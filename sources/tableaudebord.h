#ifndef TABLEAUDEBORD_H
#define TABLEAUDEBORD_H

#include <QStandardItem>
#include <QWidget>
#include "mongraphe.h"
#include "stats.h"

namespace Ui {
class TableauDeBord;
}

class TableauDeBord : public QWidget
{
    Q_OBJECT

public:
    explicit TableauDeBord(QWidget *parent = nullptr);
    ~TableauDeBord();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::TableauDeBord *ui;
};

#endif // TABLEAUDEBORD_H
