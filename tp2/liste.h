typedef int T_elt;


// * objectif 1
typedef struct maille{
    T_elt elt;
    struct maille * next;
    struct maille * prev;
}T_maille;

#define listeVide(L) L==NULL



T_maille *newMaille(T_elt e);


// * objectif 2
int afficherListe(T_maille *);
int afficherListeRec(T_maille *);

// char isEmpty(T_maille *head);

// void addToStart(T_maille ** head, T_elt elt);

// void displayList(T_maille *head);

// void displayListRecurs(T_maille *start);


// * objectif 3
T_maille *insererEnTete(T_elt *,T_maille *);
void insererEnTete2(T_elt *,T_maille **);


//* objectif 4
T_maille * trouverFinListe(T_maille * curr);
T_maille *insererEnFinRec(T_elt *,T_maille *);


//* objectif 5
int appartient(T_elt , T_maille *);


//* objectif 6
T_maille *insererAvecOrdre(T_elt , T_maille *);


// * objectif 7
T_maille *supprimerElement(T_elt , T_maille *);


// * objectif 8
int tailleListe(T_maille *);


