#include <model/administrator.h>

Administrator::Administrator(bool created, QObject *parent) : Actor(created, parent),
    _email()
{

}

Administrator::Administrator(const QString &serial, const QString &passwd, const QString &surname, const QString &name, const QString &email, bool created, QObject *parent) :
    Actor(serial, passwd, surname, name, created, parent),
    _email(email)
{

}

Administrator::Administrator(const std::string &serial, const std::string &passwd, const std::string &surname, const std::string &name, const std::string &email, bool created, QObject *parent) :
    Actor(serial, passwd, surname, name, created, parent),
    _email(email.c_str())
{

}

Administrator::Administrator(const char *serial, const char *passwd, const char *surname, const char *name, const char *email, bool created, QObject *parent) :
    Actor(serial, passwd, surname, name, created, parent),
    _email(email)
{

}

Administrator::Administrator(const Administrator &administrator) :
    Actor(administrator._serial, administrator._passwd, administrator._surname, administrator._name, false, administrator.parent()),
    _email(administrator._email)
{

}

Administrator::~Administrator()
{

}

QString Administrator::email() const
{
    return _email;
}

void Administrator::setEmail(const QString &email)
{
    _email = email;

    emit entityModified();
}

void Administrator::setEmail(const std::string &email)
{
    _email = email.c_str();

    emit entityModified();
}

void Administrator::setEmail(const char *email)
{
    _email = email;

    emit entityModified();
}
