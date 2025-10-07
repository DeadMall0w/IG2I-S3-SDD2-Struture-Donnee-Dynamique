#include <stdio.h>
#include "liste.h"
#include "helper.h"



int main() {
    printf("Hello, world ! \n");
    T_maille *liste = NULL;


     LOG(INFO, "Programme démarré");
    LOG(DEBUG_LEVEL, "Valeur x = %d", 42);
    LOG(WARNING, "Attention, x vaut %d", 42);
    LOG(ERROR, "Une erreur est survenue !");
    
    DEBUG = 0; // désactivation des messages DEBUG
    LOG(DEBUG_LEVEL, "Cette ligne ne s'affichera pas");

    return 0;


}
