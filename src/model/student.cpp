#include <model/student.h>

Student::Student(QObject *parent) : Actor(parent),
    _birth(),
    _registering()
{

}

Student::Student(const QString &serial, const QString &passwd, const QString &surname, const QString &name, const QDate &birth, const QDate &registering, QObject *parent) :
    Actor(serial, passwd, surname, name, parent),
    _birth(birth),
    _registering(registering)
{

}

Student::Student(const QString &serial, const uint &passwd, const QString &surname, const QString &name, const QDate &birth, const QDate &registering, QObject *parent) :
    Actor(serial, passwd, surname, name, parent),
    _birth(birth),
    _registering(registering)
{

}

Student::Student(const char *serial, const char *passwd, const char *surname, const char *name, const QDate &birth, const QDate &registering, QObject *parent) :
    Actor(serial, passwd, surname, name, parent),
    _birth(birth),
    _registering(registering)
{

}

Student::Student(const char *serial, const uint &passwd, const char *surname, const char *name, const QDate &birth, const QDate &registering, QObject *parent) :
    Actor(serial, passwd, surname, name, parent),
    _birth(birth),
    _registering(registering)
{

}

Student::~Student()
{

}

const QDate &Student::birth() const
{
    return _birth;
}

const QDate &Student::registering() const
{
    return _registering;
}

void Student::setBirth(const QDate &birth)
{
    _birth = birth;

    emit entityModified();
}

void Student::setRegistering(const QDate &registering)
{
    _registering = registering;

    emit entityModified();
}
