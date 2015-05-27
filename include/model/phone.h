#ifndef PHONE_H
#define PHONE_H

#include "entity.h"

class Phone : public Entity
{
    Q_OBJECT

public:
    enum Type
    {
        FIX = 0,
        MOBILE = 1,
        WORK = 2
    };

public:
    Phone(QObject *parent = nullptr);
    Phone(const Phone::Type &type, const QString &number, QObject *parent = nullptr);
    ~Phone();

public:
    Phone &operator=(const Phone &phone);
    bool operator==(const Phone &phone);

public:
    Phone::Type type() const;
    const QString &number() const;

public:
    void setType(const Phone::Type &type);
    void setNumber(const QString &number);

private:
    Type _type;
    QString _number;
};

#endif // PHONE_H

