#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/tableaux.h"

int main() {
    int* tableau = tableauScanfTaille(10);

    afficherTab(tableau, 10);

    tableau = realloc(tableau, 5 * sizeof(int));

    for(int i = 10; i < 20; i++) {
        tableau[i] = -1;
    }
    afficherTab(tableau, 20);

}