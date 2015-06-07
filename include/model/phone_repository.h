#ifndef PHONE_REPOSITORY_H
#define PHONE_REPOSITORY_H

#include "repository.h"

class PhoneRepository : public Repository
{
public:
    PhoneRepository(PhoneRepository *repository = nullptr, QMap<QString, Repository*> *parent = nullptr);
    PhoneRepository(const QString &repositoryName, QSqlDatabase *db, QMap<QString, Repository*> *parent = nullptr);
    PhoneRepository(const PhoneRepository &repository);

public:
    bool load();
    const QList<Entity*> &findAll() const;
    const QList<Entity*> &findBy(QMap<QString, QVariant> &criteria) const;
    bool persist();
};

#endif // PHONE_REPOSITORY_H
