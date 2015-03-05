#include <view/connectionwindow.h>
#include "ui_connectionwindow.h"

ConnectionWindow::ConnectionWindow(QWidget *parent) : QWidget(parent),
    _ui(new Ui::ConnectionWindow)
{
    _ui->setupUi(this);
}

ConnectionWindow::~ConnectionWindow()
{
    delete _ui;
}
