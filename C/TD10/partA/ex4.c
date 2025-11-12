#include <stdio.h>
#include <stdlib.h>

int main() {

    int taille;
    printf("Entrez la taille du tableau : ");
    scanf("%d", &taille);

    int* tableau = malloc(taille * sizeof(int));

    for (int i = 0; i < taille; i++) {
        
        printf("Entrez la valeur pour l'élément : %d\n", i);
        scanf("%d", &tableau[i]);
    }

    printf("{");
    for (int i = 0; i < taille; i++) {
        printf("%d,", tableau[i]);
        
    }
    printf("}");

    free(tableau);

    return 0;
}