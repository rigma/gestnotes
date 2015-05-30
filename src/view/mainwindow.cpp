#include <view/mainwindow.h>

MainWindow::MainWindow(QMap<QString, Repository*> *repositories, const MainWindow::Mode &mode, QWidget *parent) : QMainWindow(parent),
    _repositories(repositories)
{
    _ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete _ui;
}
