#include <model/entity.h>

Entity::Entity(bool created, QObject *parent) : QObject(parent),
    _id(0),
    _modified(false),
    _created(false),
    _deleted(false)
{
    connect(this, SIGNAL(entityCreated()), this, SLOT(created()));
    connect(this, SIGNAL(entityModified()), this, SLOT(modified()));
    connect(this, SIGNAL(entityDeleted()), this, SLOT(deleted()));

    if (created)
        emit entityCreated();
}

Entity::Entity(const Entity &entity) : QObject(entity.parent()),
    _id(entity._id),
    _modified(entity._modified),
    _created(false),
    _deleted(false)
{
    connect(this, SIGNAL(entityCreated()), this, SLOT(created()));
    connect(this, SIGNAL(entityModified()), this, SLOT(modified()));
    connect(this, SIGNAL(entityDeleted()), this, SLOT(deleted()));
}

Entity::~Entity()
{

}

bool Entity::operator==(Entity *e) const
{
    return _id == e->_id;
}

qulonglong Entity::id() const
{
    return _id;
}

void Entity::del()
{
    emit entityDeleted();
}

void Entity::created()
{
    if (!_modified && !_deleted)
        _created = true;
}

void Entity::modified()
{
    if (!_created && !_deleted)
        _modified = true;
}

void Entity::deleted()
{
    _deleted = true;
}
