#ifndef ADD_STUDENT_H
#define ADD_STUDENT_H

#include <QDialog>
#include <QMap>

#include <model/repository.h>

namespace Ui {
class AddStudentDialog;
}

class AddStudentDialog : public QDialog
{
    Q_OBJECT

public:
    AddStudentDialog(QMap<QString, Repository*> *repositories, QWidget *parent = nullptr);
    ~AddStudentDialog();

private slots:
    void accept();
    void reject();

private:
    Ui::AddStudentDialog *_ui;
    QMap<QString, Repository*> *_repositories;
};

#endif // ADD_STUDENT_H

