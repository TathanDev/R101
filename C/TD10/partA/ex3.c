#include <stdio.h>
#include <stdlib.h>

int main() {
  int taille = 20;
  int* tableau = malloc(taille * sizeof(int));

  for (int i = 0; i < taille; i++) {
    tableau[i] = i * i;
  }

  for (int i = 0; i < taille; i++) {
    printf("tableau[%d] = %d\n", i, tableau[i]);
  }

  return 0;
}

/**
 * 2) Ce programme alloue dynamiquement un tableau de 20 entiers, remplit ce tableau avec les carrés des indices, puis affiche chaque élément du tableau.
 * 3) Le problème majeur avec ce code est qu'il y a une fuite de mémoire car la mémoire allouée avec malloc n'est jamais libérée avec free.
 * 4) Pour corriger le problème, il faut ajouter un appel à free(tableau) a la fin de la fonction main.
 */