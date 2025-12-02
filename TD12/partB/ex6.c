#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud
{
    int valeur;
    struct Noeud *suivant;
} Noeud;

Noeud *triABulles(Noeud *liste, int taille)
{
    if (liste == NULL || taille == 1)
    {
        return liste;
    }

    int echange;
    do
    {
        echange = 0;
        Noeud *courant = liste;
        Noeud *precedent = NULL;

        for (int i = 0; i < taille - 1; i++)
        {
            if (courant->valeur > courant->suivant->valeur)
            {
                // Échange des nœuds
                Noeud *temp = courant->suivant;
                courant->suivant = temp->suivant;
                temp->suivant = courant;

                if (precedent == NULL)
                {
                    liste = temp; // Mise à jour de la tête de la liste
                }
                else
                {
                    precedent->suivant = temp;
                }
                precedent = temp;
                echange = 1;
            }
            else
            {
                precedent = courant;
                courant = courant->suivant;
            }
        }
    } while (echange);

    return liste;
}

// Pris du TD12/partB/ex4.c
Noeud *creerListeDunTab(int tab[], int taille)
{
    if (taille <= 0)
        return NULL;

    Noeud *liste = malloc(sizeof(Noeud));
    liste->valeur = tab[0];

    Noeud *ancien = liste;
    for (int i = 1; i < taille; i++)
    {
        Noeud *nouveau = malloc(sizeof(Noeud));
        nouveau->valeur = tab[i];
        ancien->suivant = nouveau;
        ancien = nouveau;
    }
    ancien->suivant = NULL;
    return liste;
}

void libererListe(Noeud *liste)
{
    Noeud *ancien = liste;
    while (ancien != NULL)
    {
        Noeud *temp = ancien;
        ancien = ancien->suivant;
        free(temp);
    }
}

// Pris du TD12/partB/ex4.c
void afficherListe(Noeud *liste)
{
    Noeud *courant = liste;
    while (courant != NULL)
    {
        printf("%d -> ", courant->valeur);
        courant = courant->suivant;
    }
    printf("NULL\n");
}

int main()
{
    int taille = 5;

    printf("Nombre d'éléments souhaité dans la liste:");
    scanf("%d", &taille);
    int tab[taille];
    for (int i = 0; i < taille; i++)
    {
        printf("\nDonner la valeur de l'entier du noeud %d: ", i + 1);
        scanf("%d", &tab[i]);
    }

    printf("Les elements de la liste:\n");

    Noeud *liste = creerListeDunTab(tab, taille);
    afficherListe(liste);

    liste = triABulles(liste, taille);
    printf("Tri à bulles de la liste chainée à l'adresse %p de taille %d:\n", liste, taille);
    afficherListe(liste);

    // Libération de la mémoire
    libererListe(liste);

    return 0;
}