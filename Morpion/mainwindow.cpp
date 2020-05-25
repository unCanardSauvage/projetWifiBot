#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QPushButton"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    joueurActif = "JOUEUR_UN";
    Victoire = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Update()
{
    if (Victoire)
    {
        ui->B_L1C1->setEnabled(false);
        ui->B_L1C2->setEnabled(false);
        ui->B_L1C3->setEnabled(false);
        ui->B_L2C1->setEnabled(false);
        ui->B_L2C2->setEnabled(false);
        ui->B_L2C3->setEnabled(false);
        ui->B_L3C1->setEnabled(false);
        ui->B_L3C2->setEnabled(false);
        ui->B_L3C3->setEnabled(false);
        if (joueurActif == "JOUEUR_UN"){ QMessageBox::information(0,"Morpion","Bravo ! Joueur 1 a gagner");}
        else{QMessageBox::information(0,"Morpion","Bravo ! Joueur 2 a gagner");}
    }
}
void MainWindow::on_B_effacer_clicked()
{
    //efface le contenu des boutons
    ui->B_L1C1->setText("");
    ui->B_L1C2->setText("");
    ui->B_L1C3->setText("");
    ui->B_L2C1->setText("");
    ui->B_L2C2->setText("");
    ui->B_L2C3->setText("");
    ui->B_L3C1->setText("");
    ui->B_L3C2->setText("");
    ui->B_L3C3->setText("");
    //rend les boutons utilisable
    ui->B_L1C1->setEnabled(true);
    ui->B_L1C2->setEnabled(true);
    ui->B_L1C3->setEnabled(true);
    ui->B_L2C1->setEnabled(true);
    ui->B_L2C2->setEnabled(true);
    ui->B_L2C3->setEnabled(true);
    ui->B_L3C1->setEnabled(true);
    ui->B_L3C2->setEnabled(true);
    ui->B_L3C3->setEnabled(true);
    //met à zéro les alignement
    ligneDuHaut.reset();
    ligneDuMilieu.reset();
    ligneDuBas.reset();
    colonneDeGauche.reset();
    colonneDuMilieu.reset();
    colonneDeDroite.reset();
    diagonaleUn.reset();
    diagonaleDeux.reset();

    joueurActif="JOUEUR_UN";
    Victoire = false;
}

void MainWindow::on_B_L1C1_clicked()
{
    ligneDuHaut.ajoutMarque(joueurActif,Victoire);
    colonneDeGauche.ajoutMarque(joueurActif,Victoire);
    diagonaleUn.ajoutMarque(joueurActif,Victoire);
    Update();
    ui->B_L1C1->setEnabled(false);
    if(joueurActif == "JOUEUR_UN")
    {
        ui->B_L1C1->setText("X");
        joueurActif = "JOUEUR_DEUX";
    }
    else
    {
        ui->B_L1C1->setText("O");
        joueurActif = "JOUEUR_UN";
    }

}

void MainWindow::on_B_L1C2_clicked()
{
    ligneDuHaut.ajoutMarque(joueurActif,Victoire);
    colonneDuMilieu.ajoutMarque(joueurActif,Victoire);
    Update();
    ui->B_L1C2->setEnabled(false);
    if(joueurActif == "JOUEUR_UN")
    {
        ui->B_L1C2->setText("X");
        joueurActif = "JOUEUR_DEUX";
    }
    else
    {
        ui->B_L1C2->setText("O");
        joueurActif = "JOUEUR_UN";
    }

}

void MainWindow::on_B_L1C3_clicked()
{
    ligneDuHaut.ajoutMarque(joueurActif,Victoire);
    colonneDeDroite.ajoutMarque(joueurActif,Victoire);
    diagonaleDeux.ajoutMarque(joueurActif,Victoire);
    Update();
    ui->B_L1C3->setEnabled(false);
    if(joueurActif == "JOUEUR_UN")
    {
        ui->B_L1C3->setText("X");
        joueurActif = "JOUEUR_DEUX";
    }
    else
    {
        ui->B_L1C3->setText("O");
        joueurActif = "JOUEUR_UN";
    }

}

void MainWindow::on_B_L2C1_clicked()
{
    ligneDuMilieu.ajoutMarque(joueurActif,Victoire);
    colonneDeGauche.ajoutMarque(joueurActif,Victoire);
    Update();
    ui->B_L2C1->setEnabled(false);
    if(joueurActif == "JOUEUR_UN")
    {
        ui->B_L2C1->setText("X");
        joueurActif = "JOUEUR_DEUX";
    }
    else
    {
        ui->B_L2C1->setText("O");
        joueurActif = "JOUEUR_UN";
    }

}

void MainWindow::on_B_L2C2_clicked()
{
    ligneDuMilieu.ajoutMarque(joueurActif,Victoire);
    colonneDuMilieu.ajoutMarque(joueurActif,Victoire);
    diagonaleUn.ajoutMarque(joueurActif,Victoire);
    diagonaleDeux.ajoutMarque(joueurActif,Victoire);
    Update();
    ui->B_L2C2->setEnabled(false);
    if(joueurActif == "JOUEUR_UN")
    {
        ui->B_L2C2->setText("X");
        joueurActif = "JOUEUR_DEUX";
    }
    else
    {
        ui->B_L2C2->setText("O");
        joueurActif = "JOUEUR_UN";
    }

}

void MainWindow::on_B_L2C3_clicked()
{
    ligneDuMilieu.ajoutMarque(joueurActif,Victoire);
    colonneDeDroite.ajoutMarque(joueurActif,Victoire);
    Update();
    ui->B_L2C3->setEnabled(false);
    if(joueurActif == "JOUEUR_UN")
    {
        ui->B_L2C3->setText("X");
        joueurActif = "JOUEUR_DEUX";
    }
    else
    {
        ui->B_L2C3->setText("O");
        joueurActif = "JOUEUR_UN";
    }
}

void MainWindow::on_B_L3C1_clicked()
{
    ligneDuBas.ajoutMarque(joueurActif,Victoire);
    colonneDeGauche.ajoutMarque(joueurActif,Victoire);
    diagonaleDeux.ajoutMarque(joueurActif,Victoire);
    Update();
    ui->B_L3C1->setEnabled(false);
    if(joueurActif == "JOUEUR_UN")
    {
        ui->B_L3C1->setText("X");
        joueurActif = "JOUEUR_DEUX";
    }
    else
    {
        ui->B_L3C1->setText("O");
        joueurActif = "JOUEUR_UN";
    }
}

void MainWindow::on_B_L3C2_clicked()
{
    ligneDuBas.ajoutMarque(joueurActif,Victoire);
    colonneDuMilieu.ajoutMarque(joueurActif,Victoire);
    Update();
    ui->B_L3C2->setEnabled(false);
    if(joueurActif == "JOUEUR_UN")
    {
        ui->B_L3C2->setText("X");
        joueurActif = "JOUEUR_DEUX";
    }
    else
    {
        ui->B_L3C2->setText("O");
        joueurActif = "JOUEUR_UN";
    }
}

void MainWindow::on_B_L3C3_clicked()
{
    ligneDuBas.ajoutMarque(joueurActif,Victoire);
    colonneDeGauche.ajoutMarque(joueurActif,Victoire);
    diagonaleUn.ajoutMarque(joueurActif,Victoire);
    Update();
    ui->B_L3C3->setEnabled(false);
    if(joueurActif == "JOUEUR_UN")
    {
        ui->B_L3C3->setText("X");
        joueurActif = "JOUEUR_DEUX";
    }
    else
    {
        ui->B_L3C3->setText("O");
        joueurActif = "JOUEUR_UN";
    }
}
