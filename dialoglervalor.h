#ifndef DIALOGLERVALOR_H
#define DIALOGLERVALOR_H

#include <QDialog>

namespace Ui {
class DialogLerValor;
}

class DialogLerValor : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLerValor(QWidget *parent = nullptr);
    ~DialogLerValor();

    QString getTexto();
    void mudarLabel(QString msg);

private slots:
    void on_BtnPi_clicked();

    void on_BtnEuler_clicked();

    void on_BtnCancelar_clicked();

    void on_BtnOK_clicked();

private:
    Ui::DialogLerValor *ui;
};

#endif // DIALOGLERVALOR_H
