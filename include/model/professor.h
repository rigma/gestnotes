#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "actor.h"

class Professor : public Actor
{
    Q_OBJECT

public:
    Professor(bool created = true, QObject *parent = nullptr);
    Professor(const QString &serial, const QString &passwd, const QString &name, const QString &surname, bool created = true, QObject *parent = nullptr);
    Professor(const QString &serial, const uint &passwd, const QString &name, const QString &surname, bool created = true, QObject *parent = nullptr);
    Professor(const char *serial, const char *passwd, const char *name, const char *surname, bool created = true, QObject *parent = nullptr);
    Professor(const char *serial, const uint &passwd, const char *name, const char *surname, bool created = true, QObject *parent = nullptr);
    ~Professor();
};

#endif // PROFESSOR_H

