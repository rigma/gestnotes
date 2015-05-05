#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <QList>
#include <QMap>
#include <QSqlDatabase>
#include <QString>
#include <QVariant>

#include "entity.h"

class Repository
{
public:
    Repository(Repository *repository = nullptr);
    Repository(const QString &repositoryName);
    Repository(const Repository &repository);
    ~Repository();

public:
    virtual bool load() = 0;
    virtual const QList<Entity*> &findAll() const = 0;
    virtual const QList<Entity*> &findBy(QMap<QString, QVariant> &criteria) const = 0;
    virtual bool persist() = 0;

public:
    const QList<Entity*> &entities() const;
    const QString &repositoryName() const;

public:
    void save(Entity *e);
    void del(Entity *e);
    void setRepositoryName(const QString &repositoryName);

protected:
    QList<Entity*> _entities;
    QString _repositoryName;
};

#endif // REPOSITORY_H

