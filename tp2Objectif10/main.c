#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "liste.h"
#include "esL.h"
#include "color.h"
#include "pile.h"
#include "es.h"

char * strtoupper( char * dest, const char * src ) { //transforme la chaine pointee par src en son equivalent en MAJUSCULE qui sera pointé par dest
    char * result = dest;
    while( *dest++ = toupper( *src++ ) );
    return result;
}

int main()
{
    
    T_maille *maListe=NULL;
    T_eltL e2 = "test";
        afficherEltL(&e2); // Note : La fonction afficherElt attend un T_Elt*, donc &e

        maListe = insererAvecOrdre(e2, maListe); 
        
        // Initialisation correcte
        T_eltL e1 = "abc";
        
        // **CORRECTION : PASSER e1 SEUL**
        maListe = insererAvecOrdre(e1, maListe);

        afficherListe(maListe);


        T_PileD * p;
        initPile(p);
        // afficherPile(p);
        
        empiler(p,20);
		empiler(p,30);
		empiler(p,40);
        afficherPile(p);
    
    return 0;
}
