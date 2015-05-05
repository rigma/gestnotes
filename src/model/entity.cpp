#include <model/entity.h>

Entity::Entity(QObject *parent) : QObject(parent),
    _id(0),
    _modified(false),
    _created(false),
    _deleted(false)
{

}

Entity::Entity(const Entity &entity) : QObject(entity.parent()),
    _id(entity._id),
    _modified(entity._modified),
    _created(false),
    _deleted(false)
{

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
