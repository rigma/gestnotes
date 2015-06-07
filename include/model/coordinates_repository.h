#ifndef COORDINATES_REPOSITORY_H
#define COORDINATES_REPOSITORY_H

#include "repository.h"

class CoordinatesRepository : public Repository
{
public:
    CoordinatesRepository(CoordinatesRepository *repository = nullptr, QMap<QString, Repository*> *parent = nullptr);
    CoordinatesRepository(const QString &repositoryName, QSqlDatabase *db, QMap<QString, Repository *> *parent = nullptr);
    CoordinatesRepository(const CoordinatesRepository &repository);

public:
    bool load();
    const QList<Entity*> &findAll() const;
    const QList<Entity*> &findBy(QMap<QString, QVariant> &criteria) const;
    bool persist();
};

#endif // COORDINATES_REPOSITORY_H

