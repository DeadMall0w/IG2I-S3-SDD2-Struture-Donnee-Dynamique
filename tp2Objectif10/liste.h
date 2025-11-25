#include "esL.h"

// * objectif 1
typedef struct maille{
    T_eltL elt;
    struct maille * next;
    struct maille * prev;
}T_maille;

#define listeVide(L) L==NULL



T_maille *newMaille(T_eltL e);


// * objectif 2
int afficherListe(T_maille *);
int afficherListeRec(T_maille *);

// char isEmpty(T_maille *head);

// void addToStart(T_maille ** head, T_eltL elt);

// void displayList(T_maille *head);

// void displayListRecurs(T_maille *start);


// * objectif 3
T_maille *insererEnTete(T_eltL *,T_maille *);
void insererEnTete2(T_maille **list, T_eltL elt);


//* objectif 4
T_maille * trouverFinListe(T_maille * curr);
T_maille *insererEnFinRec(T_eltL *,T_maille *);


//* objectif 5
int appartient(T_eltL , T_maille *);


//* objectif 6
T_maille *insererAvecOrdre(T_eltL , T_maille *);


// * objectif 7
T_maille *supprimerElement(T_eltL , T_maille *);


// * objectif 8
int tailleListe(T_maille *);


