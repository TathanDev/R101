#include <stdio.h>


typedef struct {
  int latitude;
  int longitude;
} Coordonnees;

void goSouthEast(Coordonnees *coord) {
  coord->latitude = coord->latitude - 1;  // Décrémente la latitude
  coord->longitude = coord->longitude + 1;  // Incrémente la longitude
}

Coordonnees goSouthEast2(Coordonnees coord) {

  coord.latitude = coord.latitude - 1;  // Décrémente la latitude
  coord.longitude = coord.longitude + 1;  // Incrémente la longitude
  return coord;
}

int main() {
  Coordonnees position = {43, 7};
  printf("Coordonnées initiales: (%d, %d)\n", position.latitude, position.longitude);

  // appel de la fonction
  position = goSouthEast2(position);

  printf("Coordonnées finales: (%d, %d)\n", position.latitude, position.longitude);
  return 0;
}

/**
 * 1) La procédure ne modifie pas les variables latitude et longitude dans main car ce sont les paramètres qui sont modifiés.
 * Il faudrait passer les adresses des variables en utilisant des pointeurs pour que les modifications soient modifiées dans main.
 */