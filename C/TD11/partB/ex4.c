#include <stdlib.h>
#include <stdio.h>
#include "lib/listes.h"
#include <time.h>

int main() {
  srand(time(NULL));
  int nbAInserer;
  Noeud* tete = NULL;

  puts("Insertion de 7 nombres aléatoires entre 0 et 9");
  for (int i = 0; i < 7; i++) {
    nbAInserer = rand() % 10;
    ajouterFin(&tete, nbAInserer);
    printf("Ajout de %d\n", nbAInserer);
    afficherListe(tete);
  }
  puts("Libération de la mémoire");
  libererListe(tete);
  return 0;
}