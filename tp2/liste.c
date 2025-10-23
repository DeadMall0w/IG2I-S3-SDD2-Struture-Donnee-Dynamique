#include "liste.h"
#include "es.h"
#include <stdlib.h>
#include "color.h"

// todo : mettre le bon prototype
T_maille *newMaille(T_elt e){
    T_maille *ptr = malloc(sizeof(T_maille));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    // ptr->elt = e;
    affecterElt(&ptr->elt, &e);
    ptr->next = NULL;
    ptr->prev = NULL;

}


char isEmpty(T_maille *list){
    return list == NULL;
}

void addToStart(T_maille ** list, T_elt elt){
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

void displayList(T_maille *list){
    printf("\n\n\n"BLUE);
    if (isEmpty(list)){
        printf(CYAN"LISTE VIDE\n"RESET);
        return;
    }

    T_maille *m;
    do{
        // printf("%d\n", list->elt);
        afficherElt(&list->elt);
        list = list->next;
    } while(list != NULL);
}



void displayListRecurs(T_maille *start){
    if (isEmpty(start)){
        return;
    }

    afficherElt(&start->elt);
    displayListRecurs(start->next);
}


T_maille * trouverFinListe(T_maille * curr){
    while (curr->next != NULL){ // si le prochain est null -> on est à la fin
        curr = curr->next;
    }

    return curr;
}

T_maille *insererEnFin(T_elt *e ,T_maille *list){
    T_maille *m = newMaille(*e);

    // derniere maille : 
    T_maille der = trouverFinListe()

    if (isEmpty(*list)){
        *list = m;
    }else{
        m->next = *list;
        *list = m;        
    }
}