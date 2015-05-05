#include <model/administrator.h>

Administrator::Administrator(QObject *parent) :
    Actor(parent),
    _email()
{

}

Administrator::Administrator(const QString &serial, const QString &passwd, const QString &surname, const QString &name, const QString &email, QObject *parent) :
    Actor(serial, passwd, surname, name, parent),
    _email(email)
{

}

Administrator::Administrator(const std::string &serial, const std::string &passwd, const std::string &surname, const std::string &name, const std::string &email, QObject *parent) :
    Actor(serial, passwd, surname, name, parent),
    _email(email.c_str())
{

}

Administrator::Administrator(const char *serial, const char *passwd, const char *surname, const char *name, const char *email, QObject *parent) :
    Actor(serial, passwd, surname, name, parent),
    _email(email)
{

}

Administrator::Administrator(const Administrator &administrator) :
    Actor(administrator._serial, administrator._passwd, administrator._surname, administrator._name, administrator.parent()),
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
}

void Administrator::setEmail(const std::string &email)
{
    _email = email.c_str();
}

void Administrator::setEmail(const char *email)
{
    _email = email;
}
