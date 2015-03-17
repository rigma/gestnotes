#include <model/administrator.h>

Administrator::Administrator(const QString &repositoryName, QObject *parent) :
    Actor(repositoryName, parent),
    _email()
{

}

Administrator::Administrator(const std::string &repositoryName, QObject *parent) :
    Actor(repositoryName, parent),
    _email()
{

}

Administrator::Administrator(const char *repositoryName, QObject *parent) :
    Actor(repositoryName, parent),
    _email()
{

}

Administrator::Administrator(const QString &repositoryName, const QString &serial, const QString &surname, const QString &name, const QString &email, QObject *parent) :
    Actor(repositoryName, serial, surname, name, parent),
    _email(email)
{

}

Administrator::Administrator(const std::string &repositoryName, const std::string &serial, const std::string &surname, const std::string &name, const std::string &email, QObject *parent) :
    Actor(repositoryName, serial, surname, name, parent),
    _email(email.c_str())
{

}

Administrator::Administrator(const char *repositoryName, const char *serial, const char *surname, const char *name, const char *email, QObject *parent) :
    Actor(repositoryName, serial, surname, name, parent),
    _email(email)
{

}

Administrator::Administrator(const Administrator &administrator) :
    Actor(administrator.repositoryName(), administrator._serial, administrator._surname, administrator._name, administrator.parent()),
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

    emit entityModified(_id, repositoryName());
}

void Administrator::setEmail(const std::string &email)
{
    _email = email.c_str();

    emit entityModified(_id, repositoryName());
}

void Administrator::setEmail(const char *email)
{
    _email = email;

    emit entityModified(_id, repositoryName());
}
