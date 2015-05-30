#ifndef COORDINATES_H
#define COORDINATES_H

#include <QList>
#include <QStringList>

#include "entity.h"
#include "address.h"
#include "phone.h"

class Coordinates : public Entity
{
    Q_OBJECT

public:
    Coordinates(bool created = true, QObject *parent = nullptr);
    Coordinates(const Address &address, const QString &email, const QList<Phone> &phones, bool created = true, QObject *parent = nullptr);
    ~Coordinates();

public:
    Coordinates &operator=(const Coordinates &coordinates);

public:
    const Address &address() const;
    const QString &email() const;
    const QList<Phone> &phones() const;
    const QStringList &phoneNumbers(const Phone::Type &type, bool all = false) const;
    const QString &rawAddress() const;

public:
    void setAddress(const Address &address);
    void setEmail(const QString &email);
    void setPhones(const QList<Phone> &phones);
    void addPhone(const Phone &phones);
    void removePhone(const unsigned long long &id);

private:
    Address _address;
    QString _email;
    QList<Phone> _phones;
};

#endif // COORDINATES_H
