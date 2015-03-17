#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "actor.h"

class Administrator : public Actor
{
    Q_OBJECT

public:
    Administrator(const QString &repositoryName, QObject *parent = nullptr);
    Administrator(const std::string &repositoryName, QObject *parent = nullptr);
    Administrator(const char *repositoryName, QObject *parent = nullptr);
    Administrator(const QString &repositoryName, const QString &serial, const QString &surname, const QString &name, const QString &email, QObject *parent = nullptr);
    Administrator(const std::string &repositoryName, const std::string &serial, const std::string &surname, const std::string &name, const std::string &email, QObject *parent = nullptr);
    Administrator(const char *repositoryName, const char *serial, const char *surname, const char *name, const char *email, QObject *parent = nullptr);
    Administrator(const Administrator &Administrator);
    ~Administrator();

public:
    QString email() const;

public:
    void setEmail(const QString &email);
    void setEmail(const std::string &email);
    void setEmail(const char *email);

private:
    QString _email;
};

#endif // ADMINISTRATOR_H

