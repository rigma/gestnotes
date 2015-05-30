#ifndef ENTRY_H
#define ENTRY_H

#include <QString>
#include <QObject>
#include <string>

class Repository;
class AdministratorRepository;
class ProfessorRepostirory;
class StudentRepository;
class Coordinates;
class PhoneRepository;
class ContactRepository;

class Entity : public QObject
{
    Q_OBJECT

public:
    Entity(bool created = true, QObject *parent = nullptr);
    Entity(const Entity &entity);
    ~Entity();

public:
    bool operator==(Entity *e) const;

public:
    virtual qulonglong id() const;

public:
    void del();

private slots:
    void created();
    void modified();
    void deleted();

protected:
    qulonglong _id;
    bool _modified;
    bool _created;
    bool _deleted;

signals:
    void entityCreated();
    void entityModified();
    void entityDeleted();

    friend class Repository;
    friend class AdministratorRepository;
    friend class ProfessorRepository;
    friend class StudentRepository;
    friend class CoordinatesRepository;
    friend class PhoneRepository;
    friend class ContactRepository;
};

#endif // ENTRY_H

