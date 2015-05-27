#include <model/entity.h>

Entity::Entity(QObject *parent) : QObject(parent),
    _id(0),
    _modified(false),
    _created(false),
    _deleted(false)
{
    connect(this, SIGNAL(entityCreated()), this, SLOT(created()));
    connect(this, SIGNAL(entityModified()), this, SLOT(modified()));
    connect(this, SIGNAL(entityDeleted()), this, SLOT(deleted()));

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

    emit entityCreated();
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
    _created = true;
}

void Entity::modified()
{
    _modified = true;
}

void Entity::deleted()
{
    _deleted = true;
}
