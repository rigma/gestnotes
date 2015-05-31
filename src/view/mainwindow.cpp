#include <view/mainwindow.h>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QMap<QString, Repository*> *repositories, const MainWindow::Mode &mode, QWidget *parent) : QMainWindow(parent),
    _ui(new Ui::MainWindow),
    _repositories(repositories)
{
    _ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete _ui;
}
