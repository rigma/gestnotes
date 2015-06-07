#ifndef CONTACT_REPOSITORY_H
#define CONTACT_REPOSITORY_H

#include "repository.h"

class ContactRepository : public Repository
{
public:
    ContactRepository(ContactRepository *repository = nullptr, QMap<QString, Repository *> *parent = nullptr);
    ContactRepository(const QString &repositoryName, QSqlDatabase *db, QMap<QString, Repository*> *parent = nullptr);
    ContactRepository(const ContactRepository &repository);

public:
    bool load();
    const QList<Entity*> &findAll() const;
    const QList<Entity*> &findBy(QMap<QString, QVariant> &criteria) const;
    bool persist();
};

#endif // CONTACT_REPOSITORY_H

