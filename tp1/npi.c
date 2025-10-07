#include "pile.h"
#include "color.h"
#include <stdarg.h>

#define MAXSTRINGSIZE 50

void translate_to_npi(char s[MAXSTRINGSIZE]);
void debug(const char *fmt, ...);
void hanoi(int n, char src, char aux, char dest, int t);


T_PileD pile1;
T_PileD pile2;
T_PileD pile3;

T_PileD Tpile1;
T_PileD Tpile2;
T_PileD Tpile3;



void debug(const char *fmt, ...) {
    // va_list args;
    // va_start(args, fmt);
    // printf(YELLOW);
    // vprintf(fmt, args);
    // printf(RESET);
    // va_end(args);
}

int main(){
    int choix = 2; // choix par défaut
    int n = 3;
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
    case 2:
        printf("Nombre de disque :");

        scanf("%d", &n);

        initPile(&pile1);
        initPile(&pile2);
        initPile(&pile3);
        
        
        for (int i = n; i >= 1; i--) {
            empiler(&pile1, '0' + i);
        }
        hanoi(n, 'A', 'B', 'C', n);

        // afficherHannoi(n);
        


    default:
        break;
    }



}

void afficherHannoi(const int t){
    
    initPile(&Tpile1);
    initPile(&Tpile2);
    initPile(&Tpile3);
    
    T_Elt e;
    printf("\n");
    // printf(YELLOW "\n");
    // afficherPile(&pile1);
    // printf("\n" RESET);

    for (int i = 0; i < t; i++)
    {
        // printf("|   |   |   |\n");
        printf("│ ");
        if (i == t - hauteur(&pile1))
        {
            // printf("1");
            depiler(&pile1, &e);
            empiler(&Tpile1, e);
            printf("%c  │", e);
        }else{
            printf("   │");
        }

        printf("│ ");
        if (i == t - hauteur(&pile2))
        {
            depiler(&pile2, &e);
            empiler(&Tpile2, e);

            printf("%c  │", e);
        }else{
            printf("   │");
        }

        printf("│ ");
        if (i == t - hauteur(&pile3))
        {
            depiler(&pile3, &e);
            empiler(&Tpile3, e);

            printf("%c  │", e);
        }else{
            printf("   │");
        }
        printf("\n");
    }

    printf("└────┴┴────┴┴────┘");
    while (!pilevide(&Tpile1))
    {
        depiler(&Tpile1, &e);
        empiler(&pile1, e);
    }
     
    while (!pilevide(&Tpile2))
    {
        depiler(&Tpile2, &e);
        empiler(&pile2, e);
    }

    while (!pilevide(&Tpile3))
    {
        depiler(&Tpile3, &e);
        empiler(&pile3, e);
    }
}


/*
Procédure HANOI(n, source, auxiliaire, destination)
    si n == 1 alors
        déplacer disque de source → destination
    sinon
        HANOI(n-1, source, destination, auxiliaire)
        déplacer disque de source → destination
        HANOI(n-1, auxiliaire, source, destination)

*/

T_PileD* findPile(char name) {
    switch (name) {
        case 'A': return &pile1;
        case 'B': return &pile2;
        case 'C': return &pile3;
        default: return NULL;
    }
}

void hanoi(int n, char src, char aux, char dest, int t) {
    
    if (n == 1) {
        T_PileD *pSrc = findPile(src);
        T_PileD *pDest = findPile(dest);
        
        T_Elt e; 
        printf("\nDéplacer disque %c de %c vers %c\n", e, src, dest);
        depiler(pSrc, &e);
        empiler(pDest, e);
        
        afficherHannoi(t);
        return;
    }

    hanoi(n-1, src, dest, aux, t);
    
    T_PileD *pSrc = findPile(src);
    T_PileD *pDest = findPile(dest);
    
    T_Elt e; 
    printf("\nDéplacer disque %c de %c vers %c\n", e, src, dest);
    // printf(YELLOW"PILE : \n");
    // afficherPile(&pile1);
    depiler(pSrc, &e);
    empiler(pDest, e);

    afficherHannoi(t);

    hanoi(n-1, aux, src, dest, t);
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
        debug("\n*** ETAPE : %c\n", s[i]);
        
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
            if (pilevide(&pile)){
                debug("Pile vide ! -> empilation \n");
                empiler(&pile, s[i]);
            }else if (sommet(&pile) == '('){
                // printf(RED "top : %c \n", sommet(&pile));
                debug("Sommet = (\n");
                empiler(&pile, s[i]);
            }else if ((sommet(&pile) == '+' || sommet(&pile) == '-' ) && (s[i] == '*' || s[i] == '/')){ //TODO : améliorer la priorité des opérateurs
                debug("Operateur PRIO \n");
                // printf("PILE ACTUEL :\n ");
                // afficherPile(&pile);
                empiler(&pile, s[i]);
            }else {
                //printf(RED "LE TOP EST  : %c\n", sommet(&pile));

                debug("Operateur NON PRIO");
                depiler(&pile, &elt);
                afficherElt(&elt);
                empiler(&pile, s[i]);
            }

            // printf(YELLOW "empilement de %c\n" RESET, s[i]);
            // empiler(&pile, s[i]);

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
                if (elt != '(' && !pilevide(&pile)){
                    printf("%c", elt);
                }else{
                    break;
                }
                // printf(RED "Ca va continuer ? %d\n" RESET, elt != '(');
            }
            // while (pilevide(&pile) == 0 && sommet(&pile) != '('){
            //     // printf("S[i]")
            //     depiler(&pile, elt);
            //     afficherElt(&elt);
            // }
        }else if ((s[i] <= '9' && s[i] >= '0') || (s[i] <= 'z' && s[i] >= 'a') || (s[i] <= 'Z' && s[i] >= 'A')){
            // printf("NUMBER\n");
            printf("%c", s[i]);
            // printf(BLUE "AFFICHAGE : %c \n" RESET, s[i]);
        }else{
            // printf(RED "Caractère %c non reconnue pour une opération !\n" RESET, s[i]);
        }


        i++;
        //printf("%d \n", i);
    }

    while(!pilevide(&pile))
    {
        depiler(&pile, &elt);
        printf("%c", elt);
    }
}


