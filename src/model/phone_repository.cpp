#include <QSqlRecord>
#include <QSqlQuery>

#include <model/phone_repository.h>
#include <model/phone.h>

PhoneRepository::PhoneRepository(PhoneRepository *repository) : Repository(repository)
{

}

PhoneRepository::PhoneRepository(const QString &repositoryName) : Repository(repositoryName)
{

}

PhoneRepository::PhoneRepository(const PhoneRepository &repository) : Repository(repository)
{

}

bool PhoneRepository::load()
{
    QSqlQuery query(QString("SELECT * FROM ") + _repositoryName);
    int idField(query.record().indexOf(QString("id")));
    int typeField(query.record().indexOf(QString("type")));
    int countryCodeField(query.record().indexOf(QString("countryCode")));
    int numberField(query.record().indexOf(QString("number")));

    while (query.next())
    {
        Phone *phone = new Phone(false);

        phone->_id = query.value(idField).toULongLong();
        phone->setType((Phone::Type) query.value(typeField).toInt());
        phone->setCountryCode(query.value(countryCodeField).toString());
        phone->setNumber(query.value(numberField).toString());

        _entities.append(phone);
    }

    return true;
}

const QList<Entity*> &PhoneRepository::findAll() const
{
    return _entities;
}

const QList<Entity*> &PhoneRepository::findBy(QMap<QString, QVariant> &criteria) const
{
    QList<Entity*> *result = new QList<Entity*>();

    for (QMap<QString, QVariant>::const_iterator c = criteria.begin() ; c != criteria.end() ; c++)
    {
        for (QList<Entity*>::const_iterator i = _entities.begin() ; i != _entities.end() ; i++)
        {
            Phone *phone = (Phone*) *i;

            if (c.key() == QString("id") || c.key() == QString("ID"))
            {
                if (phone->id() == (*c).toULongLong())
                    result->append(phone);
            }
            else if (c.key() == QString("type") || c.key() == QString("TYPE"))
            {
                if (phone->type() == (Phone::Type) (*c).toInt())
                    result->append(phone);
            }
            else if (c.key() == QString("number") || c.key() == QString("NUMBER"))
            {
                if (phone->number() == (*c).toString())
                    result->append(phone);
            }
        }
    }

    return *result;
}

bool PhoneRepository::persist()
{
    bool result(true);

    for (QList<Entity*>::const_iterator i = _entities.begin() ; i != _entities.end() ; i++)
    {
        Phone *phone = (Phone*) *i;
        QSqlQuery query;

        if (phone->_modified)
        {
            query.prepare(QString("UPDATE ") + _repositoryName + QString(" SET type = :type, countryCode = :countryCode, number = :number WHERE id :id"));
            query.bindValue(QString(":type"), QVariant(phone->type()));
            query.bindValue(QString(":countryCode"), QVariant(phone->countryCode()));
            query.bindValue(QString(":number"), QVariant(phone->number()));

            phone->_modified = false;
        }
        else if (phone->_created)
        {
            query.prepare(QString("INSERT INTO ") + _repositoryName + QString("(type, countryCode, number) VALUES (:type, :countryCode, :number)"));
            query.bindValue(QString(":type"), QVariant(phone->type()));
            query.bindValue(QString(":countryCode"), QVariant(phone->countryCode()));
            query.bindValue(QString(":number"), QVariant(phone->number()));
            phone->_created = false;
        }
        else if (phone->_deleted)
        {
            query.prepare(QString("DELETE FROM ") + _repositoryName + QString(" WHERE id = :id"));
            query.bindValue(QString(":id"), QVariant(phone->id()));

            _entities.removeOne(*i);
            delete phone;
        }

        result = result && query.exec();
    }

    return result;
}
