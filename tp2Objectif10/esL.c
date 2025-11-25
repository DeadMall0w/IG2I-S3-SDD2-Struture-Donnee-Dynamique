#include "esL.h"
#include <string.h>



// lorsque T_ELt est un int  (c'est le case de notre TP)  
// void saisirElt(T_Elt *e)
// {
// scanf("%d",e);
// }
// void afficherElt(T_Elt *e)
// {
// printf("%d\n",*e);
// }
// void affecterElt(T_Elt *d,T_Elt *s)
// {
// *d=*s;
// }



// int Compare(T_Elt *e, T_Elt *e2) {
//     if (*e < *e2)
//         return -1;
//     else if (*e > *e2)
//         return 1;
//     else
//         return 0;
// }






// lorsque T_ELt est un char  (peut être un jour)

// void saisirElt(T_Elt *e)
// {
// scanf("%c",e);
// }
// void afficherElt(T_Elt *e)
// {
// printf("\n%c",*e);
// }

// void affecterElt(T_Elt *d,T_Elt *s)
// {
// *d=*s;
// }










// lorsque T_ELt est une chaine (peut être un jour)


void saisirEltL(T_EltL *e)
{
scanf("%s",*e);
}
void afficherEltL(T_EltL *e)
{
printf("\n%s",*e);
}


void affecterEltL(T_EltL *d,T_EltL *s)
{
strcpy(*d,*s);
}

int CompareL(T_EltL *e, T_EltL *e2) {
    return strcmp(*e, *e2);
}