#include <stdio.h>
#include <stdlib.h>
#include "lib/tablistes.h"

/**
 * Cette exercise fut réaliser sur mon pc portable ou le c ne fonctionne pas ce qui veut dire que je n'ai pas pus tésté le code.
 * Il est possible qu'il y ai des erreurs de syntaxes ou autres.
 *
 */

int main() {
  // Initialisation directe de la structure dans le main
  TabListe maListe;
  maListe.taille = 0;  // Tableau initialement vide
  // Affichage
  printf("Liste vide de départ: ");
  afficherTabListe(&maListe);
  // Longueur
  printf("Taille actuelle : %d\n", maListe.taille);

  // Ajout d'éléments en fin
  ajouterElt(&maListe, 10);
  ajouterElt(&maListe, 20);
  ajouterElt(&maListe, 30);

  // Affichage
  printf("Liste après 3 ajouts en fin de liste: ");
  afficherTabListe(&maListe);
  // Longueur
  printf("Taille actuelle : %d\n", maListe.taille);

  // Suppression en fin
  retirerElt(&maListe);
  printf("Liste après suppression en fin: ");
  afficherTabListe(&maListe);
  // Longueur
  printf("Taille actuelle : %d\n", maListe.taille);

  // Ajout à un indice
  insererElt(&maListe, 1, 15);
  printf("Liste après ajout à l'indice 1: ");
  afficherTabListe(&maListe);
  printf("Taille actuelle : %d\n", maListe.taille);

  // Suppression à un indice
  supprimerElt(&maListe, 0);
  printf("Liste après suppression à l'indice 0: ");
  afficherTabListe(&maListe);
  printf("Taille actuelle : %d\n", maListe.taille);

  return 0;
}