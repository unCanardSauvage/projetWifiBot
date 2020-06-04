#include "intelligence.h"


Intelligence::Intelligence()
{
    cas3=false; //permet de nous indiquer une certaine situation dans le jeu
}

int Intelligence::tirage()
{
    // cette fonction va déterminer les choix de notre IA.
    int random = rand() % 100+1;
    return random;
}

void Intelligence::setGrille(int x, int y, std::string joueur)
{
    // ici, on va pouvoir mettre à jour nos grilles en fonction du joueur actif
    x--; y--;
    grille[x][y] = 1;
    if (joueur == "JOUEUR_UN")
        grilleCroix[x][y] = 1;
    else
        grilleRond[x][y] = 1;
}

void Intelligence::getGrille()
{
    // petite fonction me permettant de suivre le code, j'ai besoin d'afficher
    // des informations pour pouvoir me retrouver
    std::cout<<"grille[i][j]"<<std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j <3; j++){
            std::cout<<grille[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl<<"grilleCroix[i][j]"<<std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j <3; j++){
            std::cout<<grilleCroix[i][j]<<" ";
        }
        std::cout<<std::endl;
    }

    std::cout<<std::endl<<"grilleRond[i][j]"<<std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j <3; j++){
            std::cout<<grilleRond[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<"######################################"<<std::endl;
}

void Intelligence::initGrille()
{
    // grâce à cette fonction, on va pouvoir mettre nos cases de nos tableau à 0
    // afin de l'initialiser
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j <3; j++){
            grille[i][j] = 0;
            grilleCroix[i][j] = 0;
            grilleRond[i][j] = 0;
        }
    }
}

void Intelligence::setDifficulte(int difficulte)
{
    // ici, on va définir le seuil d'erreur de notre IA
    // 1=réussite et 100=échec
    this->difficulte = difficulte;
}

void Intelligence::getDifficulte()
{
    std::cout<<"difficulte : "<<difficulte<< std::endl;
}

void Intelligence::choix()
{
    // c'est dans cette fonction qu'on va essayer de tester les conditions nécessaires
    // pour avoir une IA qui fonctionne
    /*bool remplissage =false;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j <3; j++){
            if (grille[i][j] == 0 && !remplissage){
                grille[i][j] = 1;
                boutonX = i;
                boutonY = j;
                remplissage = true;
            }
        }
    }*/

    bool jouer=false;
    jouer = completTableau(jouer);
    if(jouer==false){
        jouer = bloquerTableau(jouer);
        std::cout << "bloquage" << std::endl;
    }
    if(jouer==false){
        jouer = jouerNormal(jouer);
        std::cout << "normal" << std::endl;
    }



    std::cout << "mouahaha" << std::endl;
}

int Intelligence::getBoutonX()
{
    return boutonX;
}

int Intelligence::getBoutonY()
{
    return boutonY;
}

