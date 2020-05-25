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
};

#endif // CASEALIGN_H
