#include "pile.h"
#include "color.h"


void initPile( T_PileD * P) 
{
 P->Elts=(T_Elt *)malloc(SEUIL*sizeof(T_Elt)); 
 P->nbElts=0; //important 
 assert(P->Elts); 
//  printf(BOLDGREEN "Initialisation reussie de la pile dynamique" RESET); 
}

int pilepleine(T_PileD *P)
{ 
    int nouvelleTaille; 
    if (P->nbElts%SEUIL==0) {
        nouvelleTaille=((P->nbElts/SEUIL)+1)*SEUIL;
        P->Elts=realloc(P->Elts,nouvelleTaille*sizeof(T_Elt));
        // printf("\n==> La pile est de taille %d ",nouvelleTaille);
    } 
    assert(P->Elts); 
    return 0; 
}



int pilevide(const  T_PileD *p)
{
    if (p->nbElts == 0){
        return 1;
    }
    return 0;
}



int empiler( T_PileD *p, T_Elt e) //renvoie 0 si pile pleine, sinon 1
{
    // printf(MAGENTA "\nEmpilement de %d \n" RESET,e);
    if (pilepleine(p)){
        // printf(RED "\n==> Empilement impossible, pile pleine\n" RESET);
        return 0;
    }
    p->Elts[p->nbElts++]=e;
}



int depiler( T_PileD *P, T_Elt *pelt) //renvoie 0 si pile vide, sinon 1 
{ 
    // printf(MAGENTA "\n Depilement..." RESET);
    int nouvelleTaille; 
    if (!pilevide(P)) { 
        *pelt=P->Elts[--P->nbElts]; 
        if (P->nbElts>0 && P->nbElts%SEUIL==0) { 
            nouvelleTaille=(((P->nbElts)/SEUIL))*SEUIL;
            P->Elts=realloc(P->Elts,nouvelleTaille*sizeof(T_Elt)); 
            // printf("\n==> La pile est de taille %d ",nouvelleTaille); 
            assert(P->Elts); 
        } 
        // printf(GREEN "\n Dépilement réussie" RESET);
        
        return 1; 
    } 
    // printf(RED "\n Impossible de dépiler\n" RESET);
    return 0; 
} 



T_Elt sommet(const  T_PileD *P) // TODO : gérer si la pile est vide
{
return P->Elts[P->nbElts];
}



int hauteur(const  T_PileD *P)
{
return 0;
}


void afficherPile(  T_PileD *p)
{
    // Pour respecter le principe LIFO
    /*
    Il faut : dépiler la pile dans une pile temporaire et afficher l'élément
    Réempiler la pile depuis la pile temporaire
    ! Faire attention si c'est vide
    */

    T_PileD p_temp;
    initPile(&p_temp);
    T_Elt elt;
    while (!pilevide(p)){
        depiler(p, &elt);
        afficherElt(&elt);
        empiler(&p_temp, elt);
    }

    while (!pilevide(&p_temp)){
        depiler(&p_temp, &elt);
        empiler(p, elt);
    }

}








