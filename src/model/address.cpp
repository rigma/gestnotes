#include <include/model/address.h>

Address::Address() : _number(),
    _type(),
    _name(),
    _zipCode(),
    _city(),
    _country()
{

}

Address::Address(const unsigned short &number, const Type &type, const QString &name, const QString &zipCode, const QString &city, const QString &country) : _number(number),
    _type(type),
    _name(name),
    _zipCode(zipCode),
    _city(city),
    _country(country)
{

}

Address::~Address()
{

}

Address &Address::operator=(const Address &address)
{
    _number = address._number;
    _type = address._type;
    _name = address._name;
    _zipCode = address._zipCode;
    _city = address._city;
    _country = address._country;

    return *this;
}

unsigned short Address::number() const
{
    return _number;
}

Address::Type Address::type() const
{
    return _type;
}

const QString &Address::name() const
{
    return _name;
}

const QString &Address::zipCode() const
{
    return _zipCode;
}

const QString &Address::city() const
{
    return _city;
}

const QString &Address::country() const
{
    return _country;
}

void Address::setNumber(const unsigned short &number)
{
    _number = number;
}

void Address::setType(const Address::Type &type)
{
    _type = type;
}

void Address::setName(const QString &name)
{
    _name = name;
}

void Address::setZipCode(const QString &zipCode)
{
    _zipCode = zipCode;
}

void Address::setCity(const QString &city)
{
    _city = city;
}

void Address::setCountry(const QString &country)
{
    _country = country;
}

QString Address::render() const
{
    QString *str = new QString;

    switch (_type)
    {
    case ALLEE:
        *str = QString("%u, allée %s\n%s %s\n%s").arg(_number)
                .arg(_name)
                .arg(_zipCode)
                .arg(_city)
                .arg(_country);
        break;

    case CHEMIN:
        *str = QString("%u, chemin %s\n%s %s\n%s").arg(_number)
                .arg(_name)
                .arg(_zipCode)
                .arg(_city)
                .arg(_country);
        break;

    case IMPASSE:
        *str = QString("%u, impasse %s\n%s %s\n%s").arg(_number)
                .arg(_name)
                .arg(_zipCode)
                .arg(_city)
                .arg(_country);
        break;

    case RUE:
        *str = QString("%u, rue %s\n%s %s\n%s").arg(_number)
                .arg(_name)
                .arg(_zipCode)
                .arg(_city)
                .arg(_country);
        break;

    case PLACE:
        *str = QString("%u, place %s\n%s %s\n%s").arg(_number)
                .arg(_name)
                .arg(_zipCode)
                .arg(_city)
                .arg(_country);
        break;

    case QUAI:
        *str = QString("%u, quai %s\n%s %s\n%s").arg(_number)
                .arg(_name)
                .arg(_zipCode)
                .arg(_city)
                .arg(_country);
        break;

    case CITE:
        *str = QString("%u, cité %s\n%s %s\n%s").arg(_number)
                .arg(_name)
                .arg(_zipCode)
                .arg(_city)
                .arg(_country);
        break;

    case MONTEE:
        *str = QString("%u, montée %s\n%s %s\n%s").arg(_number)
                .arg(_name)
                .arg(_zipCode)
                .arg(_city)
                .arg(_country);
        break;

    case PASSAGE:
        *str = QString("%u, passage %s\n%s %s\n%s").arg(_number)
                .arg(_name)
                .arg(_zipCode)
                .arg(_city)
                .arg(_country);
        break;

    case BOULEVARD:
        *str = QString("%u, boulevard %s\n%s %s\n%s").arg(_number)
                .arg(_name)
                .arg(_zipCode)
                .arg(_city)
                .arg(_country);
        break;

    case AVENUE:
        *str = QString("%u, avenue %s\n%s %s\n%s").arg(_number)
                .arg(_name)
                .arg(_zipCode)
                .arg(_city)
                .arg(_country);
        break;

    default:
        *str = QString("%u, rue %s\n%s %s\n%s").arg(_number)
                .arg(_name)
                .arg(_zipCode)
                .arg(_city)
                .arg(_country);
        break;
    }

    return *str;
}
