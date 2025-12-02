#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud
{
  int valeur;
  struct Noeud *suivant;
} Noeud;

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

void afficherListe(Noeud *liste)
{
  Noeud *ancien = liste;
  while (ancien != NULL)
  {
    printf("%d ", ancien->valeur);
    ancien = ancien->suivant;
  }
  printf("\n");
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

int estTrieeListe(Noeud *liste)
{
  Noeud *ancien = liste;
  int ancienneValeur = liste->valeur;
  while (ancien != NULL && ancien->suivant != NULL)
  {

    if (ancien->suivant->valeur < ancienneValeur)
    {
      return 0;
    }
    ancienneValeur = ancien->valeur;
    ancien = ancien->suivant;
  }

  return 1;
}

Noeud *insereElementListe(Noeud *tete, int valeur)
{
  Noeud *nouveau = malloc(sizeof(Noeud));
  nouveau->valeur = valeur;

  // Teste si la liste est vide ou si l'élément doit être inséré en tête
  if (tete == NULL || tete->valeur > valeur)
  {
    nouveau->suivant = tete;
    return nouveau;
  }

  Noeud *ancien = tete;
  while (ancien->suivant != NULL && ancien->suivant->valeur < valeur)
  {
    ancien = ancien->suivant;
  }

  nouveau->suivant = ancien->suivant;
  ancien->suivant = nouveau;
  return tete;
}

Noeud *triListe(Noeud *tete)
{
  Noeud *listeTriee = NULL;
  Noeud *courant = tete;

  while (courant != NULL)
  {
    Noeud *suivant = courant->suivant;
    listeTriee = insereElementListe(listeTriee, courant->valeur);
    courant = suivant;
  }

  return listeTriee;
}

int main()
{
  // listes chainées
  int tab[] = {1, 4, 5, 6, 2};
  Noeud *liste = creerListeDunTab(tab, 5);
  afficherListe(liste);

  printf("Liste %s triée.\n", estTrieeListe(liste) ? "" : "non");

  printf("\nOn trie la liste\n");

  liste = triListe(liste);
  afficherListe(liste);
  printf("Liste %s triée.\n", estTrieeListe(liste) ? "" : "non");

  // Test d'insertion en boucle
  printf("\nInsertion d'éléments\n");
  for (int i = 0; i < 6; i += 2)
  {
    printf("On insère la valeur %d\n", i);
    liste = insereElementListe(liste, i);
    afficherListe(liste);
  }

  // Libération de la mémoire
  libererListe(liste);

  return 0;
}