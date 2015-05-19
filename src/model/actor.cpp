#include <ctime>

#include <QHash>

#include <model/actor.h>

Actor::Actor(QObject *parent) :
    Entity(parent),
    _serial(),
    _passwd(0),
    _surname(),
    _name()
{
    emit entityCreated();
}

Actor::Actor(const QString &serial, const QString &passwd, const QString &surname, const QString &name, QObject *parent) :
    Entity(parent),
    _serial(serial),
    _surname(surname),
    _name(name)
{
    _passwd = qHash(passwd);

    emit entityCreated();
}

Actor::Actor(const QString &serial, const uint &passwd, const QString &surname, const QString &name, QObject *parent) :
    Entity(parent),
    _serial(serial),
    _passwd(passwd),
    _surname(surname),
    _name(name)
{
    emit entityCreated();
}

Actor::Actor(const std::string &serial, const std::string &passwd, const std::string &surname, const std::string &name, QObject *parent) :
    Entity(parent),
    _serial(serial.c_str()),
    _surname(surname.c_str()),
    _name(name.c_str())
{
    _passwd = qHash(QString(passwd.c_str()));

    emit entityCreated();
}

Actor::Actor(const std::string &serial, const uint &passwd, const std::string &surname, const std::string &name, QObject *parent) :
    Entity(parent),
    _serial(serial.c_str()),
    _passwd(passwd),
    _surname(surname.c_str()),
    _name(name.c_str())
{
    emit entityCreated();
}

Actor::Actor(const char *serial, const char *passwd, const char *surname, const char *name, QObject *parent) :
    Entity(parent),
    _serial(serial),
    _surname(surname),
    _name(name)
{
    _passwd = qHash(QString(passwd));

    emit entityCreated();
}

Actor::Actor(const char *serial, const uint &passwd, const char *surname, const char *name, QObject *parent) :
    Entity(parent),
    _serial(serial),
    _passwd(passwd),
    _surname(surname),
    _name(name)
{
    emit entityCreated();
}

Actor::Actor(const Actor &actor) :
    Entity(actor.parent()),
    _serial(actor._serial),
    _passwd(actor._passwd),
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

uint Actor::passwd() const
{
    return _passwd;
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

    emit entityModified();
}

void Actor::setSerial(const std::string &serial)
{
    _serial = serial.c_str();

    emit entityModified();
}


void Actor::setSerial(const char *serial)
{
    _serial = serial;

    emit entityModified();
}

void Actor::setPassword(const QString &passwd)
{
    _passwd = qHash(passwd);

    emit entityModified();
}

void Actor::setPassword(const std::string &passwd)
{
    _passwd = qHash(QString(passwd.c_str()));

    emit entityModified();
}

void Actor::setPassword(const char *passwd)
{
    _passwd = qHash(QString(passwd));

    emit entityModified();
}

void Actor::setPassword(const uint &passwd)
{
    _passwd = passwd;

    emit entityModified();
}

void Actor::setSurname(const QString &surname)
{
    _surname = surname;

    emit entityModified();
}

void Actor::setSurname(const std::string &surname)
{
    _surname = surname.c_str();

    emit entityModified();
}

void Actor::setSurname(const char *surname)
{
    _surname = surname;

    emit entityModified();
}

void Actor::setName(const QString &name)
{
    _name = name;

    emit entityModified();
}

void Actor::setName(const std::string &name)
{
    _name = name.c_str();

    emit entityModified();
}

void Actor::setName(const char *name)
{
    _name = name;

    emit entityModified();
}
