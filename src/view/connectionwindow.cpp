#include <QMessageBox>

#include <model/administrator_repository.h>
#include <model/professor_repository.h>
#include <model/student_repository.h>

#include <view/connectionwindow.h>
#include <view/mainwindow.h>

#include "ui_connectionwindow.h"

ConnectionWindow::ConnectionWindow(QMap<QString, Repository*> *repositories, MainWindow **mainWindow, QWidget *parent) : QWidget(parent),
    _ui(new Ui::ConnectionWindow),
    _repositories(repositories),
    _mainWindow(mainWindow)
{
    _ui->setupUi(this);
    QObject::connect(_ui->Button_connect, SIGNAL(clicked()), this, SLOT(connect()));
}

ConnectionWindow::~ConnectionWindow()
{
    delete _ui;
}


void ConnectionWindow::connect()
{
    AdministratorRepository *repoAdmin = (AdministratorRepository*) _repositories->value("administrator");
    ProfessorRepository *repoProf = (ProfessorRepository*) _repositories->value("professor");
    StudentRepository *repoStudent = (StudentRepository*) _repositories->value("student");

    QList<Entity*> result;
    QMap<QString, QVariant> criteria;

    criteria.insert("serial", QVariant(_ui->LineEdit_id->text()));
    criteria.insert("passwd", QVariant(qHash(_ui->lineEdit_mdp->text())));

    _ui->LineEdit_id->setText(QString(""));
    _ui->lineEdit_mdp->setText(QString(""));

    result = repoAdmin->findBy(criteria);
    if (!result.empty())
    {
        *_mainWindow = new MainWindow(_repositories, MainWindow::Administrator);

        close();
        (*_mainWindow)->show();

        return;
    }

    result = repoProf->findBy(criteria);
    if (!result.empty())
    {
        *_mainWindow = new MainWindow(_repositories, MainWindow::Professor);

        close();
        (*_mainWindow)->show();

        return;
    }

    result = repoStudent->findBy(criteria);
    if (result.empty())
    {
        *_mainWindow = new MainWindow(_repositories);

        close();
        (*_mainWindow)->show();

        return;
    }
    else
        QMessageBox::critical(this, QString("Erreur de connexion !"), QString("Impossible de vous connecter avec les identifiants que vous avez renseigné !"));
}
