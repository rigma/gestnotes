#include <model/student_repository.h>
#include <model/student.h>

#include <view/add_student.h>
#include <view/mainwindow.h>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QMap<QString, Repository*> *repositories, const MainWindow::Mode &mode, QWidget *parent) : QMainWindow(parent),
    _ui(new Ui::MainWindow),
    _repositories(repositories)
{
    _ui->setupUi(this);

    connect(_ui->Tableau_Eleve, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(studentContextMenu(QPoint)));
    connect(_ui->actionEl_ve, SIGNAL(triggered()), this, SLOT(ajouterEleve()));
}

MainWindow::~MainWindow()
{
    delete _ui;
}

void MainWindow::studentContextMenu(const QPoint &point)
{
    QMenu menu(this);

    menu.addAction(QString("Hello world"));
    menu.exec(_ui->Tableau_Eleve->mapToGlobal(point));
}

void MainWindow::ajouterEleve()
{
    AddStudentDialog *dialog = new AddStudentDialog(_repositories);

    connect(dialog, SIGNAL(destroyed(QObject*)), this, SLOT(studentCreated(QObject*)));
    dialog->show();
}

void MainWindow::studentCreated(QObject *dialog)
{
    StudentRepository *repo = (StudentRepository*) _repositories->value(QString("student"));

    for (QList<Entity*>::const_iterator it = repo->entities().begin() ; it != repo->entities().end() ; it++)
    {
        Student *student = (Student*) *it;

        _ui->Tableau_Eleve->addItem(student->name() + " " + student->surname());
    }

    dialog->deleteLater();
}
