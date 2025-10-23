#include <stdio.h>

void setTo42(int **p) {
    int x = 42;
    *p = &x;  // On modifie la COPIE du pointeur
}

int main(void) {
    int *ptr = NULL;
    int y = 3;

    ptr = &y;
    printf("val = %d\n", *ptr); // --> Toujours NULL

    setTo42(&ptr);
    printf("val = %d\n", *ptr); // --> Toujours NULL
}
