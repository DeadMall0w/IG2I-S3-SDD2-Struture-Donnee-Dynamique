// SDA1 TP 9 PILE de TAD (PILE d'ELEMENT)
#include "pile.h"
#include "color.h"
#include "liste.h"
#include "esL.h"


int main()
{
	T_PileD mapile;

	initPile(&mapile);

	empiler(&mapile,10);
	
	empiler(&mapile,20);
	empiler(&mapile,30);
	empiler(&mapile,40);
	
	// afficherPile(&mapile);

	T_maille * liste = NULL;
	
	// T_EltL t1 = "bonjour2";

	T_EltL t;
	t.pile = (T_PileD *)malloc(sizeof(T_PileD));
	if (t.pile != NULL) {
		initPile(t.pile);
	}

	// *** Ligne de correction 1 ***
	// Allouer de l'espace et donner un nom à l'élément (nécessaire pour insererAvecOrdre)
	t.nom = (char *)malloc(50 * sizeof(char)); // Allouer la mémoire
	strcpy(t.nom, "Pile Principale"); // Initialiser le nom (ou tout autre nom)

	empiler(t.pile, 10);
	empiler(t.pile, 20);

	afficherPile(t.pile);

	printf("Premier ok ! \n");

	liste = insererAvecOrdre(t, liste);

	afficherPile(liste->elt.pile);
	// liste = insererAvecOrdre(t1, liste);

	// afficherEltL(&t);

	afficherListe(liste);



	printf("\nau plaisir de vous revoir ...\n");
	return 0;
}
