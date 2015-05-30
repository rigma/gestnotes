#include <include/model/contact.h>

Contact::Contact(bool created, QObject *parent) : Entity(created, parent),
    _lastName(),
    _firstName()
{

}

Contact::Contact(const QString &lastName, const QString &firstName, const Coordinates &coordinates, bool created, QObject *parent) : Entity(created, parent),
    _lastName(lastName),
    _firstName(firstName),
    _coordinates(coordinates)
{

}

Contact::~Contact()
{

}

const QString &Contact::lastName() const
{
    return _lastName;
}

const QString &Contact::firstName() const
{
    return _firstName;
}

const Coordinates &Contact::coordinates() const
{
    return _coordinates;
}

void Contact::setLastName(const QString &lastName)
{
    _lastName = lastName;

    emit entityModified();
}

void Contact::setFirstName(const QString &firstName)
{
    _firstName = firstName;

    emit entityModified();
}

void Contact::setCoordinates(const Coordinates &coordinates)
{
    _coordinates = coordinates;

    emit entityModified();
}
