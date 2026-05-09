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
    Equacao equacao;

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

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
