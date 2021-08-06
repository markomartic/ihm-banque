#ifndef PREFSPERSO_H
#define PREFSPERSO_H

#include <QWidget>

namespace Ui {
class PrefsPerso;
}

class PrefsPerso : public QWidget
{
    Q_OBJECT

public:
    explicit PrefsPerso(QWidget *parent = nullptr);
    ~PrefsPerso();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_comboBox_2_currentIndexChanged(int index);

    void on_comboBox_2_activated(int index);

private:
    Ui::PrefsPerso *ui;
};

#endif // PREFSPERSO_H
