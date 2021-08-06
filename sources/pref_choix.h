#ifndef PREF_CHOIX_H
#define PREF_CHOIX_H

#include <QWidget>

namespace Ui {
class pref_choix;
}

class pref_choix : public QWidget
{
    Q_OBJECT

public:
    explicit pref_choix(QWidget *parent = nullptr);
    ~pref_choix();

private:
    Ui::pref_choix *ui;
};

#endif // PREF_CHOIX_H
