#ifndef GROUP_H
#define GROUP_H

#include <QList>

#include "entity.h"
#include "student.h"

class Group : public Entity
{
    Q_OBJECT

public:
    Group(bool created = true, QObject *parent = nullptr);
    Group(const QString &name, bool created = true, QObject *parent = nullptr);
    ~Group();

public:
    const QString &name() const;
    const QList<Student*> &students() const;

public:
    void setName(const QString &name);
    void addStudent(Student *student);
    void removeStudent(Student *student);

private:
    QString _name;
    QList<Student*> _students;
};

#endif // GROUP_H
