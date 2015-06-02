#include <include/model/group.h>

Group::Group(bool created, QObject *parent) : Entity(created, parent),
    _name(),
    _students()
{

}

Group::Group(const QString &name, bool created, QObject *parent) : Entity(created, parent),
    _name(name),
    _students()
{

}

Group::~Group()
{

}

const QString &Group::name() const
{
    return _name;
}
const QList<Student*> &Group::students() const
{
    return _students;
}

void Group::setName(const QString &name)
{
    _name = name;
}

void Group::addStudent(Student *student)
{
    if (!_students.contains(student))
        _students.append(student);
}

void Group::removeStudent(Student *student)
{
    _students.removeAll(student);
}
