#ifndef ENTRY_H
#define ENTRY_H

#include <QString>
#include <QObject>
#include <string>

class Entity : public QObject
{
    Q_OBJECT

public:
    Entity(const QString &repositoryName, QObject *parent = nullptr);
    Entity(const std::string &repositoryName, QObject *parent = nullptr);
    Entity(const char *repositoryName, QObject *parent = nullptr);
    Entity(const Entity &entity);
    ~Entity();

public:
    virtual unsigned long id() const;
    QString repositoryName() const;

protected:
    void setId(unsigned long id);

protected:
    unsigned long _id;

signals:
    void entityModified(unsigned long id, const QString &objectName);
};

#endif // ENTRY_H

