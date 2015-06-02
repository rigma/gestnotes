#include <QMessageBox>
#include <QMap>

#include <model/professor.h>
#include <model/professor_repository.h>
#include <view/add_professor.h>

#include "ui_add_professor.h"

AddProfessorDialog::AddProfessorDialog(QMap<QString, Repository *> *repositories, QWidget *parent) : QDialog(parent),
    _ui(new Ui::AddProfessorDialog),
    _repositories(repositories)
{
    _ui->setupUi(this);

    connect(_ui->buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(_ui->buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

AddProfessorDialog::~AddProfessorDialog()
{
    delete _ui;
}

void AddProfessorDialog::accept()
{
    ProfessorRepository *repo = (ProfessorRepository*) _repositories->value("professor");
    Professor *professor = new Professor;
    QMap<QString, QVariant> criteria;

    if (professor == nullptr)
    {
        QMessageBox::critical(this, QString("Erreur"), QString("Une erreur est survenue lors de la création du professeur !"));
        close();

        delete this;
    }

    criteria["surname"] = QVariant(_ui->lineEdit_Nom->text());
    criteria["name"] = QVariant(_ui->LineEdit_Prenom->text());

    QList<Entity*> result = repo->findBy(criteria);
    if (!result.empty())
    {
        QMessageBox::critical(this, QString("Erreur"), QString("Le porfesseur existe déjà dans la base de donnée !"));
        close();

        delete professor;
        delete this;
    }

    professor->setSerial(_ui->LineEdit_Matricule->text());
    professor->setSurname(_ui->lineEdit_Nom->text());
    professor->setName(_ui->LineEdit_Prenom->text());
    professor->setPassword(_ui->lineEdit_Nom->text().toLower() + "_" + _ui->LineEdit_Prenom->text().toLower());

    repo->save(professor);
    close();

    delete this;
}

void AddProfessorDialog::reject()
{
    close();

    delete this;
}
