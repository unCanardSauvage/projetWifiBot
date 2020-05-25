#include "mainwindow.h"
#include "casealign.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    std::string joueurActif = "JOUEUR_UN";
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
