#include <model/entity.h>

Entity::Entity(const QString &objectName, QObject *parent) : QObject(parent),
    _id(0)
{
    setObjectName(objectName);
}

Entity::Entity(const std::string &repositoryName, QObject *parent) : QObject(parent),
    _id(0)
{
    setObjectName(QString(repositoryName.c_str()));
}

Entity::Entity(const char *repositoryName, QObject *parent) : QObject(parent),
    _id(0)
{
    setObjectName(QString(repositoryName));
}

Entity::Entity(const Entity &entity) : QObject(entity.parent()),
    _id(entity._id)
{

}

Entity::~Entity()
{

}

unsigned long Entity::id() const
{
    return _id;
}

QString Entity::repositoryName() const
{
    return objectName();
}

void Entity::setId(unsigned long id)
{
    _id = id;
}
