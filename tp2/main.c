#include <stdio.h>
#include "liste.h"
#include "es.h"
#include "color.h"


// todo : 
/* 
Terminer de renommer les fonctions avec le bon prototype
Faire ajouter en tete v1
Faire ajouter en fin des 2 facons
Faire la suite des objectifs
*/
void Test();

int main() {
    printf("Hello, world ! \n\n");
    
    T_maille *maListe = NULL;

    int menu;
    T_elt *e;
    do
    {
        printf(RESET"\n\n<------- MENU --------->\n");
        printf(RED"0 - Quitter\n"RESET);

        printf(YELLOW"1 - afficher la liste\n"RESET);
        printf(YELLOW"2 - afficher la liste (récursivement)\n"RESET);

        printf(YELLOW"3 - Ajouter un élément à la fin [Pas encore fait]\n");
        printf(YELLOW"4 - Ajouter un élément au début\n");

        printf(GREEN"10 - Fonction de test\n"RESET);

        scanf("%d", &menu);

        switch (menu)
        {
        case 1:
            printf(MAGENTA"AFFICHAGE DE LA LISTE : \n"RESET);
            displayList(maListe);
            break;
        case 2:
            printf(MAGENTA"AFFICHAGE DE LA LISTE : \n"RESET);
            displayListRecurs(maListe);
            break;
        case 3:
            printf(MAGENTA"Veuillez entrer un élément : "RESET);
            saisirElt(e);

            break;
            //addToEnd(&maListe, *e);
        case 4:
            printf(MAGENTA"Veuillez entrer un élément : "RESET);
            saisirElt(e);

            addToStart(&maListe, *e);                        
            break;
        case 10:
            // Test();
            // printf()
            // printf("pile vide (1) : %d\n", isEmpty(maListe));
            // T_maille *m = newMaille(0);
            // displayListRecurs(maListe);
            // // maListe = m; // on pointe vers le 1 el (10)
            // // printf(BLUE"Adresse pointé maListe : %p\n"RESET, maListe);
            // addToStart(&maListe, 10);
            // displayListRecurs(maListe);

            // // printf("pile vide (0) : %d\n", isEmpty(maListe));
            // addToStart(&maListe, 20);
            // displayListRecurs(maListe);

            //maListe = m;
            // printf("pile vide (0) : %d\n", isEmpty(maListe));

            // afficher liste

            break;
        default:
            break;
        }


    } while (menu != 0);
    






     return 0;
}


void Test(){
    // T_Elt e;
    // //saisirElt(&e);
    // //afficherElt(&e);
   
    // T_maille* tete = newMaille(0);

    // printf("e: %d \n", tete->elt);
}
