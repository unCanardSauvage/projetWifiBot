#include "casealign.h"

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
    }
    else
    {
        nbRond += 1;
    }
    if (nbCroix == 3 || nbRond == 3)
    {
        victoire = true;
    }
}
