#ifndef CONTACT_H
#define CONTACT_H

#include "entity.h"
#include "coordinates.h"

class Contact : public Entity
{
    Q_OBJECT

public:
    Contact(QObject *parent = nullptr);
    Contact(const QString &lastName, const QString &firstName, const Coordinates &coordinates, QObject *parent = nullptr);
    ~Contact();

public:
    const QString &lastName() const;
    const QString &firstName() const;
    const Coordinates &coordinates() const;

public:
    void setLastName(const QString &lastName);
    void setFirstName(const QString &firstName);
    void setCoordinates(const Coordinates &coordinates);

private:
    QString _lastName;
    QString _firstName;
    Coordinates _coordinates;
};

#endif // CONTACT_H

