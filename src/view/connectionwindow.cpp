#include <model/administrator_repository.h>
#include <view/connectionwindow.h>

#include "ui_connectionwindow.h"

ConnectionWindow::ConnectionWindow(QMap<QString, Repository*> *repositories, QWidget *parent) : QWidget(parent),
    _ui(new Ui::ConnectionWindow),
    _repositories(repositories)
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
    AdministratorRepository *repo = (AdministratorRepository*) _repositories->value("administrator");
    QList<Entity*> result;
    QMap<QString, QVariant> criteria;

    criteria.insert("serial", QVariant(_ui->lineEdit_id->text()));
    criteria.insert("passwd", QVariant(qHash(_ui->lineEdit_mdp->text())));

    result = repo->findBy(criteria);

    if (result.empty())
    {
        _ui->lineEdit_id->setText(QString(""));
        _ui->lineEdit_mdp->setText(QString(""));
    }
    // else afficher la nouvelle fenêtre
}
