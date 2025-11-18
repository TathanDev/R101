#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct NoeudStr {
  char* url;
  struct NoeudStr* suivant;
} NoeudStr;

void aller(NoeudStr** pile, const char* url)
{
    NoeudStr* nouveauNoeud = malloc(sizeof(NoeudStr));
    if (nouveauNoeud == NULL)
    {
        printf("Erreur d'allocation mémoire!\n");
        return;
    }
    nouveauNoeud->url = strdup(url);
    nouveauNoeud->suivant = *pile;
    *pile = nouveauNoeud;
}

char* revenir(NoeudStr** pile) {
    NoeudStr* sommet = *pile;
    char* url = sommet->url;
    *pile = sommet->suivant;
    free(sommet);
    return url;
}

void afficheUrl(NoeudStr* pile) {
    if (pile == NULL) {
        printf("Aucune URL dans l'historique.\n");
        return;
    }
    printf("URL courante: %s\n", pile->url);
}

bool historiqueVide(NoeudStr* pile) {
    return pile->url == NULL || pile == NULL;
}

void nettoieHistorique(NoeudStr* pile) {
    while(pile->suivant != NULL) {
        revenir(&pile);
    }
}


int main() {
  puts("Début de navigation");

  NoeudStr* navigateur = {NULL};
  afficheUrl(navigateur);

  puts("\nSimulation de navigation");
  char urls[][128] = {"https://www.qwant.com", "https://www.framasoft.org",
                      "https://www.stackoverflow.com"};
  for (int i = 0; i < 3; i++) {
    char* url = urls[i];
    printf("Navigation vers; %s\n", url);
    aller(&navigateur, url);
    afficheUrl(navigateur);
  }

  puts("\nRetour en arrière");
  printf("Dépile %s\n", revenir(&navigateur));
  afficheUrl(navigateur);

  puts("\nNaviguer vers une nouvelle page");
  aller(&navigateur, "https://www.wikipedia.org");
  afficheUrl(navigateur);  // Affiche wikipedia

  // Libération
  puts("\nNettoyage de la mémoire dynamique\n");
  nettoieHistorique(navigateur);
  return 0;
}