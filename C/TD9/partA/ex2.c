/**
 * 1) L'union Donnee vaut 8 octets car le plus grand membre est un double.
 *
 * 2) le contenue de e1.valeur.entier sera un nombre étrange car l'union stocke un flottant et non un entier.
 *
 * 3) On utilise une énumération pour savoir ce que contient l'union à un moment donné.
 * 
 * 4) La valeur de e1.valeur.entier sera 65 car le caractère 'A' a pour code ASCII 65.
 * 
 * 6) On utilise un UNION lorsque l'on souhaite économiser de la mémoire en stockant différentes
 *    types de données dans la même zone mémoire, mais en n'utilisant qu'un seul type à la fois.
 */


#include <stdio.h>
#include <string.h>


void afficherElement(struct Element e);


typedef enum { ENTIER, FLOTTANT, CARACTERE } TypeDonnee;

union Donnee {
  int entier;
  double flottant;
  char caractere;
};

struct Element {
  TypeDonnee type;
  union Donnee valeur;
};

int main() {
  struct Element e1, e2;

  e1.type = ENTIER;
  e1.valeur.entier = 42;


  
  e2.type = FLOTTANT;
  e2.valeur.flottant = 3.14;

  printf("e1 : ");
  if (e1.type == ENTIER) {
    printf("entier = %d\n", e1.valeur.entier);
  }

  printf("e2 : ");
  if (e2.type == FLOTTANT) {
    printf("flottant = %.2lf\n", e2.valeur.flottant);
  }


  e1.type = CARACTERE;
    e1.valeur.caractere = 'A';
    printf("e1 (caractère) : %d\n", e1.valeur.entier);


  return 0;
}

void afficherElement(struct Element e) {
  switch (e.type) {
    case ENTIER:
      printf("Entier: %d\n", e.valeur.entier);
      break;
    case FLOTTANT:
      printf("Flottant: %.2lf\n", e.valeur.flottant);
      break;
    case CARACTERE:
      printf("Caractère: %c\n", e.valeur.caractere);
      break;
    default:
      printf("Type inconnu\n");
  }
}