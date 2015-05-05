#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <QDataStream>

#include "actor.h"

class Administrator : public Actor
{
    Q_OBJECT

public:
    Administrator(QObject *parent = nullptr);
    Administrator(const QString &serial, const QString &passwd, const QString &surname, const QString &name, const QString &email, QObject *parent = nullptr);
    Administrator(const std::string &serial, const std::string &passwd, const std::string &surname, const std::string &name, const std::string &email, QObject *parent = nullptr);
    Administrator(const char *serial, const char *passwd, const char *surname, const char *name, const char *email, QObject *parent = nullptr);
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

