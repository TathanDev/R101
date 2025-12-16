#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <stdbool.h>

typedef enum
{
    PRE,
    IN,
    POST
} DFSOrdre;

typedef struct NoeudAB
{
    int valeur;
    struct NoeudAB *gauche;
    struct NoeudAB *droit;
} NoeudAB;

NoeudAB *creerExempleAB()
{
    NoeudAB *racine = malloc(sizeof(NoeudAB));
    racine->valeur = 2;

    NoeudAB *noeud7 = malloc(sizeof(NoeudAB));
    noeud7->valeur = 7;

    NoeudAB *noeud5 = malloc(sizeof(NoeudAB));
    noeud5->valeur = 5;

    racine->gauche = noeud7;
    racine->droit = noeud5;

    NoeudAB *noeud2 = malloc(sizeof(NoeudAB));
    noeud2->valeur = 2;

    NoeudAB *noeud6 = malloc(sizeof(NoeudAB));
    noeud6->valeur = 6;

    noeud7->gauche = noeud2;
    noeud7->droit = noeud6;

    NoeudAB *noeud9 = malloc(sizeof(NoeudAB));
    noeud9->valeur = 9;

    noeud5->droit = noeud9;

    NoeudAB *noeud4 = malloc(sizeof(NoeudAB));
    noeud4->valeur = 4;

    noeud9->gauche = noeud4;

    NoeudAB *noeud5_2 = malloc(sizeof(NoeudAB));
    noeud5_2->valeur = 5;

    NoeudAB *noeud11 = malloc(sizeof(NoeudAB));
    noeud11->valeur = 11;

    noeud6->gauche = noeud5_2;
    noeud6->droit = noeud11;

    return racine;
}

void libererArbre(NoeudAB **racine)
{
    if (*racine != NULL)
    {
        libererArbre(&((*racine)->gauche));
        libererArbre(&((*racine)->droit));
        free(*racine);
        *racine = NULL;
    }
}

void parcourPrefixe(NoeudAB *racine)
{
    if (racine != NULL)
    {
        printf("%d ", racine->valeur);
        parcourPrefixe(racine->gauche);
        parcourPrefixe(racine->droit);
    }
}

void parcourInfixe(NoeudAB *racine)
{
    if (racine != NULL)
    {
        parcourInfixe(racine->gauche);
        printf("%d ", racine->valeur);
        parcourInfixe(racine->droit);
    }
}

void parcourPostfixe(NoeudAB *racine)
{

    if (racine != NULL)
    {
        parcourPostfixe(racine->gauche);
        parcourPostfixe(racine->droit);
        printf("%d ", racine->valeur);
    }
}

void parcourirProfondeurAB(NoeudAB *racine, DFSOrdre ordre, bool inverse)
{
    switch (ordre)
    {
    case PRE:
        parcourPrefixe(racine);
        break;
    case IN:
        parcourInfixe(racine);
        break;
    case POST:
        parcourPostfixe(racine);
        break;
    }
}

int main()
{
    NoeudAB *racine = creerExempleAB();
    bool inverse = false;
    puts("Parcours en profondeur dans l'ordre\n---");

    // TODO : implémenter la gestion de l'inverse
    printf("\tPRE: ");
    parcourirProfondeurAB(racine, PRE, inverse);
    printf("\n\tIN: ");
    parcourirProfondeurAB(racine, IN, inverse);
    printf("\n\tPOST: ");
    parcourirProfondeurAB(racine, POST, inverse);

    libererArbre(&racine);

    return 0;
}