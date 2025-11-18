#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Noeud
{
    int valeur;
    struct Noeud *suivant;
} Noeud;

typedef struct
{
    Noeud *sommet;
} Pile;

void empiler(Pile *pile, int valeur)
{
    Noeud *nouveauNoeud = malloc(sizeof(Noeud));
    if (nouveauNoeud == NULL)
    {
        printf("Erreur d'allocation mémoire!\n");
        return;
    }
    nouveauNoeud->valeur = valeur;
    nouveauNoeud->suivant = pile->sommet;
    pile->sommet = nouveauNoeud;
}

int depile(Pile *pile)
{
    if (pile->sommet == NULL)
    {
        printf("Pile vide!\n");
        exit(EXIT_FAILURE);
    }
    Noeud *temp = pile->sommet;
    int valeur = temp->valeur;
    pile->sommet = pile->sommet->suivant;
    free(temp);
    return valeur;
}

bool estVide(Pile *pile)
{
    return pile->sommet == NULL;
}

int getSommet(Pile *pile)
{
    if (pile->sommet == NULL)
    {
        printf("Pile vide!\n");
        exit(EXIT_FAILURE);
    }
    return pile->sommet->valeur;
}

int main()
{
    Pile pile = {NULL};

    printf("Pile initialisée, estVide renvoie: %d\n", estVide(&pile));

    printf("Début de l'empilement.\n");
    empiler(&pile, 10);
    printf("Valeur empilée: 10\n");
    empiler(&pile, 20);
    printf("Valeur empilée: 20\n");
    empiler(&pile, 30);
    printf("Valeur empilée: 30\n");

    printf("Maintenant estVide renvoie: %d et getSommet: %d\n", estVide(&pile), getSommet(&pile));

    printf("Dépile et affiche tous les éléments avec une boucle while\n");
    while (!estVide(&pile))
    {
        int v = depile(&pile);
        printf("Dépile %d\n", v);
    }

    printf("Maintenant estVide renvoie: %d\n", estVide(&pile));

    return 0;
}