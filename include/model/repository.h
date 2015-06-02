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
    Repository(Repository *repository = nullptr, QMap<QString, Repository*> *parent = nullptr);
    Repository(const QString &repositoryName, QMap<QString, Repository *> *parent = nullptr);
    Repository(const Repository &repository);
    virtual ~Repository();

public:
    virtual bool load() = 0;
    virtual const QList<Entity*> &findAll() const = 0;
    virtual const QList<Entity*> &findBy(QMap<QString, QVariant> &criteria) const = 0;
    virtual bool persist() = 0;

public:
    QMap<QString, Repository*> parent();
    const QList<Entity*> &entities() const;
    const QString &repositoryName() const;

public:
    void setRepositoryName(const QString &repositoryName);
    void setParent(QMap<QString, Repository*> *parent);

public:
    void save(Entity *e);
    void del(Entity *e);

protected:
    QMap<QString, Repository*> *_parent;
    QList<Entity*> _entities;
    QString _repositoryName;
};

#endif // REPOSITORY_H

