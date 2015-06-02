#ifndef ADD_PROFESSOR
#define ADD_PROFESSOR

#include <QDialog>
#include <QMap>
#include <model/repository.h>


namespace Ui {
class AddProfessorDialog;
}

class AddProfessorDialog : public QDialog
{
    Q_OBJECT

public:
    AddProfessorDialog(QMap<QString, Repository*> *repositories, QWidget *parent = nullptr);
    ~AddProfessorDialog();

private slots:
    void accept();
    void reject();

private:
    Ui::AddProfessorDialog *_ui;
    QMap<QString, Repository*> *_repositories;
};


#endif // ADD_PROFESSOR_H


