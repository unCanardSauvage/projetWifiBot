#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QPushButton"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    joueurActif = "JOUEUR_UN";
    Victoire = false;
    MainWindow::actualiserDiff();
    grille.getDifficulte();
    grille.initGrille();
    IA = true;
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
        if (joueurActif == "JOUEUR_UN"){ QMessageBox::information(0,"Morpion","Bravo ! Joueur 1 a gagné");}
        else{QMessageBox::information(0,"Morpion","Bravo ! Joueur 2 a gagné");}
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

    MainWindow::actualiserDiff();
    grille.getDifficulte();
    grille.initGrille();
}

void MainWindow::on_B_L1C1_clicked()
{
    ligneDuHaut.ajoutMarque(joueurActif,Victoire);
    colonneDeGauche.ajoutMarque(joueurActif,Victoire);
    diagonaleUn.ajoutMarque(joueurActif,Victoire);
    grille.setGrille(1, 1, joueurActif);
    grille.getGrille();
    Update();
    ui->B_L1C1->setEnabled(false);

    if (IA == true) {
        if(joueurActif == "JOUEUR_UN")
        {
           ui->B_L1C1->setText("X");
           joueurActif = "JOUEUR_DEUX";
           grille.choix();
           quelBouton();
        }
        else
        {
            std::cout<<"C'est mon tour !"<<std::endl;
            ui->B_L1C1->setText("O");
            joueurActif = "JOUEUR_UN";
        }
    }
    else
    {
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


}

void MainWindow::on_B_L1C2_clicked()
{
    ligneDuHaut.ajoutMarque(joueurActif,Victoire);
    colonneDuMilieu.ajoutMarque(joueurActif,Victoire);
    grille.setGrille(1, 2, joueurActif);
    grille.getGrille();
    Update();
    ui->B_L1C2->setEnabled(false);
    if (IA == true) {
        if(joueurActif == "JOUEUR_UN")
        {
           ui->B_L1C2->setText("X");
           joueurActif = "JOUEUR_DEUX";
           grille.choix();
           quelBouton();
        }
        else
        {
            std::cout<<"C'est mon tour !"<<std::endl;
            ui->B_L1C2->setText("O");
            joueurActif = "JOUEUR_UN";
        }

    }
    else
    {
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

}

void MainWindow::on_B_L1C3_clicked()
{
    ligneDuHaut.ajoutMarque(joueurActif,Victoire);
    colonneDeDroite.ajoutMarque(joueurActif,Victoire);
    diagonaleDeux.ajoutMarque(joueurActif,Victoire);
    grille.setGrille(1, 3, joueurActif);
    grille.getGrille();
    Update();
    ui->B_L1C3->setEnabled(false);
    if (IA == true) {
        if(joueurActif == "JOUEUR_UN")
        {
           ui->B_L1C3->setText("X");
           joueurActif = "JOUEUR_DEUX";
           grille.choix();
           quelBouton();
        }
        else
        {
            std::cout<<"C'est mon tour !"<<std::endl;
            ui->B_L1C3->setText("O");
            joueurActif = "JOUEUR_UN";
        }
    }
    else
    {
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

}

void MainWindow::on_B_L2C1_clicked()
{
    ligneDuMilieu.ajoutMarque(joueurActif,Victoire);
    colonneDeGauche.ajoutMarque(joueurActif,Victoire);
    grille.setGrille(2, 1, joueurActif);
    grille.getGrille();
    Update();
    ui->B_L2C1->setEnabled(false);
    if (IA == true) {
        if(joueurActif == "JOUEUR_UN")
        {
           ui->B_L2C1->setText("X");
           joueurActif = "JOUEUR_DEUX";
           grille.choix();
           quelBouton();
        }
        else
        {
            std::cout<<"C'est mon tour !"<<std::endl;
            ui->B_L2C1->setText("O");
            joueurActif = "JOUEUR_UN";
        }
    }
    else
    {
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
}

void MainWindow::on_B_L2C2_clicked()
{
    ligneDuMilieu.ajoutMarque(joueurActif,Victoire);
    colonneDuMilieu.ajoutMarque(joueurActif,Victoire);
    diagonaleUn.ajoutMarque(joueurActif,Victoire);
    diagonaleDeux.ajoutMarque(joueurActif,Victoire);
    grille.setGrille(2, 2, joueurActif);
    grille.getGrille();
    Update();
    ui->B_L2C2->setEnabled(false);
    if (IA == true) {
        if(joueurActif == "JOUEUR_UN")
        {
           ui->B_L2C2->setText("X");
           joueurActif = "JOUEUR_DEUX";
           grille.choix();
           quelBouton();
        }
        else
        {
            std::cout<<"C'est mon tour !"<<std::endl;
            ui->B_L2C2->setText("O");
            joueurActif = "JOUEUR_UN";
        }
    }
    else
    {
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

}

void MainWindow::on_B_L2C3_clicked()
{
    ligneDuMilieu.ajoutMarque(joueurActif,Victoire);
    colonneDeDroite.ajoutMarque(joueurActif,Victoire);
    grille.setGrille(2, 3, joueurActif);
    grille.getGrille();
    Update();
    ui->B_L2C3->setEnabled(false);
    if (IA == true) {
        if(joueurActif == "JOUEUR_UN")
        {
           ui->B_L2C3->setText("X");
           joueurActif = "JOUEUR_DEUX";
           grille.choix();
           quelBouton();
        }
        else
        {
            std::cout<<"C'est mon tour !"<<std::endl;
            ui->B_L2C3->setText("O");
            joueurActif = "JOUEUR_UN";
        }
    }
    else{
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
}

void MainWindow::on_B_L3C1_clicked()
{
    ligneDuBas.ajoutMarque(joueurActif,Victoire);
    colonneDeGauche.ajoutMarque(joueurActif,Victoire);
    diagonaleDeux.ajoutMarque(joueurActif,Victoire);
    grille.setGrille(3, 1, joueurActif);
    grille.getGrille();
    Update();
    ui->B_L3C1->setEnabled(false);
    if (IA == true) {
        if(joueurActif == "JOUEUR_UN")
        {
           ui->B_L3C1->setText("X");
           joueurActif = "JOUEUR_DEUX";
           grille.choix();
           quelBouton();
        }
        else
        {
            std::cout<<"C'est mon tour !"<<std::endl;
            ui->B_L3C1->setText("O");
            joueurActif = "JOUEUR_UN";
        }
    }
    else{
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
}

void MainWindow::on_B_L3C2_clicked()
{
    ligneDuBas.ajoutMarque(joueurActif,Victoire);
    colonneDuMilieu.ajoutMarque(joueurActif,Victoire);
    //std::cout<<colonneDuMilieu.getCroix()<<std::endl;
    grille.setGrille(3, 2, joueurActif);
    grille.getGrille();
    Update();
    ui->B_L3C2->setEnabled(false);
    if (IA == true) {
        if(joueurActif == "JOUEUR_UN")
        {
           ui->B_L3C2->setText("X");
           joueurActif = "JOUEUR_DEUX";
           grille.choix();
           quelBouton();
        }
        else
        {
            std::cout<<"C'est mon tour !"<<std::endl;
            ui->B_L3C2->setText("O");
            joueurActif = "JOUEUR_UN";
        }
    }
    else{
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
}

void MainWindow::on_B_L3C3_clicked()
{
    ligneDuBas.ajoutMarque(joueurActif,Victoire);
    colonneDeGauche.ajoutMarque(joueurActif,Victoire);
    diagonaleUn.ajoutMarque(joueurActif,Victoire);
    grille.setGrille(3, 3, joueurActif);
    grille.getGrille();
    Update();
    ui->B_L3C3->setEnabled(false);
    if (IA == true) {
        if(joueurActif == "JOUEUR_UN")
        {
           ui->B_L3C3->setText("X");
           joueurActif = "JOUEUR_DEUX";
           grille.choix();
           quelBouton();
        }
        else
        {
            std::cout<<"C'est mon tour !"<<std::endl;
            ui->B_L3C3->setText("O");
            joueurActif = "JOUEUR_UN";
        }
    }
    else{
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
}

void MainWindow::quelBouton()
{
    int x = grille.getBoutonX();
    int y = grille.getBoutonY();
    x++;
    y++;
    std::cout<<"x"<<grille.getBoutonX()<<"y"<<grille.getBoutonY()<<std::endl;
   if (x == 1 && y == 1)
       on_B_L1C1_clicked();
   if (x == 1 && y == 2)
       on_B_L1C2_clicked();
   if (x == 1 && y == 3)
       on_B_L1C3_clicked();
   if (x == 2 && y == 1)
       on_B_L2C1_clicked();
   if (x == 2 && y == 2)
       on_B_L2C2_clicked();
   if (x == 2 && y == 3)
       on_B_L2C3_clicked();
   if (x == 3 && y == 1)
       on_B_L3C1_clicked();
   if (x == 3 && y == 2)
       on_B_L3C2_clicked();
   if (x == 3 && y == 3)
       on_B_L3C3_clicked();
}


void MainWindow::changerDiff()
{
    ui->spinBox->value();
    this->Update();
}

void MainWindow::actualiserDiff()
{
    grille.setDifficulte(ui->spinBox->value());
}

void MainWindow::setIA()
{
    if (IA==true) {
        IA=false;
        ui->B_selectIA->setText("PvP");
    }
    else {
        IA=true;
        ui->B_selectIA->setText("IA");
    }

}
