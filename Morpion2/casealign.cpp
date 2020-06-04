#include "casealign.h"
#include <iostream>

CaseAlign::CaseAlign()
{
    nbCroix = 0;
    nbRond = 0;
}
void CaseAlign::reset()
{
    nbCroix = 0;
    nbRond = 0;
}
void CaseAlign::ajoutMarque(std::string joueur,bool &victoire)
{
    if(joueur == "JOUEUR_UN")
    {
        nbCroix += 1;
        std::cout << "nbCroix = " << nbCroix << std::endl;
    }
    else
    {
        nbRond += 1;
        std::cout << "nbRond = " << nbRond << std::endl;
    }
    if (nbCroix == 3 || nbRond == 3)
    {
        victoire = true;
    }
}

int CaseAlign::getCroix()
{
    return nbCroix;
}

int CaseAlign::getRond()
{
    return nbRond;
}


