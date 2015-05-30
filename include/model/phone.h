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
    Phone(bool created = true, QObject *parent = nullptr);
    Phone(const Phone::Type &type, const QString &number, bool created = true, QObject *parent = nullptr);
    ~Phone();

public:
    Phone &operator=(const Phone &phone);
    bool operator==(const Phone &phone);

public:
    Phone::Type type() const;
    const QString &countryCode() const;
    const QString &number() const;
    const QString &phoneNumber() const;

public:
    void setType(const Phone::Type &type);
    void setCountryCode(const QString &countryCode);
    void setNumber(const QString &number);

private:
    Type _type;
    QString _countryCode;
    QString _number;
};

#endif // PHONE_H

