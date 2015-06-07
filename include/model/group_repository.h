#ifndef GROUP_REPOSITORY_H
#define GROUP_REPOSITORY_H

#include "repository.h"

class GroupRepository : public Repository
{
public:
    GroupRepository(GroupRepository *repository = nullptr, QMap<QString, Repository*> *parent = nullptr);
    GroupRepository(const QString &repositoryName, QSqlDatabase *db, QMap<QString, Repository *> *parent = nullptr);
    GroupRepository(const GroupRepository &repository);

public:
    bool load();
    const QList<Entity*> &findAll() const;
    const QList<Entity*> &findBy(QMap<QString, QVariant> &criteria) const;
    bool persist();
};

#endif // GROUP_REPOSITORY_H

