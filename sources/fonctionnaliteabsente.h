#ifndef FONCTIONNALITEABSENTE_H
#define FONCTIONNALITEABSENTE_H

#include <QWidget>

namespace Ui {
class FonctionnaliteAbsente;
}

class FonctionnaliteAbsente : public QWidget
{
    Q_OBJECT

public:
    explicit FonctionnaliteAbsente(QWidget *parent = nullptr);
    ~FonctionnaliteAbsente();

private slots:
    void on_pushButton_clicked();

private:
    Ui::FonctionnaliteAbsente *ui;
};

#endif // FONCTIONNALITEABSENTE_H
