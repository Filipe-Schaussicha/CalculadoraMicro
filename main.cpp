#include "mainwindow.h"

#include <QApplication>

/**
* Projeto de uma calcudora feita usando C/C++ e Assembly
*
* Autores:
* - Filipe Schausst
* - Artur Silveira
*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return QCoreApplication::exec();
}
