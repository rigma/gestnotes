#include <view/mainwindow.h>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QMap<QString, Repository*> *repositories, const MainWindow::Mode &mode, QWidget *parent) : QMainWindow(parent),
    _ui(new Ui::MainWindow),
    _repositories(repositories)
{
    _ui->setupUi(this);

    connect(_ui->Tableau_Eleve, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(studentContextMenu(QPoint)));
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
