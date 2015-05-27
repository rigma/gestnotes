#include <include/model/coordinates.h>

Coordinates::Coordinates(QObject *parent) : Entity(parent),
    _address(),
    _email(),
    _phones()
{

}

Coordinates::Coordinates(const Address &address, const QString &email, const QList<Phone> &phones, QObject *parent) : Entity(parent),
    _address(address),
    _email(email),
    _phones(phones)
{

}

Coordinates::~Coordinates()
{

}

Coordinates &Coordinates::operator=(const Coordinates &coordinates)
{
    _address = coordinates._address;
    _email = coordinates._email;
    _phones = coordinates._phones;

    return *this;
}

const Address &Coordinates::address() const
{
    return _address;
}

const QString &Coordinates::email() const
{
    return _email;
}

const QList<Phone> &Coordinates::phones() const
{
    return _phones;
}

void Coordinates::setAddress(const Address &address)
{
    _address = address;

    emit entityModified();
}

void Coordinates::setEmail(const QString &email)
{
    _email = email;

    emit entityModified();
}

void Coordinates::setPhones(const QList<Phone> &phones)
{
    _phones = phones;

    emit entityModified();
}

void Coordinates::addPhone(const Phone &phone)
{
    _phones.append(phone);

    emit entityModified();
}

void Coordinates::removePhone(const unsigned long long &id)
{
    for (auto &phone : _phones)
    {
        if (phone.id() == id)
        {
            _phones.removeOne(phone);

            break;
        }
    }
}
