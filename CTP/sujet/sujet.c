// Berquier Raphael
// Non fonctionnel
// Ne passe pas correctement après une suppression, ce qui fait que des éléments sont supprimées alors qu'ils ne devraient pas
// Comme dans le cas avec 11 cartes où le 6 de carreau n'est pas supprimé



#include<stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIGNES 5
#define COLONNES 15

typedef struct{ //4 couleurs et 8 cartes de chaque couleur = 32 cartes

    int valeur; //entre 7 et 14   14=AS  13=ROI  12=DAME  11=VALET
    int couleur; //entre 1 et 4

} T_Carte;


typedef struct maille
{
    T_Carte carte;
    struct maille *suiv;
}T_Maille;


//* <==== Prototypes de fonction
T_Maille *insererEnFinRec(T_Carte *e ,T_Maille *list);
T_Maille *newMaille(T_Carte e);
char isEmpty(T_Maille *list);
int afficherListeRec(T_Maille *start);

int appartient(T_Carte e,T_Maille *start);
int Compare(T_Carte *e, T_Carte *e2);
T_Carte creerCarte(int _valeur, int _couleur);

T_Maille *supprimerElement(T_Carte e, T_Maille *maille);

T_Maille* lireTasCartes(char *ch)
{
    T_Maille *liste=NULL;
    FILE *fic=NULL;
    T_Carte  uneCarte;



    fic=fopen(ch,"r");

    do
    {
        fread(&uneCarte,sizeof(T_Carte),1,fic);
        if (!feof(fic))
        {
            printf("\n %d--%d",uneCarte.valeur,uneCarte.couleur);
            liste = insererEnFinRec(&uneCarte, liste);
            //ici inserez chaque cartes lue EN FIN DE votre liste chainee (avec votre fonction insererEnFin)
            //! IMPORTANT !! avec insererEnFin et rien d'autre
            
        }
    }while(!feof(fic));
    fclose(fic);
    printf("\n Fin de la lecture des cartes\n");
    return liste;
}



int tailleListe(T_Maille *l)
{
    int c=0;
    while(l!=NULL) {c++;l=l->suiv;}
    return c;
}

void reussite(T_Maille *l)
{
    // printf("Fonction de la réussite !!!");
    //à ecrire



    
    unsigned char nbOperation = 0; // on suppose que l'on reste dans les contraintes de l'exercice, cad pas plus de 32 cartes
    unsigned char nbPasse = 1; // On suppose qu'il n'y aura jamais plus de 255 passages car il n'y a que 32 cartes (au max 33 passages)
    do{

        unsigned char i = 0; // index de boucle (on suppose toujours 32 cartes)
        nbOperation = 0;
        
        T_Maille *currMaille = l; // maille actuelle
        T_Maille *tmp; // maille actuelle



        T_Carte derniereCarte = l->carte;
        
        // T_Carte c = creerCarte(15, 4);
        // if (appartient(c, l) == 1){
        //     // printf("La ca")
        //     printf("\n14-4");
        //     // nbOperation++;
        // }

        do{

            // printf("\n--------\n - Examination de la carte : %d - %d \n", currMaille->carte.valeur, currMaille->carte.couleur);
            

            // * Recherche si c'est entre 2 cartes de la même couleur
            if (derniereCarte.couleur == currMaille->suiv->carte.couleur || derniereCarte.valeur == currMaille->suiv->carte.valeur){
                printf(" - Trouvé ! ->  Carte sera supprimé : %d - %d \n", currMaille->carte.valeur, currMaille->carte.couleur);
                //! Supprimer la carte
                tmp = currMaille;
                currMaille = currMaille->suiv;
                // printf("La derniere carte est : %d - %d", derniereCarte.valeur, derniereCarte.couleur); 
                nbOperation++;

                l = supprimerElement(tmp->carte, l);
                
            }else{
                derniereCarte = currMaille->carte;
                currMaille = currMaille->suiv;

            }

            
            


        } while(currMaille->suiv != NULL);


        printf("\n Fin passage n° %d \n\n", nbPasse);
        //afficherListeRec(l);
        nbPasse++;
        
    } while (nbOperation != 0); // On fait la boucle tant qu'il y a au moins une modification
    
}




////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{

    printf("Hello, world ! \n");

    T_Maille *L = NULL;
    srand( time( NULL ) );


    // T_Carte c;
    // c.couleur = 3;
    // c.valeur = 1;

    // L = insererEnFinRec(&c, L);
    // afficherListeRec(L);
    
    
     L=lireTasCartes("tas10.16"); //vous testerez les 10 fichiers de données disponibles (tas1 à tas10)
     printf("\nTAILLE AVANT=%d\n", tailleListe(L));
     reussite(L);
     printf("\n\nTAILLE APRES=%d\n", tailleListe(L));
    
    
    printf("Fin de la fonction \n");



}




//* <===== Librairies de fonctions pour la liste
T_Maille *insererEnFinRec(T_Carte *e ,T_Maille *list){
    if (isEmpty(list)){
        return newMaille(*e);
    } else {

        list->suiv = insererEnFinRec(e, list->suiv);
        // if (list->suiv != NULL) {
        //     list->suiv->prev = list;
        // }
        return list;
    }
}


T_Maille *newMaille(T_Carte e){
    T_Maille *ptr = malloc(sizeof(T_Maille));
    if (ptr == NULL) {
        printf("Allocation mémoire échouée !\n");
        return NULL;
    }
    
    ptr->carte = e;
    
    
    ptr->suiv = NULL;
    
    return ptr;

}



char isEmpty(T_Maille *list){
    return list == NULL;
}


int afficherListeRec(T_Maille *start){
    if (isEmpty(start)){
        return 1;
    }

    // afficherElt(&start->elt);
    printf(" - Carte : %d - %d \n", start->carte.valeur, start->carte.couleur);
    afficherListeRec(start->suiv);
    
    return 1;
}


int appartient(T_Carte e,T_Maille *start){
    if (isEmpty(start)){
        return 0;
    }

    // afficherElt(&start->elt);
    if (Compare(&start->carte, &e) == 0){
        return 1;
    }
    return appartient(e, start->suiv);
}


int Compare(T_Carte *e, T_Carte *e2) {
    if (e->valeur == e2->valeur && e->couleur == e2->couleur){
        return 0; // même carte
    }
    return 1;
}


T_Carte creerCarte(int _valeur, int _couleur){
    T_Carte c;
    c.valeur = _valeur;
    c.couleur = _couleur;

    return c;
}



T_Maille *supprimerElement(T_Carte e, T_Maille *maille){
    
    if (appartient(e, maille) == 0){
        printf("n'est pas dedans ! \n");
        return maille;
    }

    //! attention si la liste est vide
    if (isEmpty(maille)){
        return maille;
    }

    // cas 1 : début
    if (Compare(&e, &maille->carte) == 0){
        return maille->suiv;
    }

    // cas 2 : au milieu

    T_Maille * a_supp;
    T_Maille * scope = maille;
    while (!isEmpty(scope->suiv)){
        if (Compare(&e, &scope->suiv->carte) == 0){
            a_supp = scope->suiv;
            if (scope->suiv->suiv == NULL){
                scope->suiv = NULL;
                free(a_supp);
                return maille;
            }else{ // pas nécessaire mais plus propre
                scope->suiv = scope->suiv->suiv;
                free(a_supp);
                return maille;
            }
        }   

        // printf("test \n");
        scope = scope->suiv;
    }

    return maille;
    
}