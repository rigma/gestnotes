#include <include/model/phone.h>

Phone::Phone(bool created, QObject *parent) : Entity(created, parent),
    _type(),
    _number()
{

}

Phone::Phone(const Phone::Type &type, const QString &number, bool created, QObject *parent) : Entity(created, parent),
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

const QString &Phone::countryCode() const
{
    return _countryCode;
}

const QString &Phone::number() const
{
    return _number;
}

const QString &Phone::phoneNumber() const
{
    QString *phoneNumber = new QString;

    *phoneNumber = (_countryCode == "+33") ? _countryCode + _number.section(QChar('0'), 1) : _countryCode + _number;

    return *phoneNumber;
}

void Phone::setType(const Phone::Type &type)
{
    _type = type;

    emit entityModified();
}

void Phone::setCountryCode(const QString &countryCode)
{
    _countryCode = countryCode;

    emit entityModified();
}

void Phone::setNumber(const QString &number)
{
    _number = number;

    emit entityModified();
}