bool Intelligence::bloquerTableau(bool jouer)
{
    // On vérifie si l'IA doit bloquer

    // LIGNES
    if (grilleCroix[0][0]+grilleCroix[0][1]+grilleCroix[0][2]==2)
    {
        jouer=true;
        if (grilleCroix[0][0]==0)
        {
            boutonX=0;
            boutonY=0;
        }
        if (grilleCroix[0][1]==0)
        {
            boutonX=0;
            boutonY=1;
        }
        if (grilleCroix[0][2]==0)
        {
            boutonX=0;
            boutonY=2;
        }
    }

    if (grilleCroix[1][0]+grilleCroix[1][1]+grilleCroix[1][2]==2)
    {
        jouer=true;
        if (grilleCroix[1][0]==0)
        {
            boutonX=1;
            boutonY=0;
        }
        if (grilleCroix[1][1]==0)
        {
            boutonX=1;
            boutonY=1;
        }
        if (grilleCroix[1][2]==0)
        {
            boutonX=1;
            boutonY=2;
        }
    }

    if (grilleCroix[2][0]+grilleCroix[2][1]+grilleCroix[2][2]==2)
    {
        jouer=true;
        if (grilleCroix[2][0]==0)
        {
            boutonX=2;
            boutonY=0;
        }
        if (grilleCroix[2][1]==0)
        {
            boutonX=2;
            boutonY=1;
        }
        if (grilleCroix[2][2]==0)
        {
            boutonX=2;
            boutonY=2;
        }
    }

    // COLONNES
    if (grilleCroix[0][0]+grilleCroix[1][0]+grilleCroix[2][0]==2)
    {
        jouer=true;
        if (grilleCroix[0][0]==0)
        {
            boutonX=0;
            boutonY=0;
        }
        if (grilleCroix[1][0]==0)
        {
            boutonX=1;
            boutonY=0;
        }
        if (grilleCroix[2][0]==0)
        {
            boutonX=2;
            boutonY=0;
        }
    }

    if (grilleCroix[0][1]+grilleCroix[1][1]+grilleCroix[2][1]==2)
    {
        jouer=true;
        if (grilleCroix[0][1]==0)
        {
            boutonX=0;
            boutonY=1;
        }
        if (grilleCroix[1][1]==0)
        {
            boutonX=1;
            boutonY=1;
        }
        if (grilleCroix[2][1]==0)
        {
            boutonX=2;
            boutonY=1;
        }
    }

    if (grilleCroix[0][2]+grilleCroix[1][2]+grilleCroix[2][2]==2)
    {
        jouer=true;
        if (grilleCroix[0][2]==0)
        {
            boutonX=0;
            boutonY=2;
        }
        if (grilleCroix[1][2]==0)
        {
            boutonX=1;
            boutonY=2;
        }
        if (grilleCroix[2][2]==0)
        {
            boutonX=2;
            boutonY=2;
        }
    }

    // DIAGONALES
    if (grilleCroix[0][0]+grilleCroix[1][1]+grilleCroix[2][2]==2)
    {
        jouer=true;
        if (grilleCroix[0][0]==0)
        {
            boutonX=0;
            boutonY=0;
        }
        if (grilleCroix[1][1]==0)
        {
            boutonX=1;
            boutonY=1;
        }
        if (grilleCroix[2][2]==0)
        {
            boutonX=2;
            boutonY=2;
        }
    }

    if (grilleCroix[0][2]+grilleCroix[1][1]+grilleCroix[2][0]==2)
    {
        jouer=true;
        if (grilleCroix[0][2]==0)
        {
            boutonX=0;
            boutonY=2;
        }
        if (grilleCroix[1][1]==0)
        {
            boutonX=1;
            boutonY=1;
        }
        if (grilleCroix[2][0]==0)
        {
            boutonX=2;
            boutonY=0;
        }
    }

    return jouer;
}

