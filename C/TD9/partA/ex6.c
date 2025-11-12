#include <stdio.h>


typedef enum { FORCE, VITESSE, INTELLIGENCE} TypePouvoir;

typedef union Pouvoir
{
  int force;
  float vitesse;
  int intelligence;
} Pouvoir;

typedef struct {
  char nom[50];
  TypePouvoir type;
  Pouvoir pouvoir;
} SuperHeros;

void afficherSuperHeros(SuperHeros hero) {
  printf("Nom: %s\n", hero.nom);
  printf("Type de pouvoir: %d\n", hero.type);
  switch (hero.type) {
    case FORCE:
      printf("Force: %d\n", hero.pouvoir.force);
      break;
    case VITESSE:
      printf("Vitesse: %.2f\n", hero.pouvoir.vitesse);
      break;
    case INTELLIGENCE:
      printf("Intelligence: %d\n", hero.pouvoir.intelligence);
      break;
  }
}


int main() {
  SuperHeros heros[3];

  for (int i = 0; i < 3; i++)
  {
    printf("Nom %d: ", i + 1);
    scanf("%s", heros[i].nom);

    switch (i) {
      case 0:
        printf("Force: ");
        scanf("%d", &heros[i].pouvoir.force);
        heros[i].type = FORCE;
        break;

      case 1:
        printf("Vitesse : ");
        scanf("%f", &heros[i].pouvoir.vitesse);
        heros[i].type = VITESSE;
        break;

      case 2:
        printf("Intelligence: ");
        scanf("%d", &heros[i].pouvoir.intelligence);
        heros[i].type = INTELLIGENCE;
        break;
    }

  }

  return 0;
}

/**
 * 1) La procédure ne modifie pas les variables latitude et longitude dans main car ce sont les paramètres qui sont modifiés.
 * Il faudrait passer les adresses des variables en utilisant des pointeurs pour que les modifications soient modifiées dans main.
 */