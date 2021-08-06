
#include <qchecklist.h>
#include <QComboBox>
#include <qcheckbox.h>
#include "tableaudebord.h"
#include "stats.h"
#include "ui_stats.h"
#include <QScreen>

Stats::Stats(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Stats)
{
    ui->setupUi(this);

    int x = (QApplication::primaryScreen()->geometry().width()-this->width()) / 2;
    int y = (QApplication::primaryScreen()->geometry().height()-this->height()) / 2;
    this->move(x, y);

    //noms banquiers
    const char *noms[10] = {"Draal", "ffetsy", "YuuSen", "pl", "Witcher", "toti", "hsivric", "T.S.H.", "Appas", "uzerman"};
    for(int i = 0; i<100; i++) {
        ui->tableWidget->insertRow (ui->tableWidget->rowCount());
        ui->tableWidget->setItem   (ui->tableWidget->rowCount()-1, 5, new QTableWidgetItem(noms[rand()%10]));
    }

    //prix de vente
    const char *prix[7] = {"100 €", "200 €", "500 €", "700 €", "1000 €", "1500 €", "2000 €"};
    for(int i = 0; i<100; i++) {
        ui->tableWidget->setItem   (i, 1, new QTableWidgetItem(prix[rand()%7]));
    }

    //nom produit
    const char *produits[7] = {"", "200 €", "500 €", "700 €", "1000 €", "1500 €", "2000 €"};
    for(int i = 0; i<100; i++) {
        ui->tableWidget->setItem   (i, 1, new QTableWidgetItem(produits[rand()%7]));
    }

    QCheckList *qcl = ui->comboBox_4;
    qcl->addCheckItem("Prêts", 17, Qt::Unchecked);
    qcl->addCheckItem("Comptes", 17, Qt::Unchecked);
    qcl->addCheckItem("Chéquiers", 17, Qt::Unchecked);
    qcl->setNoneCheckedText("Banque");

    QCheckList *qcl2 = ui->comboBox_5;
    qcl2->addCheckItem("Ecrans", 17, Qt::Unchecked);
    qcl2->addCheckItem("Téléphone", 17, Qt::Unchecked);
    qcl2->addCheckItem("Habitation", 17, Qt::Unchecked);
    qcl2->setNoneCheckedText("Assurances");

    QCheckList *qcl3 = ui->comboBox_6;
    qcl3->addCheckItem("La Banque", 17, Qt::Unchecked);
    qcl3->setNoneCheckedText("Bourse");
}

Stats::~Stats()
{
    delete ui;
}

void Stats::on_pushButton_3_clicked()
{
    (new TableauDeBord())->show();
    this->close();
}

void Stats::on_pushButton_7_clicked()
{
    //(new FonctionnaliteAbsente())->show();
    QMessageBox msgBox;
    msgBox.setText("Fonctionnalité en cours de développement.");
    msgBox.exec();

}

void Stats::on_pushButton_5_clicked()
{
    //(new FonctionnaliteAbsente())->show();
    QMessageBox msgBox;
    msgBox.setText("Fonctionnalité en cours de développement.");
    msgBox.exec();
}

void Stats::on_pushButton_6_clicked()
{
    //(new FonctionnaliteAbsente())->show();
    QMessageBox msgBox;
    msgBox.setText("Fonctionnalité en cours de développement.");
    msgBox.exec();
}
