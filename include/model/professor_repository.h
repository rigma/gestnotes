#ifndef PROFESSOR_REPOSITORY_H
#define PROFESSOR_REPOSITORY_H

#include "repository.h"

class ProfessorRepository : public Repository
{
public:
    ProfessorRepository(ProfessorRepository *repository = nullptr);
    ProfessorRepository(const QString &repositoryName);
    ProfessorRepository(const ProfessorRepository &repository);
    ~ProfessorRepository();

public:
    bool load();
    const QList<Entity*> &findAll() const;
    const QList<Entity*> &findBy(QMap<QString, QVariant> &criteria) const;
    bool persist();
};

#endif // PROFESSOR_REPOSITORY_H

