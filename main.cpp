#include <QApplication>
#include <QMap>
#include <QProgressBar>
#include <QSqlDatabase>
#include <QSqlQuery>

#include <model/administrator_repository.h>
#include <model/professor_repository.h>
#include <model/student_repository.h>

#include <view/connectionwindow.h>

#define N 3

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QMap<QString, Repository*> repositories;
    QProgressBar loading;
    QSqlDatabase db;
    QSqlQuery query;

    if (QSqlDatabase::connectionNames().empty())
    {
        db = QSqlDatabase::addDatabase(QString("QSQLITE"));
        db.setHostName(QString("localhost"));
        db.setDatabaseName(QString("gestnotes.db"));
        db.setUserName(QString("gestnotes"));
        db.setPassword(QString("gestnotes"));

        if (!db.open())
            return 0;

        query = QSqlQuery(db);
        query.exec(QString("CREATE TABLE administrator(id INTEGER PRIMARY KEY ASC AUTOINCREMENT NOT NULL, serial TEXT NOT NULL, password INTEGER NOT NULL, name TEXT NOT NULL, surname TEXT NOT NULL, email TEXT NOT NULL)"));
        query.exec(QString("CREATE TABLE professor(id INTEGER PRIMARY KEY ASC AUTOINCREMENT NOT NULL, serial TEXT NOT NULL, password INTEGER NOT NULL, name TEXT NOT NULL, surname TEXT NOT NULL)"));
        query.exec(QString("CREATE TABLE student(id INTEGER PRIMARY KEY ASC AUTOINCREMENT NOT NULL, serial TEXT NOT NULL, password INTEGER NOT NULL, name TEXT NOT NULL, surname TEXT NOT NULL, birth NUMERIC NOT NULL, registering NUMERIC NOT NULL)"));
    }
    else
    {
        db = QSqlDatabase::database();

        if (!db.open())
            return 0;
    }

    loading.setMinimum(0);
    loading.setMaximum(N);
    loading.setWindowTitle(QString("Chargement..."));
    loading.setValue(0);
    loading.show();

    repositories.insert("administrator", new AdministratorRepository(QString("administrator")));
    repositories.value("administrator")->load();

    loading.setValue(1);

    repositories.insert("professor", new ProfessorRepository(QString("professor")));
    repositories.value("professor")->load();

    loading.setValue(2);

    repositories.insert("student", new StudentRepository(QString("student")));
    repositories.value("student")->load();

    loading.setValue(3);
    loading.close();

    ConnectionWindow connection(&repositories);
    connection.show();

    return app.exec();
}
