#include "pref_choix.h"
#include "ui_pref_choix.h"

pref_choix::pref_choix(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pref_choix)
{
    ui->setupUi(this);
}

pref_choix::~pref_choix()
{
    delete ui;
}
