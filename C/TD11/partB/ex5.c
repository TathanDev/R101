#include <stdlib.h>
#include <stdio.h>
#include "lib/listes.h"
#include <time.h>

int main(){
  srand(time(NULL));
  int nbAInserer;
  Noeud *tete = NULL;

  puts("Insertion de 12 nombres aléatoires entre 0 et 9");
  for (int i = 0; i < 12; i++)
  {
    nbAInserer = rand() % 6;
    ajouterFin(&tete, nbAInserer);
  }
  afficherListe(tete);
  printf("Nombre d'éléments dans la liste: %u\n", longueurListe(tete));

  supprimerNombres(&tete, 5);
  puts("Après suppression des 5:");
  afficherListe(tete);
  printf("Nombre d'éléments dans la liste: %u\n", longueurListe(tete));

  libererListe(tete);
  return 0;
}