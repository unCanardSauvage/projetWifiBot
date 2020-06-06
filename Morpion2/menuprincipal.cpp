#include "menuprincipal.h"
#include "ui_menuprincipal.h"


MenuPrincipal::MenuPrincipal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuPrincipal)
{
    ui->setupUi(this);
    //ui->
}

MenuPrincipal::~MenuPrincipal()
{
    delete ui;
}

void MenuPrincipal::jouer(){
    mainwindow.show();
    this->close();
}

void MenuPrincipal::quitter(){
    this->close();
}
