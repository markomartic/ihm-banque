
#include "prefsperso.h"
#include <qdebug.h>
#include <qmessagebox.h>
#include "fonctionnaliteabsente.h"
#include "qchecklist.h"
#include <iostream>
#include <QtGui>
#include "qcustomplot.h"
#include <QScreen>
#include "mainwindow.h"
#include "tableaudebord.h"
#include "ui_tableaudebord.h"

TableauDeBord::TableauDeBord(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableauDeBord)
{
    ui->setupUi(this);

    QCheckList *qcl = ui->comboBox_4;
    qcl->addCheckItem("Toutes Agences", 17, Qt::Unchecked);
    qcl->addCheckItem("Agence A", 17, Qt::Checked);
    qcl->addCheckItem("Agence B", 17, Qt::Unchecked);
    qcl->addCheckItem("Agence C", 17, Qt::Unchecked);
    qcl->addCheckItem("Agence D", 17, Qt::Unchecked);
    qcl->addCheckItem("Agence E", 17, Qt::Unchecked);
    qcl->setNoneCheckedText("Agence A");

    new MonGraphe(ui->widget, 0, 3, "Prêts", "Comptes", "Chéquiers", 3, 2, 1);
    new MonGraphe(ui->widget_2, 0, 2, "Ecrans", "Tél", "", 3, 2, 0);
    new MonGraphe(ui->widget_3, 0, 1, "La Banque", "", "", 3, 0, 0);
    new MonGraphe(ui->widget_4, 0, 1, "La Banque", "", "", 3, 0, 0);
    new MonGraphe(ui->widget_5, 0, 3, "Bancaire", "Assurance", "Bourse", 3, 2, 1);

    // position au milieu de l'écran
    int x = (QApplication::primaryScreen()->geometry().width()-this->width()) / 2;
    int y = (QApplication::primaryScreen()->geometry().height()-this->height()) / 2;
    this->move(x, y);

    // màj de la date du jour-même
    ui->dateEdit->setDate(QDate::currentDate().addMonths(-6));
    ui->dateEdit_3->setDate(QDate::currentDate().addMonths(-3));
}

TableauDeBord::~TableauDeBord()
{
    delete ui;
}

void TableauDeBord::on_pushButton_clicked()
{
    MainWindow *w = new MainWindow();
    w->show();
    this->close();
}

void TableauDeBord::on_pushButton_8_clicked()
{

}

void TableauDeBord::on_pushButton_4_clicked()
{
    Stats *w = new Stats();
    w->show();
    this->close();
}

void TableauDeBord::on_pushButton_7_clicked()
{
    //(new FonctionnaliteAbsente())->show();
    QMessageBox msgBox;
    msgBox.setText("Fonctionnalité en cours de développement.");
    msgBox.exec();

}

void TableauDeBord::on_pushButton_5_clicked()
{
    //(new FonctionnaliteAbsente())->show();
    QMessageBox msgBox;
    msgBox.setText("Fonctionnalité en cours de développement.");
    msgBox.exec();
}

void TableauDeBord::on_pushButton_6_clicked()
{
    //(new FonctionnaliteAbsente())->show();
    QMessageBox msgBox;
    msgBox.setText("Fonctionnalité en cours de développement.");
    msgBox.exec();
}
