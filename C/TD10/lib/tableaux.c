#include <stdio.h>
#include <stdlib.h>
#include "tableaux.h"

/**
 * @brief Alloue et initialise un tableau dynamique d'entiers de taille
 * spécifiée, en demandant à l'utilisateur de saisir chaque élément.
 *
 * Cette fonction alloue dynamiquement un tableau d'entiers de la taille
 * demandée, puis invite l'utilisateur à entrer chaque élément du tableau via
 * l'entrée standard. En cas d'échec d'allocation mémoire, un message d'erreur
 * est affiché sur la sortie d'erreur standard et le programme se termine avec
 * un code d'erreur (1).
 *
 * @param taille La taille du tableau à allouer (doit être un entier strictement
 * positif). Si taille <= 0, le comportement est indéfini.
 *
 * @return int* Un pointeur vers le premier élément du tableau alloué et
 * initialisé. L'appelant est responsable de libérer la mémoire allouée avec
 * `free()` pour éviter les fuites mémoire.
 *
 * @note
 * - L'utilisateur doit entrer des valeurs entières valides pour chaque élément.
 * - Le tableau retourné doit être libéré par l'appelant une fois qu'il n'est
 * plus nécessaire.
 * - En cas d'échec de l'allocation mémoire, le programme se termine
 * immédiatement.
 *
 * @example
 *   // Exemple d'utilisation :
 *   int* monTableau = tableauScanfTaille(5);
 *   // Utilisation du tableau...
 *   free(monTableau); // Libération obligatoire de la mémoire
 */
int* tableauScanfTaille(int taille) {
    int* tableau = malloc(taille * sizeof(int));
    if (tableau == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        exit(1);
    }

    for (int i = 0; i < taille; i++) {
        printf("Entrez la valeur pour l'élément %d : ", i);
        scanf("%d", &tableau[i]);
    }

    return tableau;
}

void afficherTab(int* tab, int taille) {
    printf("{");
    for (int i = 0; i < taille; i++) {
        printf("%d", tab[i]);
        if (i < (taille - 1)) {
            printf(", ");
        }
    }
    printf("}\n");
}
