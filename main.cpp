#include <QApplication>
#include <QDebug>
#include <QFile>
#include <QMap>
#include <QSqlDatabase>
#include <QSqlQuery>

#include <model/administrator_repository.h>
#include <model/professor_repository.h>
#include <model/student_repository.h>
#include <model/contact_repository.h>
#include <model/coordinates_repository.h>
#include <model/phone_repository.h>

#include <view/connectionwindow.h>
#include <view/mainwindow.h>

#define N 6

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QMap<QString, Repository*> repositories;
    MainWindow *window(nullptr);
    QSqlDatabase db;
    QSqlQuery query;

    int code(0);
    bool prepare(false);

    if (!QFile("gestnotes.db").exists())
        prepare = true;

    db = QSqlDatabase::addDatabase(QString("QSQLITE"));
    db.setHostName(QString("localhost"));
    db.setDatabaseName(QString("gestnotes.db"));
    db.setUserName(QString("gestnotes"));
    db.setPassword(QString("gestnotes"));

    if (!db.open())
        return 1;

    if (prepare)
    {
        query = QSqlQuery(db);
        query.exec(QString("CREATE TABLE administrator(id INTEGER PRIMARY KEY ASC AUTOINCREMENT NOT NULL, serial TEXT NOT NULL, password INTEGER NOT NULL, name TEXT NOT NULL, surname TEXT NOT NULL, email TEXT NOT NULL)"));
        query.exec(QString("CREATE TABLE professor(id INTEGER PRIMARY KEY ASC AUTOINCREMENT NOT NULL, serial TEXT NOT NULL, password INTEGER NOT NULL, name TEXT NOT NULL, surname TEXT NOT NULL)"));
        query.exec(QString("CREATE TABLE student(id INTEGER PRIMARY KEY ASC AUTOINCREMENT NOT NULL, serial TEXT NOT NULL, password INTEGER NOT NULL, name TEXT NOT NULL, surname TEXT NOT NULL, birth TEXT NOT NULL, registering TEXT NOT NULL)"));
        query.exec(QString("CREATE TABLE contact(id INTEGER PRIMARY KEY ASC AUTOINCREMENT NOT NULL, lastName TEXT NOT NULL, first TEXT NOT NULL)"));
        query.exec(QString("CREATE TABLE coordinates(id INTEGER PRIMARY KEY ASC AUTOINCREMENT NOT NULL, number INTEGER NOT NULL, type INTEGER NOT NULL, name TEXT NOT NULL, zipCode TEXT NOT NULL, city TEXT NOT NULL, country TEXT NOT NULL, email TEXT NOT NULL)"));
        query.exec(QString("CREATE TABLE phone(id INTEGER PRIMARY KEY ASC AUTOINCREMENT NOT NULL, type INTEGER NOT NULL, countryCode TEXT NOT NULL, number TEXT NOT NULL)"));

        query.prepare(QString("INSERT INTO administrator (serial, password, surname, name, email) VALUES (:serial, :passwd, :surname, :name, :email)"));
        query.bindValue(QString(":serial"), QVariant("root"));
        query.bindValue(QString(":passwd"), QVariant(qHash("root")));
        query.bindValue(QString(":surname"), QVariant("John"));
        query.bindValue(QString(":name"), QVariant("Doe"));
        query.bindValue(QString(":email"), QVariant("root@localhost"));
        query.exec();
    }

    repositories.insert("administrator", new AdministratorRepository(QString("administrator"), &db, &repositories));
    repositories.value("administrator")->load();

    repositories.insert("professor", new ProfessorRepository(QString("professor"), &db, &repositories));
    repositories.value("professor")->load();

    repositories.insert("student", new StudentRepository(QString("student"), &db, &repositories));
    repositories.value("student")->load();

    repositories.insert("contact", new ContactRepository(QString("contact"), &db, &repositories));
    repositories.value("contact")->load();

    repositories.insert("coordinates", new CoordinatesRepository(QString("coordinates"), &db, &repositories));
    repositories.value("coordinates")->load();

    repositories.insert("phone", new PhoneRepository(QString("phone"), &db, &repositories));
    repositories.value("phone")->load();

    ConnectionWindow connection(&repositories, &window);
    connection.show();

    code = app.exec();

    for (QMap<QString, Repository*>::const_iterator it = repositories.begin() ; it != repositories.end() ; it++)
    {
        it.value()->persist();

        delete it.value();
    }

    if (window != nullptr)
        delete window;

    return code;
}
