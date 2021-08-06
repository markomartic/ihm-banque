
#include <qscreen.h>
#include "fonctionnaliteabsente.h"
#include "ui_fonctionnaliteabsente.h"

FonctionnaliteAbsente::FonctionnaliteAbsente(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FonctionnaliteAbsente)
{
    ui->setupUi(this);
    int x = (QApplication::primaryScreen()->geometry().width()-this->width()) / 2;
    int y = (QApplication::primaryScreen()->geometry().height()-this->height()) / 2;
    this->move(x, y);
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
}

FonctionnaliteAbsente::~FonctionnaliteAbsente()
{
    delete ui;
}

void FonctionnaliteAbsente::on_pushButton_clicked()
{
    this->close();
}
