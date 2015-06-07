#ifndef ADMINISTRATOR_REPOSITORY_H
#define ADMINISTRATOR_REPOSITORY_H

#include "repository.h"

class AdministratorRepository : public Repository
{
public:
    AdministratorRepository(AdministratorRepository *repository = nullptr, QMap<QString, Repository*> *parent = nullptr);
    AdministratorRepository(const QString &repositoryName, QSqlDatabase *db, QMap<QString, Repository*> *parent = nullptr);
    AdministratorRepository(const AdministratorRepository &repository);

public:
    bool load();
    const QList<Entity*> &findAll() const;
    const QList<Entity*> &findBy(QMap<QString, QVariant> &criteria) const;
    bool persist();
};

#endif // ADMINISTRATOR_REPOSITORY_H

