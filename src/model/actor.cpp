#include <model/actor.h>

Actor::Actor(const QString &repositoryName, QObject *parent) :
    Entity(repositoryName, parent),
    _serial(),
    _surname(),
    _name()
{

}

Actor::Actor(const std::string &repositoryName, QObject *parent) :
    Entity(repositoryName, parent),
    _serial(),
    _surname(),
    _name()
{

}

Actor::Actor(const char *repositoryName, QObject *parent) :
    Entity(repositoryName, parent),
    _serial(),
    _surname(),
    _name()
{

}

Actor::Actor(const QString &repositoryName, const QString &serial, const QString &surname, const QString &name, QObject *parent) :
    Entity(repositoryName, parent),
    _serial(serial),
    _surname(surname),
    _name(name)
{

}

Actor::Actor(const std::string &repositoryName, const std::string &serial, const std::string &surname, const std::string &name, QObject *parent) :
    Entity(repositoryName, parent),
    _serial(serial.c_str()),
    _surname(surname.c_str()),
    _name(name.c_str())
{

}

Actor::Actor(const char *repositoryName, const char *serial, const char *surname, const char *name, QObject *parent) :
    Entity(repositoryName, parent),
    _serial(serial),
    _surname(surname),
    _name(name)
{

}

Actor::Actor(const Actor &actor) :
    Entity(actor.repositoryName(), actor.parent()),
    _serial(actor._serial),
    _surname(actor._surname),
    _name(actor._name)
{

}

Actor::~Actor()
{

}

QString Actor::serial() const
{
    return _serial;
}

QString Actor::surname() const
{
    return _surname;
}

QString Actor::name() const
{
    return _name;
}

void Actor::setSerial(const QString &serial)
{
    _serial = serial;

    emit entityModified(_id, repositoryName());
}

void Actor::setSerial(const std::string &serial)
{
    _serial = serial.c_str();

    emit entityModified(_id, repositoryName());
}

void Actor::setSerial(const char *serial)
{
    _serial = serial;

    emit entityModified(_id, repositoryName());
}

void Actor::setSurname(const QString &surname)
{
    _surname = surname;

    emit entityModified(_id, repositoryName());
}

void Actor::setSurname(const std::string &surname)
{
    _surname = surname.c_str();

    emit entityModified(_id, repositoryName());
}

void Actor::setSurname(const char *surname)
{
    _surname = surname;

    emit entityModified(_id, repositoryName());
}

void Actor::setName(const QString &name)
{
    _name = name;

    emit entityModified(_id, repositoryName());
}

void Actor::setName(const std::string &name)
{
    _name = name.c_str();

    emit entityModified(_id, repositoryName());
}

void Actor::setName(const char *name)
{
    _name = name;

    emit entityModified(_id, repositoryName());
}
