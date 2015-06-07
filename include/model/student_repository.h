#ifndef STUDENT_REPOSITORY_H
#define STUDENT_REPOSITORY_H

#include "repository.h"

class StudentRepository : public Repository
{
public:
    StudentRepository(StudentRepository *repository = nullptr, QMap<QString, Repository*> *parent = nullptr);
    StudentRepository(const QString &repositoryName, QSqlDatabase *db, QMap<QString, Repository*> *parent = nullptr);
    StudentRepository(const StudentRepository &repository);

public:
    bool load();
    const QList<Entity*> &findAll() const;
    const QList<Entity*> &findBy(QMap<QString, QVariant> &criteria) const;
    bool persist();
};

#endif // STUDENT_REPOSITORY_H

