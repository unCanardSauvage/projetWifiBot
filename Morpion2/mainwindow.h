#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "casealign.h"
#include "QMessageBox"
#include "QPushButton"
#include "intelligence.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void Update();
    void quelBouton(); // permet de simuler un clic de la IA
    void actualiserDiff(); // permet de changer le niveau de difficulté

private:
    Ui::MainWindow *ui;
    std::string joueurActif;
    bool Victoire;

    CaseAlign ligneDuHaut;
    CaseAlign ligneDuMilieu;
    CaseAlign ligneDuBas;

    CaseAlign colonneDeGauche;
    CaseAlign colonneDuMilieu;
    CaseAlign colonneDeDroite;

    CaseAlign diagonaleUn;
    CaseAlign diagonaleDeux;

    Intelligence grille;

    bool IA;

    int scoreJ1;
    int scoreJ2;


private slots:
    void on_B_effacer_clicked();
    void on_B_L1C1_clicked();
    void on_B_L1C2_clicked();
    void on_B_L1C3_clicked();
    void on_B_L2C1_clicked();
    void on_B_L2C2_clicked();
    void on_B_L2C3_clicked();
    void on_B_L3C1_clicked();
    void on_B_L3C2_clicked();
    void on_B_L3C3_clicked();
    void changerDiff();
    void setIA(); // permet de définir si on joue contre la IA ou en en PvP
    void quitter();
};
#endif // MAINWINDOW_H
