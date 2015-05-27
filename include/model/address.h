#ifndef ADDRESS_H
#define ADDRESS_H

#include "entity.h"

class Address : public Entity
{
    Q_OBJECT

public:
    enum Type
    {
        ALLEE = 0,
        CHEMIN = 1,
        IMPASSE = 2,
        RUE = 3,
        PLACE = 4,
        QUAI = 5,
        CITE = 6,
        MONTEE = 7,
        PASSAGE = 8,
        BOULEVARD = 9,
        AVENUE = 10
    };

public:
    Address(QObject *parent = nullptr);
    Address(const unsigned short &number, const Type &type, const QString &name, const QString &zipCode, const QString &city, const QString &country = QString("FRANCE"), QObject *parent = nullptr);
    ~Address();

public:
    Address &operator=(const Address &address);

public:
    unsigned short number() const;
    Type type() const;
    const QString &name() const;
    const QString &zipCode() const;
    const QString &city() const;
    const QString &country() const;

public:
    void setNumber(const unsigned short &number);
    void setType(const Type &type);
    void setName(const QString &name);
    void setZipCode(const QString &zipCode);
    void setCity(const QString &city);
    void setCountry(const QString &country);

public:
    QString render() const;

private:
    unsigned short _number;
    Type _type;
    QString _name;
    QString _zipCode;
    QString _city;
    QString _country;
};

#endif // ADDRESS_H

