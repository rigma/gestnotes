
#include <QSqlRecord>
#include <QSqlQuery>

#include <model/contact_repository.h>
#include <model/contact.h>

ContactRepository::ContactRepository(ContactRepository *repository) : Repository(repository)
{

}

ContactRepository::ContactRepository(const QString &repositoryName) : Repository(repositoryName)
{

}

ContactRepository::ContactRepository(const ContactRepository &repository) : Repository(repository)
{

}

ContactRepository::~ContactRepository()
{
    persist();
}

bool ContactRepository::load()
{
    QSqlQuery query(QString("SELECT * FROM ") + _repositoryName);
    int idField(query.record().indexOf("id"));
    int lastNameField(query.record().indexOf(QString("lastName")));
    int firstNameField(query.record().indexOf(QString("firstName")));

    while (query.next())
    {
        Contact *contact = new Contact(false);

        contact->_id = query.value(idField).toULongLong();
        contact->setLastName(query.value(lastNameField).toString());
        contact->setFirstName(query.value(firstNameField).toString());

        _entities.append(contact);
    }

    return true;
}

const QList<Entity*> &ContactRepository::findAll() const
{
    return _entities;
}

const QList<Entity*> &ContactRepository::findBy(QMap<QString, QVariant> &criteria) const
{
    QList<Entity*> *result = new QList<Entity*>();

    for (QMap<QString, QVariant>::const_iterator c = criteria.begin() ; c != criteria.end() ; c++)
    {
        for (QList<Entity*>::const_iterator i = _entities.begin() ; i != _entities.end() ; i++)
        {
            Contact *contact = (Contact*) *i;

            if (c.key() == QString("id") || c.key() == QString("ID"))
            {
                if (contact->id() == (*c).toULongLong())
                    result->append(contact);
            }
            else if (c.key() == QString("last") || c.key() == QString("LAST") || c.key() == QString("last name") || c.key() == QString("LAST NAME"))
            {
                if (contact->lastName() == (*c).toString())
                    result->append(contact);
            }
            else if (c.key() == QString("first") || c.key() == QString("FIRST") || c.key() == QString("first name") || c.key() == QString("FIRST NAME"))
            {
                if (contact->firstName() == (*c).toString())
                    result->append(contact);
            }
        }
    }

    return *result;
}

bool ContactRepository::persist()
{
    bool result(true);

    for (QList<Entity*>::const_iterator i = _entities.begin() ; i != _entities.end() ; i++)
    {
        Contact *contact = (Contact*) *i;
        QSqlQuery query;

        if (contact->_modified)
        {
            query.prepare(QString("UPDATE ") + _repositoryName + QString(" SET lastName = :lastName, firstName = :firstName WHERE id :id"));
            query.bindValue(QString(":lastName"), QVariant(contact->lastName()));
            query.bindValue(QString(":firstName"), QVariant(contact->firstName()));

            contact->_modified = false;
        }
        else if (contact->_created)
        {
            query.prepare(QString("INSERT INTO ") + _repositoryName + QString("(lastName, firstName) VALUES (:lastName, :firstName)"));
            query.bindValue(QString(":lastName"), QVariant(contact->lastName()));
            query.bindValue(QString(":firstName"), QVariant(contact->firstName()));

            contact->_created = false;
        }
        else if (contact->_deleted)
        {
            query.prepare(QString("DELETE FROM ") + _repositoryName + QString(" WHERE id = :id"));
            query.bindValue(QString(":id"), QVariant(contact->id()));

            _entities.removeOne(*i);
            delete contact;
        }

        result = result && query.exec();
    }

    return result;
}

