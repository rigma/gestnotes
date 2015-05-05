#ifndef ADMINISTRATOR_REPOSITORY_H
#define ADMINISTRATOR_REPOSITORY_H

#include "administrator.h"
#include "repository.h"

class AdministratorRepository : public Repository
{
public:
    AdministratorRepository(AdministratorRepository *repository = nullptr);
    AdministratorRepository(const QString &repositoryName);
    AdministratorRepository(const AdministratorRepository &repository);
    ~AdministratorRepository();

public:
    bool load();
    const QList<Entity*> &findAll() const;
    const QList<Entity*> &findBy(QMap<QString, QVariant> &criteria) const;
    bool persist();
};

#endif // ADMINISTRATOR_REPOSITORY_H

