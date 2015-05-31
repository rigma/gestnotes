#ifndef CONTACT_REPOSITORY_H
#define CONTACT_REPOSITORY_H

#include "repository.h"

class ContactRepository : public Repository
{
public:
    ContactRepository(ContactRepository *repository = nullptr);
    ContactRepository(const QString &repositoryName);
    ContactRepository(const ContactRepository &repository);

public:
    bool load();
    const QList<Entity*> &findAll() const;
    const QList<Entity*> &findBy(QMap<QString, QVariant> &criteria) const;
    bool persist();
};

#endif // CONTACT_REPOSITORY_H

