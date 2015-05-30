#include <model/professor.h>

Professor::Professor(bool created, QObject *parent) : Actor(created, parent)
{

}

Professor::Professor(const QString &serial, const QString &passwd, const QString &name, const QString &surname, bool created, QObject *parent) :
    Actor(serial, passwd, name, surname, created, parent)
{

}

Professor::Professor(const QString &serial, const uint &passwd, const QString &name, const QString &surname, bool created, QObject *parent) :
    Actor(serial, passwd, name, surname, created, parent)
{

}

Professor::Professor(const char *serial, const char *passwd, const char *name, const char *surname, bool created, QObject *parent) :
    Actor(serial, passwd, name, surname, created, parent)
{

}

Professor::Professor(const char *serial, const uint &passwd, const char *name, const char *surname, bool created, QObject *parent) :
    Actor(serial, passwd, name, surname, created, parent)
{

}

Professor::~Professor()
{

}
