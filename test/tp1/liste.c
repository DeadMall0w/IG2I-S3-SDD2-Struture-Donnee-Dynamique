#include "liste.h"
#include "esL.h"
#include <stdlib.h>
#include "color.h"

// todo : mettre le bon prototype
T_maille *newMaille(T_EltL e){
    T_maille *ptr = malloc(sizeof(T_maille));
    if (ptr == NULL) {
        printf("Allocation mémoire échouée !\n");
        return NULL;
    }
    
    ptr->elt = malloc(strlen(e) + 1);
    if (ptr->elt == NULL) {
        free(ptr);
        return NULL;
    }
    

    strcpy(ptr->elt, e); 
    
    ptr->next = NULL;
    ptr->prev = NULL;

    return ptr;

}


char isEmpty(T_maille *list){
    return list == NULL;
}

void insererEnTete2(T_maille ** list, T_EltL elt){
    T_maille *m = newMaille(elt);

    if (isEmpty(*list)){
        *list = m;
    }else{
        m->next = *list;
        *list = m;        
    }
}

// todo : changer avec les bons prototypes
// todo : faire la version 1 de insertTete

int afficherListe(T_maille *list){
    printf("\n\n\n"BLUE);
    if (isEmpty(list)){
        printf(CYAN"LISTE VIDE\n"RESET);
        return 1;
    }

    T_maille *m;
    do{
        // printf("%d\n", list->elt);
        afficherEltL(&list->elt);
        list = list->next;
    } while(list != NULL);

    return 1;
}

T_maille *supprimerElement(T_EltL e, T_maille *maille){
    
    if (appartient(e, maille) == 0){
        printf(RED "n'est pas dedans ! \n" RESET);
        return maille;
    }

    //! attention si la liste est vide
    if (isEmpty(maille)){
        return maille;
    }

    // cas 1 : début
    if (CompareL(&e, &maille->elt) == 0){
        return maille->next;
    }

    // cas 2 : au milieu

    T_maille * a_supp;
    T_maille * scope = maille;
    while (!isEmpty(scope->next)){
        if (CompareL(&e, &scope->next->elt) == 0){
            a_supp = scope->next;
            if (scope->next->next == NULL){
                scope->next = NULL;
                free(a_supp->elt);
                free(a_supp);
                return maille;
            }else{ // pas nécessaire mais plus propre
                scope->next = scope->next->next;
                free(a_supp->elt);
                free(a_supp);
                return maille;
            }
        }   

        // printf("test \n");
        scope = scope->next;
    }

    return maille;
    
}



int afficherListeRec(T_maille *start){
    if (isEmpty(start)){
        return 1;
    }

    afficherEltL(&start->elt);
    afficherListeRec(start->next);
    
    return 1;
}


T_maille * trouverFinListe(T_maille * curr){
    while (curr->next != NULL){ // si le prochain est null -> on est à la fin
        curr = curr->next;
    }

    return curr;
}

T_maille *insererEnFinRec(T_EltL *e ,T_maille *list){
    if (isEmpty(list)){
        return newMaille(*e);
    } else {

        list->next = insererEnFinRec(e, list->next);
        if (list->next != NULL) {
            list->next->prev = list;
        }
        return list;
    }
}


int tailleListe(T_maille *list){
    int i = 0;
    if (isEmpty(list)){
        return 0;
    }

    T_maille *m;
    do{
        i++;
        list = list->next;
    } while(list != NULL);

    return i;   
}

int appartient(T_EltL e,T_maille *start){
    if (isEmpty(start)){
        return 0;
    }

    // afficherElt(&start->elt);
    if (CompareL(&start->elt, &e) == 0){
        return 1;
    }
    return appartient(e, start->next);
}

T_maille *insererAvecOrdre(T_EltL e, T_maille *list) {
    if (appartient(e, list)){
        return list;
    }
    T_maille *maille = newMaille(e);

    if (isEmpty(list) || CompareL(&e, &list->elt) < 0) {
        maille->next = list;
        if (list != NULL) {
            list->prev = maille;
        }
        return maille;
    }

    T_maille *curr = list;
    while (curr->next != NULL && CompareL(&e, &curr->next->elt) > 0) {
        curr = curr->next;
    }

    maille->next = curr->next;
    if (curr->next != NULL) {
        curr->next->prev = maille;
    }
    curr->next = maille;
    maille->prev = curr;

    return list;
}
