// SDA1 TP 9 PILE de TAD (PILE d'ELEMENT)
#include "pile.h"
#include "file.h"
#include "color.h"


int menu()
{

int choix;
printf("\n\n\n SDA1 TP9");
printf("\n\n\n 1 : tester mon fichier file.c");
printf("\n 2 : tester mon fichier pile.c");
printf("\n 3 : afficher et compter les permutations d'une chaine");
printf("\n 4 : afficher et compter les solutions pour un échiquier ");
printf("\n 0 :  QUITTER  ");
printf("\n votre choix ?  ");
scanf("%d",&choix);
return choix;
}

int main()
{
T_File mafile;
T_PileD mapile;
int chx;
// int taille;
//char chaine[20];

T_Elt t_temp;

do
{
chx=menu();
switch (chx)
	{
	case 1 :  
		//testez toutes vos fonctions par un jeu de test de votre choix
		//testPile(&mapile); //TP9 partie 1 : à ecrire 
		break;
	case 2 : //testez toutes vos fonctions par un jeu de test de votre choix
		// testFile(&mafile); //TP9 partie 1 : à ecrire
		
		
		printf(MAGENTA "\nDébut du test de la pile dynamique\n" RESET);

		printf(MAGENTA "\nLancement initialisation pile\n" RESET);
		initPile(&mapile);
		printf(BOLDGREEN "\nInitialisation reussie de la pile dynamique\n" RESET); 
		
		printf(MAGENTA "\nAjout des : 10.01, 20.02, 30.0, 40.4\n" RESET);
		empiler(&mapile,10.01);
		
		empiler(&mapile,20.02);
		empiler(&mapile,30.0);
		empiler(&mapile,40.4);
		printf(BOLDGREEN "\nAjout des éléments réussies\n" RESET); 
		printf(YELLOW "\nAFFICHAGE PILE (10,20,30,40)\n" RESET);
		afficherPile(&mapile);

		printf(MAGENTA "\nAjout des valeurs 50.5 à 90.9\n" RESET);
		empiler(&mapile,50.5);
		empiler(&mapile,60.6);
		empiler(&mapile,70.7);
		empiler(&mapile,80.8);
		empiler(&mapile,90.9);
		printf(BOLDGREEN "\nAjout des éléments réussies\n" RESET); 

		printf(YELLOW "\nAFFICHAGE PILE (10,20,...,90)\n" RESET);
		afficherPile(&mapile);

		printf(MAGENTA "\nDépilement de 5 éléments\n" RESET);
		depiler(&mapile, &t_temp);	
		afficherElt(&t_temp);
		depiler(&mapile, &t_temp);	
		depiler(&mapile, &t_temp);	
		depiler(&mapile, &t_temp);	
		depiler(&mapile, &t_temp);	
		printf(YELLOW "\nAFFICHAGE PILE (10,20,...,40)\n" RESET);
		afficherPile(&mapile);

		printf(MAGENTA "\nDépilement de tous les éléments restants\n" RESET);
		depiler(&mapile, &t_temp);	
		depiler(&mapile, &t_temp);	
		depiler(&mapile, &t_temp);	
		depiler(&mapile, &t_temp);	
		depiler(&mapile, &t_temp);	
		depiler(&mapile, &t_temp);	
		depiler(&mapile, &t_temp);	
		depiler(&mapile, &t_temp);	
		depiler(&mapile, &t_temp);	
		depiler(&mapile, &t_temp);	
		depiler(&mapile, &t_temp);	
		depiler(&mapile, &t_temp);	
		
		printf(YELLOW "\nAFFICHAGE PILE\n" RESET);
		afficherPile(&mapile);

		printf(BOLDGREEN "Fin du test de la pile dynamique\n" RESET);
		break; 
	case 3 : 
		//scanf("%s",chaine); //une chaine de longueur <=MAX
		//permut(&mapile,chaine); //TP9 partie 2: ecrire permut
		break;
	case 4 : 
		//scanf("%d",&taille);//taille echiquier <=MAX
		//echiquier(&mapile,taille); //TP9 partie 3: ecrire echiquier
		break;



	}
}while(chx!=0);

printf("\nau plaisir de vous revoir ...\n");
return 0;
}
