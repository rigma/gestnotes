#include <QSqlQuery>

#include <model/repository.h>

Repository::Repository(Repository *repository, QMap<QString, Repository*> *parent) : _parent(parent),
    _entities(),
    _repositoryName()
{
    if (repository != nullptr)
        _repositoryName = repository->_repositoryName;
}

Repository::Repository(const QString &repositoryName, QSqlDatabase *db, QMap<QString, Repository*> *parent) : _parent(parent),
    _db(db),
    _entities(),
    _repositoryName(repositoryName)
{

}

Repository::Repository(const Repository &repository) : _parent(repository._parent),
    _db(repository._db),
    _entities(repository._entities),
    _repositoryName(repository._repositoryName)
{

}

Repository::~Repository()
{

}

const QList<Entity*> &Repository::entities() const
{
    return _entities;
}

const QString &Repository::repositoryName() const
{
    return _repositoryName;
}

void Repository::setRepositoryName(const QString &repositoryName)
{
    _repositoryName = repositoryName;
}

void Repository::save(Entity *e)
{
    for (QList<Entity*>::const_iterator i = _entities.begin() ; i != _entities.end() ; i++)
    {
        if (e == *i)
        {
            e->_modified = true;

            return;
        }
    }

    _entities.append(e);
}

void Repository::del(Entity *e)
{
    e->_deleted = true;

    _entities.removeOne(e);
}