bool Intelligence::completTableau(bool jouer)
{
    // On vérifie si l'IA peut gagner

    // LIGNES
    if (grilleRond[0][0]+grilleRond[0][1]+grilleRond[0][2]==2)
    {
        jouer=true;
        if (grilleRond[0][0]==0)
        {
            boutonX=0;
            boutonY=0;
        }
        if (grilleRond[0][1]==0)
        {
            boutonX=0;
            boutonY=1;
        }
        if (grilleRond[0][2]==0)
        {
            boutonX=0;
            boutonY=2;
        }
    }

    if (grilleRond[1][0]+grilleRond[1][1]+grilleRond[1][2]==2)
    {
        jouer=true;
        if (grilleRond[1][0]==0)
        {
            boutonX=1;
            boutonY=0;
        }
        if (grilleRond[1][1]==0)
        {
            boutonX=1;
            boutonY=1;
        }
        if (grilleRond[1][2]==0)
        {
            boutonX=1;
            boutonY=2;
        }
    }

    if (grilleRond[2][0]+grilleRond[2][1]+grilleRond[2][2]==2)
    {
        jouer=true;
        if (grilleRond[2][0]==0)
        {
            boutonX=2;
            boutonY=0;
        }
        if (grilleRond[2][1]==0)
        {
            boutonX=2;
            boutonY=1;
        }
        if (grilleRond[2][2]==0)
        {
            boutonX=2;
            boutonY=2;
        }
    }

    // COLONNES
    if (grilleRond[0][0]+grilleRond[1][0]+grilleRond[2][0]==2)
    {
        jouer=true;
        if (grilleRond[0][0]==0)
        {
            boutonX=0;
            boutonY=0;
        }
        if (grilleRond[1][0]==0)
        {
            boutonX=1;
            boutonY=0;
        }
        if (grilleRond[2][0]==0)
        {
            boutonX=2;
            boutonY=0;
        }
    }

    if (grilleRond[0][1]+grilleRond[1][1]+grilleRond[2][1]==2)
    {
        jouer=true;
        if (grilleRond[0][1]==0)
        {
            boutonX=0;
            boutonY=1;
        }
        if (grilleRond[1][1]==0)
        {
            boutonX=1;
            boutonY=1;
        }
        if (grilleRond[2][1]==0)
        {
            boutonX=2;
            boutonY=1;
        }
    }

    if (grilleRond[0][2]+grilleRond[1][2]+grilleRond[2][2]==2)
    {
        jouer=true;
        if (grilleRond[0][2]==0)
        {
            boutonX=0;
            boutonY=2;
        }
        if (grilleRond[1][2]==0)
        {
            boutonX=1;
            boutonY=2;
        }
        if (grilleRond[2][2]==0)
        {
            boutonX=2;
            boutonY=2;
        }
    }

    // DIAGONALES
    if (grilleRond[0][0]+grilleRond[1][1]+grilleRond[2][2]==2)
    {
        jouer=true;
        if (grilleRond[0][0]==0)
        {
            boutonX=0;
            boutonY=0;
        }
        if (grilleRond[1][1]==0)
        {
            boutonX=1;
            boutonY=1;
        }
        if (grilleRond[2][2]==0)
        {
            boutonX=2;
            boutonY=2;
        }
    }

    if (grilleRond[0][2]+grilleRond[1][1]+grilleRond[2][0]==2)
    {
        jouer=true;
        if (grilleRond[0][2]==0)
        {
            boutonX=0;
            boutonY=2;
        }
        if (grilleRond[1][1]==0)
        {
            boutonX=1;
            boutonY=1;
        }
        if (grilleRond[2][0]==0)
        {
            boutonX=2;
            boutonY=0;
        }
    }

    return jouer;
}

void Intelligence::jouerRandom()
{
    bool verif=false;
    while(verif==false){
        int randomx = rand() %3;
        int randomy = rand() %3;
        if(grille[randomx][randomy]==0){
            boutonX=randomx;
            boutonY=randomy;
            verif=true;
        }
    }
    std::cout<<"yolooooo"<<std::endl;
}

