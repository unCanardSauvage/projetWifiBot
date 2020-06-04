#ifndef CASEALIGN_H
#define CASEALIGN_H
#include <string>

class CaseAlign
{
private:
    int nbCroix;
    int nbRond;
public:
    CaseAlign();
    void reset();
    void ajoutMarque(std::string joueur, bool &victoire);
    int getCroix(); // retourne le nombre de croix
    int getRond(); // retourne le nombre de ronds

};

#endif // CASEALIGN_H
