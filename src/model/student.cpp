#include <model/student.h>

Student::Student(bool created, QObject *parent) :
    Actor(created, parent),
    _birth(),
    _registering()
{

}

Student::Student(const QString &serial, const QString &passwd, const QString &surname, const QString &name, const QDate &birth, const QDate &registering, bool created, QObject *parent) :
    Actor(serial, passwd, surname, name, created, parent),
    _birth(birth),
    _registering(registering)
{

}

Student::Student(const QString &serial, const uint &passwd, const QString &surname, const QString &name, const QDate &birth, const QDate &registering, bool created, QObject *parent) :
    Actor(serial, passwd, surname, name, created, parent),
    _birth(birth),
    _registering(registering)
{

}

Student::Student(const char *serial, const char *passwd, const char *surname, const char *name, const QDate &birth, const QDate &registering, bool created, QObject *parent) :
    Actor(serial, passwd, surname, name, created, parent),
    _birth(birth),
    _registering(registering)
{

}

Student::Student(const char *serial, const uint &passwd, const char *surname, const char *name, const QDate &birth, const QDate &registering, bool created, QObject *parent) :
    Actor(serial, passwd, surname, name, created, parent),
    _birth(birth),
    _registering(registering)
{

}

Student::Student(const Student &student) :
    Actor(student._serial, student._passwd, student._surname, student._name, false, student.parent()),
    _birth(student._birth),
    _registering(student._registering)
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
