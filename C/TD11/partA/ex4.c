#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct NoeudChar {
  char valeur;
  struct NoeudChar* suivant;
} NoeudChar;

typedef struct {
  NoeudChar* sommet;
} PileChar;


void empiler(PileChar *pile, char valeur)
{
    NoeudChar *nouveauNoeud = malloc(sizeof(NoeudChar));
    if (nouveauNoeud == NULL)
    {
        printf("Erreur d'allocation mémoire!\n");
        return;
    }
    nouveauNoeud->valeur = valeur;
    nouveauNoeud->suivant = pile->sommet;
    pile->sommet = nouveauNoeud;
}

int depile(PileChar *pile)
{
    if (pile->sommet == NULL)
    {
        printf("Pile vide!\n");
        exit(EXIT_FAILURE);
    }
    NoeudChar *temp = pile->sommet;
    char valeur = temp->valeur;
    pile->sommet = pile->sommet->suivant;
    free(temp);
    return valeur;
}

bool estVide(PileChar *pile)
{
    return pile->sommet == NULL;
}

int main(){
    PileChar pile = {NULL};
    char* ptrChara = malloc(260 * sizeof(char));
    if (ptrChara == NULL) {
        printf("Erreur d'allocation mémoire!\n");
        return 1;
    }
    printf("Entrer un texte: ");
    fgets(ptrChara, 260, stdin);

    int taille = strlen(ptrChara);
    for (int i = 0; i < taille; i++) {
        empiler(&pile, ptrChara[i]);
    }

    while (!estVide(&pile)) {
        printf("%c", depile(&pile));
    }
    printf("\n");

    free(ptrChara);
    return 0;
}