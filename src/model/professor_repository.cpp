#include <QSqlRecord>
#include <QSqlQuery>

#include <model/professor_repository.h>
#include <model/professor.h>

ProfessorRepository::ProfessorRepository(ProfessorRepository *repository, QMap<QString, Repository*> *parent) : Repository(repository, parent)
{

}

ProfessorRepository::ProfessorRepository(const QString &repositoryName, QSqlDatabase *db, QMap<QString, Repository*> *parent) : Repository(repositoryName, db, parent)
{

}

ProfessorRepository::ProfessorRepository(const ProfessorRepository &repository) : Repository(repository)
{

}

bool ProfessorRepository::load()
{
    QSqlQuery query(*_db);

    query.prepare(QString("SELECT * FROM ") + _repositoryName);
    int idField(query.record().indexOf(QString("id")));
    int serialField(query.record().indexOf(QString("serial")));
    int passwdField(query.record().indexOf(QString("password")));
    int surnameField(query.record().indexOf(QString("surname")));
    int nameField(query.record().indexOf(QString("name")));

    while (query.next())
    {
        Professor *prof = new Professor(false);

        prof->_id = query.value(idField).toULongLong();
        prof->setSerial(query.value(serialField).toString());
        prof->setPassword(query.value(passwdField).toUInt());
        prof->setSurname(query.value(surnameField).toString());
        prof->setName(query.value(nameField).toString());

        _entities.append(prof);
    }

    return true;
}

const QList<Entity*> &ProfessorRepository::findAll() const
{
    return _entities;
}

const QList<Entity*> &ProfessorRepository::findBy(QMap<QString, QVariant> &criteria) const
{
    QList<Entity*> *result = new QList<Entity*>();

    for (QMap<QString, QVariant>::const_iterator c = criteria.begin() ; c != criteria.end() ; c++)
    {
        for (QList<Entity*>::const_iterator i = _entities.begin() ; i != _entities.end() ; i++)
        {
            Professor *prof = (Professor*) *i;

            if (c.key() == QString("id") || c.key() == QString("ID"))
            {
                if (prof->id() == (*c).toULongLong())
                    result->append(prof);
            }
            else if (c.key() == QString("serial") || c.key() == QString("SERIAL"))
            {
                if (prof->serial() == (*c).toString())
                    result->append(prof);
            }
            else if (c.key() == QString("passwd") || c.key() == QString("PASSWD"))
            {
                if (prof->passwd() == (*c).toUInt())
                    result->append(prof);
            }
            else if (c.key() == QString("surname") || c.key() == QString("SURNAME"))
            {
                if (prof->surname() == (*c).toString())
                    result->append(prof);
            }
            else if (c.key() == QString("name") || c.key() == QString("NAME"))
            {
                if (prof->name() == (*c).toString())
                    result->append(prof);
            }
        }
    }

    return *result;
}

bool ProfessorRepository::persist()
{
    bool result(true);

    for (QList<Entity*>::const_iterator i = _entities.begin() ; i != _entities.end() ; i++)
    {
        Professor *prof = (Professor*) *i;
        QSqlQuery query(*_db);

        if (prof->_modified)
        {
            query.prepare(QString("UPDATE ") + _repositoryName + QString(" SET serial = :serial, passwd = :passwd, surname = :surname, name = :name WHERE id :id"));
            query.bindValue(QString(":serial"), QVariant(prof->id()));
            query.bindValue(QString(":passwd"), QVariant(prof->passwd()));
            query.bindValue(QString(":surname"), QVariant(prof->surname()));
            query.bindValue(QString(":name"), QVariant(prof->name()));

            prof->_modified = false;
        }
        else if (prof->_created)
        {
            query.prepare(QString("INSERT INTO ") + _repositoryName + QString("(serial, passwd, surname, name) VALUES (:serial, :passwd, :surname, :name)"));
            query.bindValue(QString(":serial"), QVariant(prof->serial()));
            query.bindValue(QString(":passwd"), QVariant(prof->passwd()));
            query.bindValue(QString(":surname"), QVariant(prof->surname()));
            query.bindValue(QString(":name"), QVariant(prof->name()));

            prof->_created = false;
        }
        else if (prof->_deleted)
        {
            query.prepare(QString("DELETE FROM ") + _repositoryName + QString(" WHERE id = :id"));
            query.bindValue(QString(":id"), QVariant(prof->id()));

            _entities.removeOne(*i);
            delete prof;
        }

        result = result && query.exec();
    }

    return result;
}
