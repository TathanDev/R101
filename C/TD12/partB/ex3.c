#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud {
  int valeur;
  struct Noeud* suivant;
  struct Noeud* precedent;
} Noeud;

int estVide(Noeud* file) {
  return file == NULL;
}

void afficherFile(Noeud* file) {
  if(estVide(file)) {
    printf("File %p\n", file);
    return;
  }
  printf("File: tête = %d, queue = %d\n", file->precedent->valeur, file->suivant->valeur);
}

void enfiler(Noeud** file, int valeur) {
  Noeud* nouveau = malloc(sizeof(Noeud));
  nouveau->valeur = valeur;
  if(estVide(*file)) {
    nouveau->suivant = nouveau;
    nouveau->precedent = nouveau;
    *file = nouveau;
  } else {
    Noeud* queue = (*file)->precedent;
    queue->suivant = nouveau;
    nouveau->precedent = queue;
    nouveau->suivant = *file;
    (*file)->precedent = nouveau;
  }
}

int defiler(Noeud** file) {
  if(estVide(*file)) {
    printf("Erreur : la file est vide\n");
    return -1;
  }
  Noeud* tete = *file;
  int valeur = tete->valeur;

  //Si la file ne contient qu'un seul élément
  if(tete->suivant == tete) {
    free(tete);
    *file = NULL;

  } else {

    //On met à jour les pointeurs pour retirer la tête
    Noeud* nouvelleTete = tete->suivant;
    Noeud* queue = tete->precedent;
    queue->suivant = nouvelleTete;
    nouvelleTete->precedent = queue;
    free(tete);
    *file = nouvelleTete;
  }
  return valeur;
}

int main() {
  Noeud* file = NULL;
  puts("# Etat initial");

  printf("File vide ? %s\n", estVide(file) ? "vrai" : "faux");
  afficherFile(file);

  puts("\n# Début des enfilages");
  for (int i = 0; i < 3; i++) {
    printf("Enfile %d\n", i + 1);
    enfiler(&file, i + 1);
    afficherFile(file);
  }

  printf("File vide ? %s\n", estVide(file) ? "vrai" : "faux");

  puts("\n# Début des défilements");
  while (!estVide(file)) {
    printf("Défile %d\n", defiler(&file));
    afficherFile(file);
  }

  puts("\n# Etat final");

  printf("File vide ? %s\n", estVide(file) ? "vrai" : "faux");
}