#include <model/professor.h>

Professor::Professor(QObject *parent) : Actor(parent)
{

}

Professor::Professor(const QString &serial, const QString &passwd, const QString &name, const QString &surname, QObject *parent) :
    Actor(serial, passwd, name, surname, parent)
{

}

Professor::Professor(const QString &serial, const uint &passwd, const QString &name, const QString &surname, QObject *parent) :
    Actor(serial, passwd, name, surname, parent)
{

}

Professor::Professor(const char *serial, const char *passwd, const char *name, const char *surname, QObject *parent) :
    Actor(serial, passwd, name, surname, parent)
{

}

Professor::Professor(const char *serial, const uint &passwd, const char *name, const char *surname, QObject *parent) :
    Actor(serial, passwd, name, surname, parent)
{

}

Professor::~Professor()
{

}
