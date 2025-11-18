#include <stdlib.h>
#include <stdio.h>
#include "listes.h"

void afficherListe(Noeud* tete) {
  Noeud* courant = tete;
  while (courant != NULL) {
      printf("%d -> ", courant->valeur);
      courant = courant->suivant;
  }
  printf("NULL\n");
}

unsigned longueurListe(Noeud* tete) {
  unsigned longueur = 0;
  Noeud* courant = tete;
  while (courant != NULL) {
      longueur++;
      courant = courant->suivant;
  }
  return longueur;
}

Noeud* creerListeDunTab(int tab[], int taille) {
  if(taille <= 0) {
      return NULL;
  }
  Noeud* tete = malloc(sizeof(Noeud));
  if(tete == NULL) {
      printf("Erreur d'allocation mémoire!\n");
      exit(EXIT_FAILURE);
  }
  tete->valeur = tab[0];
  tete->suivant = NULL;

  Noeud* courant = tete;
  for(int i = 1; i < taille; i++) {
      Noeud* nouveau = malloc(sizeof(Noeud));
      if(nouveau == NULL) {
          printf("Erreur d'allocation mémoire!\n");
          exit(EXIT_FAILURE);
      }
      nouveau->valeur = tab[i];
      courant->suivant = nouveau;
      courant = nouveau;
  }
  return tete;
}

void libererListe(Noeud* tete) {
  Noeud* courant = tete;
  while(courant != NULL) {
      Noeud* temp = courant;
      courant = courant->suivant;
      free(temp);
  }
} 

void ajouterFin(Noeud **tete, int nbAInserer){
    Noeud* nouveau = malloc(sizeof(Noeud));
    if(nouveau == NULL) {
        printf("Erreur d'allocation mémoire!\n");
        exit(EXIT_FAILURE);
    }
    nouveau->valeur = nbAInserer;
    nouveau->suivant = NULL;

    if(*tete == NULL){
        *tete = nouveau;
        return;
    }

    Noeud* courant = *tete;
    while (courant != NULL)
    {
      if(courant->suivant == NULL){
        break;
      }
      courant = courant->suivant;
    }

    courant->suivant = nouveau;

}

void supprimerNombres(Noeud **tete, int nbASupprimer){
    if(*tete == NULL){
        return;
    }

    Noeud* courant = *tete;
    Noeud* precedent = NULL;

    while (courant != NULL)
    {
      if(courant->valeur == nbASupprimer){
        Noeud* temp = courant;
        if(precedent == NULL){
            *tete = courant->suivant;
            courant = *tete;
        } else {
            precedent->suivant = courant->suivant;
            courant = precedent->suivant;
        }
        free(temp);
      } else {
        precedent = courant;
        courant = courant->suivant;
      }
    }
}