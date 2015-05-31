#include <QSqlRecord>
#include <QSqlQuery>

#include <model/student_repository.h>
#include <model/student.h>

StudentRepository::StudentRepository(StudentRepository *repository) : Repository(repository)
{

}

StudentRepository::StudentRepository(const QString &repositoryName) : Repository(repositoryName)
{

}

StudentRepository::StudentRepository(const StudentRepository &repository) : Repository(repository)
{

}

bool StudentRepository::load()
{
    QSqlQuery query(QString("SELECT * FROM ") + _repositoryName);
    int idField(query.record().indexOf(QString("id")));
    int serialField(query.record().indexOf(QString("serial")));
    int passwdField(query.record().indexOf(QString("password")));
    int surnameField(query.record().indexOf(QString("surname")));
    int nameField(query.record().indexOf(QString("name")));
    int birthField(query.record().indexOf(QString("birth")));
    int registeringField(query.record().indexOf(QString("registering")));

    while (query.next())
    {
        Student *student = new Student(false);

        student->_id = query.value(idField).toULongLong();
        student->setSerial(query.value(serialField).toString());
        student->setPassword(query.value(passwdField).toUInt());
        student->setSurname(query.value(surnameField).toString());
        student->setName(query.value(nameField).toString());
        student->setBirth(query.value(birthField).toDate());
        student->setRegistering(query.value(registeringField).toDate());

        _entities.append(student);
    }

    return true;
}

const QList<Entity*> &StudentRepository::findAll() const
{
    return _entities;
}

const QList<Entity*> &StudentRepository::findBy(QMap<QString, QVariant> &criteria) const
{
    QList<Entity*> *result = new QList<Entity*>();

    for (QMap<QString, QVariant>::const_iterator c = criteria.begin() ; c != criteria.end() ; c++)
    {
        for (QList<Entity*>::const_iterator i = _entities.begin() ; i != _entities.end() ; i++)
        {
            Student *student = (Student*) *i;

            if (c.key() == QString("id") || c.key() == QString("ID"))
            {
                if (student->id() == (*c).toULongLong())
                    result->append(student);
            }
            else if (c.key() == QString("serial") || c.key() == QString("SERIAL"))
            {
                if (student->serial() == (*c).toString())
                    result->append(student);
            }
            else if (c.key() == QString("passwd") || c.key() == QString("PASSWD"))
            {
                if (student->passwd() == (*c).toUInt())
                    result->append(student);
            }
            else if (c.key() == QString("surname") || c.key() == QString("SURNAME"))
            {
                if (student->surname() == (*c).toString())
                    result->append(student);
            }
            else if (c.key() == QString("name") || c.key() == QString("NAME"))
            {
                if (student->name() == (*c).toString())
                    result->append(student);
            }
            else if (c.key() == QString("birth") || c.key() == QString("BIRTH"))
            {
                if (student->birth() == (*c).toDate())
                    result->append(student);
            }
            else if (c.key() == QString("registering") || c.key() == QString("REGISTERING"))
            {
                if (student->registering() == (*c).toDate())
                    result->append(student);
            }
        }
    }

    return *result;
}

bool StudentRepository::persist()
{
    bool result(true);

    for (QList<Entity*>::const_iterator i = _entities.begin() ; i != _entities.end() ; i++)
    {
        Student *student = (Student*) *i;
        QSqlQuery query;

        if (student->_modified)
        {
            query.prepare(QString("UPDATE ") + _repositoryName + QString(" SET serial = :serial, passwd = :passwd, surname = :surname, name = :name, birth = date(:birth), registering = date(:registering) WHERE id :id"));
            query.bindValue(QString(":serial"), QVariant(student->id()));
            query.bindValue(QString(":passwd"), QVariant(student->passwd()));
            query.bindValue(QString(":surname"), QVariant(student->surname()));
            query.bindValue(QString(":name"), QVariant(student->name()));
            query.bindValue(QString(":birth"), QVariant(student->birth()));
            query.bindValue(QString(":registering"), QVariant(student->registering()));

            student->_modified = false;
        }
        else if (student->_created)
        {
            query.prepare(QString("INSERT INTO ") + _repositoryName + QString("(serial, passwd, surname, name, birth, registering) VALUES (:serial, :passwd, :surname, :name, date(:birth), date(:registering))"));
            query.bindValue(QString(":serial"), QVariant(student->serial()));
            query.bindValue(QString(":passwd"), QVariant(student->passwd()));
            query.bindValue(QString(":surname"), QVariant(student->surname()));
            query.bindValue(QString(":name"), QVariant(student->name()));
            query.bindValue(QString(":birth"), QVariant(student->birth()));
            query.bindValue(QString(":registering"), QVariant(student->registering()));

            student->_created = false;
        }
        else if (student->_deleted)
        {
            query.prepare(QString("DELETE FROM ") + _repositoryName + QString(" WHERE id = :id"));
            query.bindValue(QString(":id"), QVariant(student->id()));

            _entities.removeOne(*i);
            delete student;
        }

        result = result && query.exec();
    }

    return result;
}
