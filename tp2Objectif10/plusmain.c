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

int mainBis() {
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

        printf(YELLOW"5 - Vérifier si un élément est dans la liste\n" RESET);

        printf(YELLOW"6 - Ajouter un élément dans l'ordre\n" RESET);

        printf(YELLOW"7 - Supprimer un élément\n" RESET);

        printf(YELLOW"8 - Taille de la liste\n" RESET);

        printf(GREEN"10 - Fonction de test\n"RESET);


 
        T_elt e2 = "test";
        afficherElt(&e2); // Note : La fonction afficherElt attend un T_Elt*, donc &e

        maListe = insererAvecOrdre(e2, maListe); 
        
        // Initialisation correcte
        T_elt e1 = "abc";
        
        // **CORRECTION : PASSER e1 SEUL**
        maListe = insererAvecOrdre(e1, maListe);

        afficherListe(maListe);
        scanf("%d", &menu);

        switch (menu)
        {
        case 1:
            printf(MAGENTA"AFFICHAGE DE LA LISTE : \n"RESET);
            afficherListe(maListe);
            break;
        case 2:
            printf(MAGENTA"AFFICHAGE DE LA LISTE : \n"RESET);
            afficherListeRec(maListe);
            break;
        case 3:
            printf(MAGENTA"Veuillez entrer un élément : "RESET);
            saisirElt(e);

            insererEnFinRec(e, maListe);
            break;
        case 4:
            printf(MAGENTA"Veuillez entrer un élément : "RESET);
            saisirElt(e);

            insererEnTete2(&maListe, *e);                        
            break;
        case 5:
            printf(MAGENTA"Veuillez entrer un élément : "RESET);
            saisirElt(e);

            int v = appartient(*e, maListe);
            if (v == 1){
                printf(GREEN "Element présent \n \n" RESET);
            }else{
                printf(RED "Element non présent \n\n" RESET);

            }
            break;
        case 6:
            printf(MAGENTA"Veuillez entrer un élément : "RESET);
            saisirElt(e);

            maListe = insererAvecOrdre(*e, maListe);
            break;
        case 7:
            printf(MAGENTA"Veuillez entrer un élément : "RESET);
            saisirElt(e);

            maListe = supprimerElement(*e, maListe);
            break;
        case 8:

            printf("Taille : %d", tailleListe(maListe));
            break;
        case 10:
                                  
            // *e = 0;
            // maListe = insererAvecOrdre(*e, maListe);                        
            // *e = 5;
            // maListe = insererAvecOrdre(*e, maListe);                        
            // *e = 10;
            // maListe = insererAvecOrdre(*e, maListe);                        
            // *e = 15;
            // maListe = insererAvecOrdre(*e, maListe);                        
            
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
