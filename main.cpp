#include <QApplication>
#include <QMap>
#include <QSqlDatabase>

#include <model/administrator_repository.h>
#include <view/connectionwindow.h>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QMap<QString, Repository*> repositories;
    QSqlDatabase db;

    if (QSqlDatabase::connectionNames().empty())
    {
        db = QSqlDatabase::addDatabase(QString("QSQLITE"));
        db.setHostName(QString("localhost"));
        db.setDatabaseName(QString("gestnotes.db"));
        db.setUserName(QString("gestnotes"));
        db.setPassword(QString("gestnotes"));
    }
    else
        db = QSqlDatabase::database();

    if (!db.open())
        return 0;

    repositories.insert("administrator", new AdministratorRepository(QString("administrator")));
    repositories.value("administrator")->load();

    ConnectionWindow connection(&repositories);
    connection.show();

    return app.exec();
}
