#ifndef CONNECTIONWINDOW_H
#define CONNECTIONWINDOW_H

#include <QMap>
#include <QWidget>

#include <model/repository.h>
#include <view/mainwindow.h>

namespace Ui {
class ConnectionWindow;
}

class ConnectionWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ConnectionWindow(QMap<QString, Repository*> *repositories, MainWindow **mainWindow, QWidget *parent = 0);
    ~ConnectionWindow();

private slots:
    void connect();


private:
    Ui::ConnectionWindow *_ui;
    QMap<QString, Repository*> *_repositories;
    MainWindow **_mainWindow;
};

#endif // CONNECTIONWINDOW_H
