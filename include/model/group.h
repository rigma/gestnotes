#ifndef GROUP_H
#define GROUP_H

#include <QList>

#include "entity.h"
#include "student.h"

class Group : public Entity
{
    Q_OBJECT

public:
    Group(bool created = true, const QObject *parent = nullptr);
    Group(const QString &name, const float &coefficient, bool created = true, QObject *parent = nullptr);
    ~Group();

public:
    const QString &name() const;
    float coefficient() const;
    const QList<Student*> &students() const;

public:
    void setName(const QString &group);
    void setCoefficient(const float &coefficient);
    void addStudent(const Student *student);
    void removeStudent(const Student *student);

private:
    QString _name;
    float _coefficient;
    QList<Student*> _students;
};

#endif // GROUP_H
