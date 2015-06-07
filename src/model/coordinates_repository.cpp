#include <QSqlRecord>
#include <QSqlQuery>

#include <model/coordinates_repository.h>
#include <model/coordinates.h>

CoordinatesRepository::CoordinatesRepository(CoordinatesRepository *repository, QMap<QString, Repository*> *parent) : Repository(repository, parent)
{

}

CoordinatesRepository::CoordinatesRepository(const QString &repositoryName, QSqlDatabase *db, QMap<QString, Repository*> *parent) : Repository(repositoryName, db, parent)
{

}

CoordinatesRepository::CoordinatesRepository(const CoordinatesRepository &repository) : Repository(repository)
{

}

bool CoordinatesRepository::load()
{
    QSqlQuery query(*_db);

    query.prepare(QString("SELECT * FROM ") + _repositoryName);
    int idField(query.record().indexOf(QString("id")));
    int numberField(query.record().indexOf(QString("number")));
    int typeField(query.record().indexOf(QString("type")));
    int nameField(query.record().indexOf(QString("name")));
    int zipCodeField(query.record().indexOf(QString("zipCode")));
    int cityField(query.record().indexOf(QString("city")));
    int countryField(query.record().indexOf(QString("country")));
    int emailField(query.record().indexOf(QString("email")));

    while (query.next())
    {
        Coordinates *coordinates = new Coordinates(false);
        Address *address = new Address;

        coordinates->_id = query.value(idField).toULongLong();

        address->setNumber((unsigned short) query.value(numberField).toUInt());
        address->setType((Address::Type) query.value(typeField).toInt());
        address->setName(query.value(nameField).toString());
        address->setZipCode(query.value(zipCodeField).toString());
        address->setCity(query.value(cityField).toString());
        address->setCountry(query.value(countryField).toString());
        coordinates->setAddress(*address);

        coordinates->setEmail(query.value(emailField).toString());

        _entities.append(coordinates);
    }

    return true;
}

const QList<Entity*> &CoordinatesRepository::findAll() const
{
    return _entities;
}

const QList<Entity*> &CoordinatesRepository::findBy(QMap<QString, QVariant> &criteria) const
{
    QList<Entity*> *result = new QList<Entity*>();

    for (QMap<QString, QVariant>::const_iterator c = criteria.begin() ; c != criteria.end() ; c++)
    {
        for (QList<Entity*>::const_iterator i = _entities.begin() ; i != _entities.end() ; i++)
        {
            Coordinates *coordinates = (Coordinates*) *i;

            if (c.key() == QString("id") || c.key() == QString("ID"))
            {
                if (coordinates->id() == (*c).toULongLong())
                    result->append(coordinates);
            }
            else if (c.key() == QString("email") || c.key() == QString("EMAIL"))
            {
                if (coordinates->email() == (*c).toString())
                    result->append(coordinates);
            }
        }
    }

    return *result;
}

bool CoordinatesRepository::persist()
{
    bool result(true);

    for (QList<Entity*>::const_iterator i = _entities.begin() ; i != _entities.end() ; i++)
    {
        Coordinates *coordinates = (Coordinates*) *i;
        QSqlQuery query(*_db);

        if (coordinates->_modified)
        {
            query.prepare(QString("UPDATE ") + _repositoryName + QString(" SET number = :number, type = :type, name = :name, zipCode = :zipCode, city = :city, country = :country, email = :email WHERE id :id"));
            query.bindValue(QString(":id"), QVariant(coordinates->id()));
            query.bindValue(QString(":number"), QVariant(coordinates->address().number()));
            query.bindValue(QString(":type"), QVariant(coordinates->address().type()));
            query.bindValue(QString(":name"), QVariant(coordinates->address().name()));
            query.bindValue(QString(":zipCode"), QVariant(coordinates->address().zipCode()));
            query.bindValue(QString(":city"), QVariant(coordinates->address().city()));
            query.bindValue(QString(":country"), QVariant(coordinates->address().country()));
            query.bindValue(QString(":email"), QVariant(coordinates->email()));

            coordinates->_modified = false;
        }
        else if (coordinates->_created)
        {
            query.prepare(QString("INSERT INTO ") + _repositoryName + QString("(number, type, name, zipCode, city, country, email) VALUES (:number, :type, :name, :zipCode, :city, :country, :email)"));
            query.bindValue(QString(":number"), QVariant(coordinates->address().number()));
            query.bindValue(QString(":type"), QVariant(coordinates->address().type()));
            query.bindValue(QString(":name"), QVariant(coordinates->address().name()));
            query.bindValue(QString(":zipCode"), QVariant(coordinates->address().zipCode()));
            query.bindValue(QString(":city"), QVariant(coordinates->address().city()));
            query.bindValue(QString(":country"), QVariant(coordinates->address().country()));
            query.bindValue(QString(":email"), QVariant(coordinates->email()));

            coordinates->_created = false;
        }
        else if (coordinates->_deleted)
        {
            query.prepare(QString("DELETE FROM ") + _repositoryName + QString(" WHERE id = :id"));
            query.bindValue(QString(":id"), QVariant(coordinates->id()));

            _entities.removeOne(*i);
            delete coordinates;
        }

        result = result && query.exec();
    }

    return result;
}

