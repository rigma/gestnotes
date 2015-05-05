#ifndef ENTRY_H
#define ENTRY_H

#include <QString>
#include <QObject>
#include <string>

class Repository;
class AdministratorRepository;

class Entity : public QObject
{
    Q_OBJECT

public:
    Entity(QObject *parent = nullptr);
    Entity(const Entity &entity);
    ~Entity();

public:
    bool operator==(Entity *e) const;

public:
    virtual qulonglong id() const;

protected:
    qulonglong _id;
    bool _modified;
    bool _created;
    bool _deleted;

signals:
    void entityModified(unsigned long id, const QString &objectName);

    friend class Repository;
    friend class AdministratorRepository;
};

#endif // ENTRY_H

