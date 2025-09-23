#include "pile.h"
#include "color.h"

#define MAXSTRINGSIZE 50

void translate_to_npi(char s[MAXSTRINGSIZE]);




int main(){
    int choix;
    printf(BOLDYELLOW "Que voulez vous faire ?\n" RESET);
    printf(YELLOW "1) traduire en notation inverse polonaise\n" RESET);

    scanf("%d",&choix);
    

    switch (choix)
    {
    case  1:
        printf("Entrez la chaîne à traduire :");
        char s[MAXSTRINGSIZE];

        scanf("%s", s);

        translate_to_npi(s);
        
        break;
    
    default:
        break;
    }



}
/*

Tant qu'il y a des caractères à lire sur l’expression à traduire { 
 1. Prendre le caractère suivant de l’expression 
 2. Si c'est un opérande alors 
 l’afficher à l’écran 
 sinon Si c'est une parenthèse ouvrante alors 
 empiler cette parenthèse 
 sinon Si c'est un opérateur, alors 
 1. Si la pile est vide alors empiler l'opérateur 
 2. Si le sommet de la pile est une parenthèse 
 ouvrante alors empiler l'opérateur 
 3. Si l'opérateur est prioritaire sur celui au sommet 
 de la pile alors empiler l'opérateur 
 sinon 
 dépiler l'opérateur et l’afficher à l’écran 
 empilez l'opérateur courant 
 5. Si c'est une parenthèse fermante, dépiler et afficher les opérateurs jusqu'à ce que l'on 
rencontre la parenthèse ouvrante qui sera dépilée aussi. 
23 
} 
Enlever tous les opérateurs restants et les placer sur le fichier de sortie.*/


void translate_to_npi(char s[MAXSTRINGSIZE]){
    printf(YELLOW "Transcription de " BOLDYELLOW "%s" RESET YELLOW " en cours...\n" RESET, s);
    int i = 0;

    T_PileD pile;
    T_Elt elt;
    initPile(&pile);
    afficherPile(&pile);



    while (s[i] != '\0' && i < MAXSTRINGSIZE-1){
        // printf("CHAR %c\n", s[i]);
        
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
            // printf("OPERATEUR \n");
            // if (pilevide(&pile)){
            //     // printf("Pile vide !\n");
            //     empiler(&pile, s[i]);
            // }else if (sommet(&pile) == '('){
            //     // printf("Sommet : (\n");
            //     empiler(&pile, s[i]);
            // }else if (s[i] == '+' || s[i] == '-'){ //TODO : améliorer la priorité des opérateurs
            //     // printf("Operateur noon prio \n");
            //     // printf("PILE ACTUEL :\n ");
            //     // afficherPile(&pile);
            //     depiler(&pile, &elt);
            //     afficherElt(&elt);
            //     empiler(&pile, s[i]);
            // }else {
            //     empiler(&pile, s[i]);
            // }

            // printf(YELLOW "empilement de %c\n" RESET, s[i]);
            empiler(&pile, s[i]);

        }else if(s[i] == '('){
            // printf(YELLOW "empilement de %c\n" RESET, s[i]);
            empiler(&pile, '(');
        }else if(s[i] == ')'){
            // printf(RED "Ca ferme !\n" RESET);
            // printf("Taille pile : %d\n", pile.nbElts);
            // printf(YELLOW"\nPile : \n" RESET);
            // afficherPile(&pile);
            // printf("\n\n");
            
            while (1)
            {
                // printf("\nDEPILEMENT \n");
                depiler(&pile, &elt);
                // printf("ELT : \n");
                if (elt == '('){
                    break;
                }
                printf("%c", elt);
                // printf(RED "Ca va continuer ? %d\n" RESET, elt != '(');
            }
            // while (pilevide(&pile) == 0 && sommet(&pile) != '('){
            //     // printf("S[i]")
            //     depiler(&pile, elt);
            //     afficherElt(&elt);
            // }
        }else if (s[i] <= '9' && s[i] >= '0'){
            // printf("NUMBER\n");
            printf("%c", s[i]);
            // printf(BLUE "AFFICHAGE : %c \n" RESET, s[i]);
        }else{
            // printf(RED "Caractère %c non reconnue pour une opération !\n" RESET, s[i]);
        }




        i++;
    }

    depiler(&pile, &elt);
    printf("%c", elt);

}


