
#ifndef ESL_H
#define ESL_H


#include <stdio.h>
#include <string.h>
#include "pile.h"
// typedef char *T_EltL; //TAD
// typedef char *T_eltL; //! car j'ai oublié pas mal de majuscule

typedef struct elt{
    T_PileD * pile;
    char * nom;
}T_EltL;

// ou
//typedef char T_chaine[50];
//typedef T_chaine T_Elt; //TAD
// ou
// typedef char  T_Elt; //TAD


void saisirEltL(T_EltL *);
void afficherEltL(T_EltL *);
void affecterEltL(T_EltL *,T_EltL *);
int CompareL(T_EltL *e, T_EltL *e2);




#endif

