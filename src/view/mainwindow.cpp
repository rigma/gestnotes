#include <view/mainwindow.h>
#include <view/add_student.h>

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
    AddStudentDialog *dialog = new AddStudentDialog(_repositories, this);
    dialog->show();
}