bool Intelligence::jouerNormal(bool jouer)
{
    // ici, on va déterminer ce que notre IA va faire tant que deux jetons de même type
    // ne sont pas sur la même ligne/colonne/diagonale

    int varAleatoire;
    varAleatoire=tirage();
    // compter le nombre de croix, c'est aussi compter le nombre de tours
    int sommeCroix = 0;
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            sommeCroix=sommeCroix+grilleCroix[i][j];
        }
    }

    if (sommeCroix==1){
        //si le joueur pose dans les angles
        if (grilleCroix[0][0]==1 || grilleCroix[0][2]==1
                || grilleCroix[2][0]==1 || grilleCroix[2][2]==1){
            //la IA a fort intérêt à vite bloquer le centre
            //augmentons la marge de réussite...
            if (varAleatoire<difficulte+((100-difficulte)/2)){
                boutonX=1;
                boutonY=1;
            }
            else{
                 jouerRandom();
            }
        }

        //si le joueur pose au milieu
        if(grilleCroix[1][1]==1){
            //de même, si la IA ne joue pas sur un angle, elle rique de perdre
            //mais ne lui donnons pas un coup de pouce dans ce cas de figure,
            //la victoire du joueur est moins évidente et notre IA peut toujours
            //bien jouer en posant sa pièce aléatoirement
            if (varAleatoire<difficulte){
                int choisir=rand()%4;
                if(choisir==0){
                    boutonX=0;
                    boutonY=0;
                }
                if(choisir==1){
                    boutonX=0;
                    boutonY=2;
                }
                if(choisir==2){
                    boutonX=2;
                    boutonY=2;
                }
                if(choisir==3){
                    boutonX=2;
                    boutonY=0;
                }
            }
            else{
                jouerRandom();
            }

        }
        //si le joueur joue sur un des côtés, angles exclus
        //ce cas là est moins évident à traîter. A ma connaissance, le plus
        //judicieux est de poser son rond sur le côté opposé, en face de la croix
        //du joueur, et ainsi, tenter un coup au troisième tour si toutes les conditions
        //sont réunies
        //si la IA joue autre part, si les deux camps jouent la défensive, il y aura égalité

        if(grilleCroix[0][1]==1 || grilleCroix[1][0]==1
                || grilleCroix[2][1]==1 || grilleCroix[1][2]==1){
            cas3=true;
            if(varAleatoire<difficulte){
                if(grilleCroix[0][1]==1){
                    boutonX=2;
                    boutonY=1;
                }
                if(grilleCroix[2][1]==1){
                    boutonX=0;
                    boutonY=1;
                }
                if(grilleCroix[1][0]==1){
                    boutonX=1;
                    boutonY=2;
                }
                if(grilleCroix[1][2]==1){
                    boutonX=1;
                    boutonY=0;
                }
            }
            else{
                jouerRandom();
            }
        }
    }

    if (sommeCroix==2){
        //bon, là ça devient compliqué à tout visualiser. On doit repartir des
        //hypothèses précédentes, en considèrant que le joueur ait posé 2 croix.
        //on va pouvoir considèrer que la IA peut déjà être contrainte de bloquer
        //l'adversaire. Mais elle peut toujours avoir des coups intéressants, notamment
        //dans le troisième cas traité pour le premier tour
        if(cas3==true){
            if(grilleCroix[1][1]==1){
                int choisir=rand()%2;
                if(varAleatoire<difficulte){
                    if(grilleCroix[0][1]==1){
                        if(choisir==0){
                            boutonX=0;
                            boutonY=0;
                        }
                        else{
                            boutonX=0;
                            boutonY=2;
                        }
                    }
                    if(grilleCroix[2][1]==1){
                        if(choisir==0){
                            boutonX=2;
                            boutonY=0;
                        }
                        else{
                            boutonX=2;
                            boutonY=2;
                        }
                    }
                    if(grilleCroix[1][0]==1){
                        if(choisir==0){
                            boutonX=0;
                            boutonY=0;
                        }
                        else{
                            boutonX=2;
                            boutonY=0;
                        }
                    }
                    if(grilleCroix[1][2]==1){
                        if(choisir==0){
                            boutonX=0;
                            boutonY=2;
                        }
                        else{
                            boutonX=2;
                            boutonY=2;
                        }
                    }
                }
                else{
                    jouerRandom();
                }
            }
            else{
                jouerRandom();
                cas3=false;
            }
        }
        else{
            jouerRandom();
        }
    }

    if (sommeCroix==3){
        if(cas3==true){
            if(varAleatoire<difficulte){
                if(grilleCroix[0][1]==1 && grilleRond[0][0]==1
                        && grille[0][1]==grille[0][2]){
                    boutonX=2;
                    boutonY=0;
                }
                if(grilleCroix[0][1]==1 && grilleRond[0][2]==1
                        && grille[2][1]==grille[2][2]){
                    boutonX=2;
                    boutonY=2;
                }
                if(grilleCroix[2][1]==1 && grilleRond[0][2]==1
                        && grille[0][0]==grille[0][1]){
                    boutonX=0;
                    boutonY=0;
                }
                if(grilleCroix[2][1]==1 && grilleRond[2][2]==1
                        && grille[2][0]==grille[2][1]){
                    boutonX=2;
                    boutonY=0;
                }
                if(grilleCroix[1][0]==1 && grilleRond[0][0]==1
                        && grille[0][2]==grille[0][1]){
                    boutonX=0;
                    boutonY=2;
                }
                if(grilleCroix[1][0]==1 && grilleRond[2][0]==1
                        && grille[2][2]==grille[2][1]){
                    boutonX=2;
                    boutonY=2;
                }
                if(grilleCroix[2][1]==1 && grilleRond[2][0]==1
                        && grille[1][0]==grille[0][0]){
                    boutonX=0;
                    boutonY=0;
                }
                if(grilleCroix[2][1]==1 && grilleRond[2][2]==1
                        && grille[1][2]==grille[0][2]){
                    boutonX=0;
                    boutonY=2;
                }
                else{
                    jouerRandom();
                }
            }
            else{
                jouerRandom();
            }
        }
        else{
            jouerRandom();
        }
    }

    if(sommeCroix>3){
        jouerRandom();
    }

    return jouer=true;
}
