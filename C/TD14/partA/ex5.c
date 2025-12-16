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

int calculerHauteurAB(NoeudAB *racine)
{
    if (racine == NULL)
    {
        return -1;
    }
    else
    {
        int hauteurGauche = calculerHauteurAB(racine->gauche);
        int hauteurDroite = calculerHauteurAB(racine->droit);
        return (hauteurGauche > hauteurDroite ? hauteurGauche : hauteurDroite) + 1;
    }
}

int calculerTailleAB(NoeudAB *racine)
{
    if (racine == NULL)
    {
        return 0;
    }
    else
    {

        return 1 + calculerTailleAB(racine->gauche) + calculerTailleAB(racine->droit);
    }
}

int compterFeuillesAB(NoeudAB *racine)
{
    if (racine == NULL)
    {
        return 0;
    }
    if (racine->gauche == NULL && racine->droit == NULL)
    {
        return 1;
    }
    return compterFeuillesAB(racine->gauche) + compterFeuillesAB(racine->droit);
}

bool estParfaitAB(NoeudAB *racine)
{
    if (racine == NULL)
    {
        return true;
    }

    int hauteur = calculerHauteurAB(racine);
    int taille = calculerTailleAB(racine);

    return taille == (1 << (hauteur + 1)) - 1;
}

int main()
{
    NoeudAB *racine = creerExempleAB();
    // afficherAB(racine);

    printf("Hauteur de l'arbre:     %3d\n", calculerHauteurAB(racine));
    printf("Taille de l'arbre:      %3d\n", calculerTailleAB(racine));
    printf("Nb de feuilles l'arbre: %3d\n", compterFeuillesAB(racine));
    printf("Arbre parfait:          %3s\n", estParfaitAB(racine) ? "Oui" : "Non");

    // libérer la mémoire de l'arbre
    libererArbre(&racine);

    return 0;
}