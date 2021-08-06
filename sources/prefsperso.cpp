
#include <QApplication>
#include "tableaudebord.h"
#include <QWidget>
#include <QLayout>
#include "mainwindow.h"
#include <QScreen>
#include "prefsperso.h"
#include "ui_prefsperso.h"

PrefsPerso::PrefsPerso(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrefsPerso)
{
    ui->setupUi(this);
    int x = (QApplication::primaryScreen()->geometry().width()-this->width()) / 2;
    int y = (QApplication::primaryScreen()->geometry().height()-this->height()) / 2;
    this->move(x, y);
}

PrefsPerso::~PrefsPerso()
{
    delete ui;
}

void PrefsPerso::on_pushButton_2_clicked()
{
    MainWindow *mainwindow = new MainWindow();
    mainwindow->show();
    this->close();
}

void PrefsPerso::on_pushButton_clicked()
{
    TableauDeBord *w = new TableauDeBord();
    w->show();
    this->close();
}

void PrefsPerso::on_comboBox_2_currentIndexChanged(int index)
{

}

void PrefsPerso::on_comboBox_2_activated(int index)
{
    if(index == 0) {
        QFile styleSheetFile(":/");
        styleSheetFile.open(QFile::ReadOnly);
        QString styleSheet = QLatin1String(styleSheetFile.readAll());

        qApp->setStyleSheet(styleSheet);
    }
    else {
        QFile styleSheetFile(":/ressources/stylesheet/theme.qss");
        styleSheetFile.open(QFile::ReadOnly);
        QString styleSheet = QLatin1String(styleSheetFile.readAll());

        qApp->setStyleSheet(styleSheet);
    }
}
