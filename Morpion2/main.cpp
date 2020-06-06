#include "mainwindow.h"
#include "casealign.h"
#include "menuprincipal.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    std::string joueurActif = "JOUEUR_UN";
    QApplication a(argc, argv);
    MenuPrincipal menu;
    menu.show();
    return a.exec();
}
