/*
Trace des printf pour l'exécution avec tab = {3, 8, 7, 1, 5} :

Tableau initial:  {3, 8, 7, 1, 5}
i = 1 iPivot = 4: {3, 8, 7, 1, 5}
i = 1 iPivot = 3: {3, 1, 7, 5, 8}
i = 2 iPivot = 3: {3, 1, 7, 5, 8}
i = 2 iPivot = 2: {3, 1, 5, 7, 8}
Partition renvoie: 2
*/

#include <stdio.h>

//#include "lib/tableaux.h"


void permuteInt(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
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
int partition(int tab[], int iMin, int iMax) {
	int iPivot = iMax;

	int i = iMin;
	while (iPivot > i) {
		if (tab[i] > tab[iPivot]) {
			permuteInt(&tab[i], &tab[iPivot]);
			iPivot--;
			permuteInt(&tab[i], &tab[iPivot]);
		} else
			i++;
		printf("i = %d iPivot = %d: ", i, iPivot);
		afficherTab(tab, iMax - iMin + 1);
	}
	return i;
}

int main() {
	int tab[] = {3, 8, 7, 1, 5};
	int taille = sizeof(tab) / sizeof(tab[0]);

	printf("Tableau initial:  ");
	afficherTab(tab, taille);

	printf("Partition renvoie: %d\n", partition(tab, 0, taille - 1));

	return 0;
}

/**
 * Trace d'exécution :
 * Tableau initial:  {3, 8, 7, 1, 5}
 * i = 1 iPivot = 4: {3, 8, 7, 1, 5}
 * i = 1 iPivot = 3: {3, 1, 7, 5, 8}
 * i = 2 iPivot = 3: {3, 1, 7, 5, 8}
 * i = 2 iPivot = 2: {3, 1, 5, 7, 8}
 * Partition renvoie: 2
 */