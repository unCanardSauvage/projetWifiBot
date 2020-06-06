#ifndef INTELLIGENCE_H
#define INTELLIGENCE_H
#include <cstdlib>
#include "casealign.h"

#include <iostream>

class Intelligence
{
private:
    int grille[3][3];
    int grilleRond[3][3];
    int grilleCroix[3][3];
    int difficulte;
    int boutonX;
    int boutonY;
    bool cas3;

public:
    Intelligence();
    int tirage();
    void choix();
    void setGrille(int x, int y, std::string joueur);
    void getGrille();
    void initGrille();
    void setDifficulte(int difficulte);

    int getGrilleCroix(int x, int y);
    int getBoutonX();
    int getBoutonY();

    void getDifficulte();

    bool bloquerTableau(bool jouer);
    bool completTableau(bool jouer);
    bool jouerNormal(bool jouer);
    void jouerRandom();

};

#endif // INTELLIGENCE_H
