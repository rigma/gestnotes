#ifndef ACTOR_H
#define ACTOR_H

#include <QObject>
#include <string>

#include "entity.h"

class Actor : public Entity
{
    Q_OBJECT

public:
    Actor(const QString &repositoryName, QObject *parent = nullptr);
    Actor(const std::string &repositoryName, QObject *parent = nullptr);
    Actor(const char *repositoryName, QObject *parent = nullptr);
    Actor(const QString &repositoryName, const QString &serial, const QString &surname, const QString &name, QObject *parent = nullptr);
    Actor(const std::string &repositoryName, const std::string &serial, const std::string &surname, const std::string &name, QObject *parent = nullptr);
    Actor(const char *repositoryName, const char *serial, const char *surname, const char *name, QObject *parent = nullptr);
    Actor(const Actor &actor);
    virtual ~Actor();

public:
    QString serial() const;
    QString surname() const;
    QString name() const;

public:
    void setSerial(const QString &serial);
    void setSerial(const std::string &serial);
    void setSerial(const char *serial);
    void setSurname(const QString &surname);
    void setSurname(const std::string &surname);
    void setSurname(const char *surname);
    void setName(const QString &name);
    void setName(const std::string &name);
    void setName(const char *name);

protected:
    QString _serial;
    QString _surname;
    QString _name;
};

#endif // ACTOR_H

