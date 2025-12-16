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
    noeud5->gauche = NULL;

    NoeudAB *noeud4 = malloc(sizeof(NoeudAB));
    noeud4->valeur = 4;

    noeud9->gauche = noeud4;
    noeud9->droit = NULL;

    NoeudAB *noeud5_2 = malloc(sizeof(NoeudAB));
    noeud5_2->valeur = 5;

    NoeudAB *noeud11 = malloc(sizeof(NoeudAB));
    noeud11->valeur = 11;

    noeud6->gauche = noeud5_2;
    noeud6->droit = noeud11;

    noeud2->gauche = NULL;
    noeud2->droit = NULL;
    noeud5_2->gauche = NULL;
    noeud5_2->droit = NULL;
    noeud11->gauche = NULL;
    noeud11->droit = NULL;
    noeud4->gauche = NULL;
    noeud4->droit = NULL;

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

void parcourPrefixe(NoeudAB *racine, bool inverse)
{
    if (racine != NULL)
    {
        printf("%d ", racine->valeur);
        if (!inverse)
        {
            parcourPrefixe(racine->gauche, inverse);
            parcourPrefixe(racine->droit, inverse);
        }
        else
        {
            parcourPrefixe(racine->droit, inverse);
            parcourPrefixe(racine->gauche, inverse);
        }
    }
}

void parcourInfixe(NoeudAB *racine, bool inverse)
{
    if (racine != NULL)
    {
        if (!inverse)
        {
            parcourInfixe(racine->gauche, inverse);
            printf("%d ", racine->valeur);
            parcourInfixe(racine->droit, inverse);
        }
        else
        {
            parcourInfixe(racine->droit, inverse);
            printf("%d ", racine->valeur);
            parcourInfixe(racine->gauche, inverse);
        }
    }
}

void parcourPostfixe(NoeudAB *racine, bool inverse)
{
    if (racine != NULL)
    {
        if (!inverse)
        {
            parcourPostfixe(racine->gauche, inverse);
            parcourPostfixe(racine->droit, inverse);
            printf("%d ", racine->valeur);
        }
        else
        {
            parcourPostfixe(racine->droit, inverse);
            parcourPostfixe(racine->gauche, inverse);
            printf("%d ", racine->valeur);
        }
    }
}

void parcourirProfondeurAB(NoeudAB *racine, DFSOrdre ordre, bool inverse)
{
    switch (ordre)
    {
    case PRE:
        parcourPrefixe(racine, inverse);
        break;
    case IN:
        parcourInfixe(racine, inverse);
        break;
    case POST:
        parcourPostfixe(racine, inverse);
        break;
    }
}

int main()
{
    NoeudAB *racine = creerExempleAB();
    bool inverse = false;
    puts("Parcours en profondeur dans l'ordre\n---");

    printf("\tPRE: ");
    parcourirProfondeurAB(racine, PRE, inverse);
    printf("\n\tIN: ");
    parcourirProfondeurAB(racine, IN, inverse);
    printf("\n\tPOST: ");
    parcourirProfondeurAB(racine, POST, inverse);

    inverse = true;
    puts("\n\nParcours en profondeur inversé\n---");

    printf("\tPRE: ");
    parcourirProfondeurAB(racine, PRE, inverse);
    printf("\n\tIN: ");
    parcourirProfondeurAB(racine, IN, inverse);
    printf("\n\tPOST: ");
    parcourirProfondeurAB(racine, POST, inverse);
    puts("");

    libererArbre(&racine);

    return 0;
}