#include <include/model/phone.h>

Phone::Phone(QObject *parent) : Entity(parent),
    _type(),
    _number()
{

}

Phone::Phone(const Phone::Type &type, const QString &number, QObject *parent) : Entity(parent),
    _type(type),
    _number(number)
{

}

Phone::~Phone()
{

}

Phone &Phone::operator=(const Phone &phone)
{
    _type = phone._type;
    _number = phone._number;

    return *this;
}

bool Phone::operator==(const Phone &phone)
{
    return (_type == phone._type && _number == phone._number) ? true : false;
}

Phone::Type Phone::type() const
{
    return _type;
}

const QString &Phone::number() const
{
    return _number;
}

void Phone::setType(const Phone::Type &type)
{
    _type = type;

    emit entityModified();
}

void Phone::setNumber(const QString &number)
{
    _number = number;

    emit entityModified();
}
