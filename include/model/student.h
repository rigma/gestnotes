#ifndef STUDENT_H
#define STUDENT_H

#include <QDate>

#include "actor.h"

class Student : public Actor
{
    Q_OBJECT

public:
    Student(QObject *parent = nullptr);
    Student(const QString &serial, const QString &passwd, const QString &surname, const QString &name, const QDate &birth, const QDate &registering, QObject *parent = nullptr);
    Student(const QString &serial, const uint &passwd, const QString &surname, const QString &name, const QDate &birth, const QDate &registering, QObject *parent = nullptr);
    Student(const char *serial, const char *passwd, const char *surname, const char *name, const QDate &birth, const QDate &registering, QObject *parent = nullptr);
    Student(const char *serial, const uint &passwd, const char *surname, const char *name, const QDate &birth, const QDate &registering, QObject *parent = nullptr);
    Student(const Student &student);
    ~Student();

public:
    const QDate &birth() const;
    const QDate &registering() const;

public:
    void setBirth(const QDate &birth);
    void setRegistering(const QDate &registering);

private:
    QDate _birth;
    QDate _registering;
};

#endif // STUDENT_H

