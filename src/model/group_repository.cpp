#include <QSqlRecord>
#include <QSqlQuery>

#include <model/group_repository.h>
#include <model/group.h>

GroupRepository::GroupRepository(GroupRepository *repository, QMap<QString, Repository*> *parent) : Repository(repository, parent)
{

}

GroupRepository::GroupRepository(const QString &repositoryName, QSqlDatabase *db, QMap<QString, Repository*> *parent) : Repository(repositoryName, db, parent)
{

}

GroupRepository::GroupRepository(const GroupRepository &repository) : Repository(repository)
{

}

bool GroupRepository::load()
{
    QSqlQuery query(*_db);

    query.prepare(QString("SELECT * FROM ") + _repositoryName);
    int idField(query.record().indexOf(QString("id")));
    int nameField(query.record().indexOf(QString("name")));

    while (query.next())
    {
        Group *group = new Group(false);

        group->_id = query.value(idField).toULongLong();
        group->setName(query.value(nameField).toString());

        _entities.append(group);
    }

    return true;
}

const QList<Entity*> &GroupRepository::findAll() const
{
    return _entities;
}

const QList<Entity*> &GroupRepository::findBy(QMap<QString, QVariant> &criteria) const
{
    QList<Entity*> *result = new QList<Entity*>();

    for (QMap<QString, QVariant>::const_iterator c = criteria.begin() ; c != criteria.end() ; c++)
    {
        for (QList<Entity*>::const_iterator i = _entities.begin() ; i != _entities.end() ; i++)
        {
            Group *group = (Group*) *i;

            if (c.key() == QString("id") || c.key() == QString("ID"))
            {
                if (group->id() == (*c).toULongLong())
                    result->append(group);
            }
            else if (c.key() == QString("name") || c.key() == QString("NAME"))
            {
                if (group->name() == (*c).toString())
                    result->append(group);
            }
        }
    }

    return *result;
}

bool GroupRepository::persist()
{
    bool result(true);

    for (QList<Entity*>::const_iterator i = _entities.begin() ; i != _entities.end() ; i++)
    {
        Group *group = (Group*) *i;
        QSqlQuery query(*_db);

        if (group->_modified)
        {
            query.prepare(QString("UPDATE ") + _repositoryName + QString(" SET name = :name WHERE id :id"));
            query.bindValue(QString(":id"), QVariant(group->id()));
            query.bindValue(QString(":name"), QVariant(group->name()));

            group->_modified = false;
        }
        else if (group->_created)
        {
            query.prepare(QString("INSERT INTO ") + _repositoryName + QString("(number, type, name, zipCode, city, country, email) VALUES (:number, :type, :name, :zipCode, :city, :country, :email)"));
            query.bindValue(QString(":name"), QVariant(group->name()));

            group->_created = false;
        }
        else if (group->_deleted)
        {
            query.prepare(QString("DELETE FROM ") + _repositoryName + QString(" WHERE id = :id"));
            query.bindValue(QString(":id"), QVariant(group->id()));

            _entities.removeOne(*i);
            delete group;
        }

        result = result && query.exec();
    }

    return result;
}
