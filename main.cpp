#include <QApplication>
#include <QDebug>
#include <QFile>
#include <QMap>
#include <QProgressBar>
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
    QProgressBar loading;
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
        query.exec(QString("CREATE TABLE student(id INTEGER PRIMARY KEY ASC AUTOINCREMENT NOT NULL, serial TEXT NOT NULL, password INTEGER NOT NULL, name TEXT NOT NULL, surname TEXT NOT NULL, birth NUMERIC NOT NULL, registering NUMERIC NOT NULL)"));
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

    loading.setMinimum(0);
    loading.setMaximum(N);
    loading.setWindowTitle(QString("Chargement..."));
    loading.setValue(0);
    loading.show();

    repositories.insert("administrator", new AdministratorRepository(QString("administrator"), &repositories));
    repositories.value("administrator")->load();

    loading.setValue(1);

    repositories.insert("professor", new ProfessorRepository(QString("professor"), &repositories));
    repositories.value("professor")->load();

    loading.setValue(2);

    repositories.insert("student", new StudentRepository(QString("student"), &repositories));
    repositories.value("student")->load();

    loading.setValue(3);

    repositories.insert("contact", new ContactRepository(QString("contact"), &repositories));
    repositories.value("contact")->load();

    loading.setValue(4);

    repositories.insert("coordinates", new CoordinatesRepository(QString("coordinates"), &repositories));
    repositories.value("coordinates")->load();

    loading.setValue(5);

    repositories.insert("phone", new PhoneRepository(QString("phone"), &repositories));
    repositories.value("phone")->load();

    loading.setValue(6);
    loading.close();

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
