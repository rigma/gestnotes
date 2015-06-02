#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <model/repository.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum Mode
    {
        ADMINISTRATOR = 0,
        PROFESSOR = 1,
        STUDENT = 2
    };

public:
    explicit MainWindow(QMap<QString, Repository*> *repositories, const Mode &mode = STUDENT, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void studentContextMenu(const QPoint &point);
    void ajouterEleve();
    void studentCreated(QObject *dialog);

private:
    Ui::MainWindow *_ui;
    QMap<QString, Repository*> *_repositories;
};

#endif // MAINWINDOW_H

