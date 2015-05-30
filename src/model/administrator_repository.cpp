#include <QSqlRecord>
#include <QSqlQuery>

#include <model/administrator_repository.h>
#include <model/administrator.h>

AdministratorRepository::AdministratorRepository(AdministratorRepository *repository) : Repository(repository)
{

}

AdministratorRepository::AdministratorRepository(const QString &repositoryName) : Repository(repositoryName)
{

}

AdministratorRepository::AdministratorRepository(const AdministratorRepository &repository) : Repository(repository)
{

}

AdministratorRepository::~AdministratorRepository()
{
    persist();
}

bool AdministratorRepository::load()
{
    QSqlQuery query(QString("SELECT * FROM ") + _repositoryName);
    int idField(query.record().indexOf(QString("id")));
    int serialField(query.record().indexOf(QString("serial")));
    int passwdField(query.record().indexOf(QString("passwd")));
    int surnameField(query.record().indexOf(QString("surname")));
    int nameField(query.record().indexOf(QString("name")));
    int emailField(query.record().indexOf(QString("email")));

    while (query.next())
    {
        Administrator *admin = new Administrator(false);

        admin->_id = query.value(idField).toULongLong();
        admin->setSerial(query.value(serialField).toString());
        admin->setPassword(query.value(passwdField).toUInt());
        admin->setSurname(query.value(surnameField).toString());
        admin->setName(query.value(nameField).toString());
        admin->setEmail(query.value(emailField).toString());

        _entities.append(admin);
    }

    return true;
}

const QList<Entity*> &AdministratorRepository::findAll() const
{
    return _entities;
}

const QList<Entity*> &AdministratorRepository::findBy(QMap<QString, QVariant> &criteria) const
{
    QList<Entity*> *result = new QList<Entity*>();

    for (QMap<QString, QVariant>::const_iterator c = criteria.begin() ; c != criteria.end() ; c++)
    {
        for (QList<Entity*>::const_iterator i = _entities.begin() ; i != _entities.end() ; i++)
        {
            Administrator *admin = (Administrator*) *i;

            if (c.key() == QString("id") || c.key() == QString("ID"))
            {
                if (admin->id() == (*c).toULongLong())
                    result->append(admin);
            }
            else if (c.key() == QString("serial") || c.key() == QString("SERIAL"))
            {
                if (admin->serial() == (*c).toString())
                    result->append(admin);
            }
            else if (c.key() == QString("passwd") || c.key() == QString("PASSWD"))
            {
                if (admin->passwd() == (*c).toUInt())
                    result->append(admin);
            }
            else if (c.key() == QString("surname") || c.key() == QString("SURNAME"))
            {
                if (admin->surname() == (*c).toString())
                    result->append(admin);
            }
            else if (c.key() == QString("name") || c.key() == QString("NAME"))
            {
                if (admin->name() == (*c).toString())
                    result->append(admin);
            }
            else if (c.key() == QString("email") || c.key() == QString("EMAIL"))
            {
                if (admin->email() == (*c).toString())
                    result->append(admin);
            }
        }
    }

    return *result;
}

bool AdministratorRepository::persist()
{
    bool result(true);

    for (QList<Entity*>::const_iterator i = _entities.begin() ; i != _entities.end() ; i++)
    {
        Administrator *admin = (Administrator*) *i;
        QSqlQuery query;

        if (admin->_modified)
        {
            query.prepare(QString("UPDATE ") + _repositoryName + QString(" SET serial = :serial, passwd = :passwd, surname = :surname, name = :name, email = :email WHERE id :id"));
            query.bindValue(QString(":serial"), QVariant(admin->id()));
            query.bindValue(QString(":passwd"), QVariant(admin->passwd()));
            query.bindValue(QString(":surname"), QVariant(admin->surname()));
            query.bindValue(QString(":name"), QVariant(admin->name()));
            query.bindValue(QString(":email"), QVariant(admin->email()));

            admin->_modified = false;
        }
        else if (admin->_created)
        {
            query.prepare(QString("INSERT INTO ") + _repositoryName + QString("(serial, passwd, surname, name, email) VALUES (:serial, :passwd, :surname, :name, :email)"));
            query.bindValue(QString(":serial"), QVariant(admin->serial()));
            query.bindValue(QString(":passwd"), QVariant(admin->passwd()));
            query.bindValue(QString(":surname"), QVariant(admin->surname()));
            query.bindValue(QString(":name"), QVariant(admin->name()));
            query.bindValue(QString(":email"), QVariant(admin->email()));

            admin->_created = false;
        }
        else if (admin->_deleted)
        {
            query.prepare(QString("DELETE FROM ") + _repositoryName + QString(" WHERE id = :id"));
            query.bindValue(QString(":id"), QVariant(admin->id()));

            _entities.removeOne(*i);
            delete admin;
        }

        result = result && query.exec();
    }

    return result;
}
