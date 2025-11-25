#include "esL.h"

// * objectif 1
typedef struct maille{
    T_EltL elt;
    struct maille * next;
    struct maille * prev;
}T_maille;

#define listeVide(L) L==NULL



T_maille *newMaille(T_EltL e);


// * objectif 2
int afficherListe(T_maille *);
int afficherListeRec(T_maille *);

// char isEmpty(T_maille *head);

// void addToStart(T_maille ** head, T_EltL elt);

// void displayList(T_maille *head);

// void displayListRecurs(T_maille *start);


// * objectif 3
T_maille *insererEnTete(T_EltL *,T_maille *);
void insererEnTete2(T_maille **list, T_EltL elt);


//* objectif 4
T_maille * trouverFinListe(T_maille * curr);
T_maille *insererEnFinRec(T_EltL *,T_maille *);


//* objectif 5
int appartient(T_EltL , T_maille *);


//* objectif 6
T_maille *insererAvecOrdre(T_EltL , T_maille *);


// * objectif 7
T_maille *supprimerElement(T_EltL , T_maille *);


// * objectif 8
int tailleListe(T_maille *);


