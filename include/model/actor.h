#ifndef ACTOR_H
#define ACTOR_H

#include <QObject>

#include <string>

#include "entity.h"

class Actor : public Entity
{
    Q_OBJECT

public:
    Actor(bool created = true, QObject *parent = nullptr);
    Actor(const QString &serial, const QString &passwd, const QString &surname, const QString &name, bool created = true, QObject *parent = nullptr);
    Actor(const QString &serial, const uint &passwd, const QString &surname, const QString &name, bool created = true, QObject *parent = nullptr);
    Actor(const std::string &serial, const std::string &passwd, const std::string &surname, const std::string &name, bool created = true, QObject *parent = nullptr);
    Actor(const std::string &serial, const uint &passwd, const std::string &surname, const std::string &name, bool created = true, QObject *parent = nullptr);
    Actor(const char *serial, const char *passwd, const char *surname, const char *name, bool created = true, QObject *parent = nullptr);
    Actor(const char *serial, const uint &passwd, const char *surname, const char *name, bool created = true, QObject *parent = nullptr);
    Actor(const Actor &actor);
    virtual ~Actor();

public:
    QString serial() const;
    uint passwd() const;
    QString surname() const;
    QString name() const;

public:
    void setSerial(const QString &serial);
    void setSerial(const std::string &serial);
    void setSerial(const char *serial);
    void setPassword(const QString &passwd);
    void setPassword(const std::string &passwd);
    void setPassword(const char *passwd);
    void setPassword(const uint &passwd);
    void setSurname(const QString &surname);
    void setSurname(const std::string &surname);
    void setSurname(const char *surname);
    void setName(const QString &name);
    void setName(const std::string &name);
    void setName(const char *name);

protected:
    QString _serial;
    uint _passwd;
    QString _surname;
    QString _name;
};

#endif // ACTOR_H

