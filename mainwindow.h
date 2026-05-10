#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "equacao.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // Equação do mostrador
    Equacao *equacao;

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    void atualizaMostrador();

private slots:
    void on_Btn0_clicked();

    void on_Btn1_clicked();

    void on_Btn2_clicked();

    void on_Btn3_clicked();

    void on_Btn4_clicked();

    void on_Btn5_clicked();

    void on_Btn6_clicked();

    void on_Btn7_clicked();

    void on_Btn8_clicked();

    void on_Btn9_clicked();

    void on_BtnVirgula_clicked();

    void on_BtnPi_clicked();

    void on_BtnBackspace_clicked();

    void on_BtnClear_clicked();

    void on_BtnMais_clicked();

    void on_BtnMenos_clicked();

    void on_BtnMult_clicked();

    void on_BtnDiv_clicked();

    void on_BtnLn_clicked();

    void on_BtnFat_clicked();

    void on_BtnSen_clicked();

    void on_BtnCos_clicked();

    void on_BtnTg_clicked();

    void on_BtnRaizQuadrada_clicked();

    void on_BtnElevadoA2_clicked();

    void on_BtnEuler_clicked();

    void on_BtnAbreParenteses_clicked();

    void on_BntFechaParenteses_clicked();

    void on_BtnFrac_clicked();

    void on_BtnElevado_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
