#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct
{
    int sommet;
    int maxTaille;
    int tab[MAX_SIZE];
} PileTableau;

void empiler(PileTableau *pile, int valeur)
{
    if (pile->sommet < pile->maxTaille - 1)
    {
        pile->sommet++;
        pile->tab[pile->sommet] = valeur;
    }
    else
    {
        printf("Pile pleine!\n");
    }
}

int depiler(PileTableau *pile)
{
    if (pile->sommet >= 0)
    {
        int valeur = pile->tab[pile->sommet];
        pile->sommet--;
        return valeur;
    }
    else
    {
        printf("Pile vide!\n");
        return -1; // Valeur indicative d'une pile vide
    }
}

int sommet(PileTableau *pile)
{
    if (pile->sommet >= 0)
    {
        return pile->tab[pile->sommet];
    }
    else
    {
        printf("Pile vide!\n");
        exit(EXIT_FAILURE);
    }
}

int main()
{
    PileTableau pile = {.sommet = -1, .maxTaille = MAX_SIZE};
    printf("Empile 1 puis 3 puis 2 comme dans l'illustration.\n");
    empiler(&pile, 1);
    empiler(&pile, 3);
    empiler(&pile, 2);

    int sommetValeur = sommet(&pile);
    printf("Le sommet est: %d\n", sommetValeur);

    printf("Sommet de la pile: %d\n", sommetValeur);

    printf("Dépile deux fois comme dans l'illustration.\n");
    int depileValeur1 = depiler(&pile);
    int depileValeur2 = depiler(&pile);
    printf("Dépile ->  %d\n", depileValeur1);
    printf("Dépile ->  %d\n", depileValeur2);

    int sommetValeur2 = sommet(&pile);
    printf("Le sommet est: %d\n", sommetValeur2);
    return 0;
}