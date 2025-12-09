#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char titre[50];
    int masse;
    int prix;
} Livre;

int comparerPrix(const void *a, const void *b)
{
    Livre *livreA = (Livre *)a;
    Livre *livreB = (Livre *)b;

    if (livreA->prix < livreB->prix)
    {
        return 1;
    }
    return -1;
}

int comparerRatio(const void *a, const void *b)
{
    Livre *livreA = (Livre *)a;
    Livre *livreB = (Livre *)b;

    double ratioA = (double)livreA->prix / livreA->masse;
    double ratioB = (double)livreB->prix / livreB->masse;

    if (ratioA < ratioB)
    {
        return 1;
    }
    return -1;
}

void afficherLivre(Livre livre)
{
    printf("%s (%d kg, %d euros)\n", livre.titre, livre.masse, livre.prix);
}

void afficherLivres(Livre livres[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("   ");
        afficherLivre(livres[i]);
    }
}

void sacGloutonMasse(Livre tab[], int n, int capacite)
{

    printf("Capacité du sac: %d kg\n", capacite);
    printf("Les livres sont déjà triés par masse croissante ->\n");

    afficherLivres(tab, n);
    printf("\n\nRemplissage du sac\n");

    int masseTotale = 0;
    int prixTotal = 0;
    for (int i = 0; i < n; i++)
    {
        if (masseTotale + tab[i].masse <= capacite)
        {
            masseTotale += tab[i].masse;
            prixTotal += tab[i].prix;
            printf("   ");
            afficherLivre(tab[i]);
        }
    }
    printf("RÉSULTAT: %d€ (%dkg / %dkg)\n", prixTotal, masseTotale, capacite);
}

void sacGloutonPrix(Livre tab[], int n, int capacite)
{
    qsort(tab, n, sizeof(Livre), comparerPrix);

    printf("Capacité du sac: %d kg\n", capacite);
    printf("Les livres sont déjà triés par masse croissante ->\n");

    afficherLivres(tab, n);
    printf("\n\nRemplissage du sac\n");

    int masseTotale = 0;
    int prixTotal = 0;
    for (int i = 0; i < n; i++)
    {
        if (masseTotale + tab[i].masse <= capacite)
        {
            masseTotale += tab[i].masse;
            prixTotal += tab[i].prix;
            printf("   ");
            afficherLivre(tab[i]);
        }
    }
    printf("RÉSULTAT: %d€ (%dkg / %dkg)\n", prixTotal, masseTotale, capacite);
}

void sacGloutonRatio(Livre tab[], int n, int capacite)
{
    qsort(tab, n, sizeof(Livre), comparerRatio);

    printf("Capacité du sac: %d kg\n", capacite);
    printf("Les livres sont déjà triés par masse croissante ->\n");

    afficherLivres(tab, n);
    printf("\n\nRemplissage du sac\n");

    int masseTotale = 0;
    int prixTotal = 0;
    for (int i = 0; i < n; i++)
    {
        if (masseTotale + tab[i].masse <= capacite)
        {
            masseTotale += tab[i].masse;
            prixTotal += tab[i].prix;
            printf("   ");
            afficherLivre(tab[i]);
        }
    }
    printf("RÉSULTAT: %d€ (%dkg / %dkg)\n", prixTotal, masseTotale, capacite);
}


int main()
{
    Livre livres[] = {{"Livre poche", 1, 1},
                      {"Memo d'algorithmique", 1, 2},
                      {"Manuel de C", 2, 2},
                      {"Tout en un BUT1", 4, 10},
                      {"Collection complete de Knuth", 12, 4}};
    const int NB_LIVRE = sizeof(livres) / sizeof(Livre);
    const int CAPACITE_SAC = 5;

    sacGloutonRatio(livres, NB_LIVRE, CAPACITE_SAC);
    return 0;
}