#ifndef COORDINATES_REPOSITORY_H
#define COORDINATES_REPOSITORY_H

#include "repository.h"

class CoordinatesRepository : public Repository
{
public:
    CoordinatesRepository(CoordinatesRepository *repository = nullptr);
    CoordinatesRepository(const QString &repositoryName);
    CoordinatesRepository(const CoordinatesRepository &repository);
    ~CoordinatesRepository();

public:
    bool load();
    const QList<Entity*> &findAll() const;
    const QList<Entity*> &findBy(QMap<QString, QVariant> &criteria) const;
    bool persist();
};

#endif // COORDINATES_REPOSITORY_H

