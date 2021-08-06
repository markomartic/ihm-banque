
#include <QWidget>
#include <QLayout>
#include <QScreen>
#include <QDebug>
#include "prefsperso.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int x = (QApplication::primaryScreen()->geometry().width()-this->width()) / 2;
    int y = (QApplication::primaryScreen()->geometry().height()-this->height()) / 2;
    this->move(x, y);
    QWidget::layout()->setContentsMargins(0, 0, 0, 0);
    statusBar()->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //qInfo() << ui->lineEdit->text();
    PrefsPerso *prefsperso = new PrefsPerso();
    prefsperso->show();
    this->close();
}
