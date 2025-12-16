#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

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

void afficherAB(NoeudAB *racine)
{
    if (racine != NULL)
    {
        printf("%d ", racine->valeur);
        afficherAB(racine->gauche);
        afficherAB(racine->droit);
    }
}

int main()
{
    NoeudAB *racine = creerExempleAB();

    puts("Affichage de l'arbre créé");
    afficherAB(racine);

    puts("\nLibération de l'arbre");
    libererArbre(&racine);
    afficherAB(racine);
    return 0;
}