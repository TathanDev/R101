#include <stdio.h>
#include <stdbool.h>

// Fonction pour afficher le tableau
void afficherTab(int *tab, int taille) {
    printf("{");
    for (int i = 0; i < taille; i++) {
        printf("%d", tab[i]);
        if (i < taille - 1) printf(", ");
    }
    printf("}\n");
}

int filsGauche(int i) {
    return 2 * i + 1;
}

int filsDroit(int i) {
    return 2 * i + 2;
}

int parent(int i) {
    return (i - 1) / 2;
}

void parcoursLargeurTabAB(int *tab, int taille) {
    for (int i = 0; i < taille; i++) {
        if (tab[i] != -1) {
            printf("%d ", tab[i]);
        }
    }
    printf("\n");
}

int calculerHauteurTabAB(int *tab, int taille, int index) {
    if (index >= taille || tab[index] == -1) return 0;

    int hauteurGauche = calculerHauteurTabAB(tab, taille, filsGauche(index));
    int hauteurDroit = calculerHauteurTabAB(tab, taille, filsDroit(index));

    return 1 + (hauteurGauche > hauteurDroit ? hauteurGauche : hauteurDroit);
}
// Calculer la taille de l'arbre (nombre de noeuds non vides)
int calculerTailleTabAB(int *tab, int taille) {
    int compteur = 0;
    for (int i = 0; i < taille; i++) {
        if (tab[i] != -1) {
            compteur++;
        }
    }
    return compteur;
}

// Compter les feuilles
int compterFeuillesTabAB(int *tab, int taille) {
    int compteur = 0;
    
    for (int i = 0; i < taille; i++) {
        if (tab[i] != -1) {
            int fg = filsGauche(i);
            int fd = filsDroit(i);
            
            // Un noeud est une feuille si ses deux fils sont vides ou hors tableau
            bool filsGaucheVide = (fg >= taille || tab[fg] == -1);
            bool filsDroitVide = (fd >= taille || tab[fd] == -1);
            
            if (filsGaucheVide && filsDroitVide) {
                compteur++;
            }
        }
    }
    
    return compteur;
}

// Vérifier si l'arbre est parfait
bool estParfaitTabAB(int *tab, int taille) {
    if (taille == 0) return false;
    
    int hauteur = calculerHauteurTabAB(tab, taille, 0);
    int tailleReelle = calculerTailleTabAB(tab, taille);
    int tailleTheorique = (1 << (hauteur + 1)) - 1; 

    return tailleReelle == tailleTheorique;
}

// Vérifier si le tableau représente un arbre binaire valide
bool verifierTabAB(int *tab, int taille) {
    if (taille == 0) return false;
    
    // La racine ne doit pas être vide
    if (tab[0] == -1) return false;
    
    // Vérifier que chaque noeud non vide (sauf la racine) a un parent non vide
    for (int i = 1; i < taille; i++) {
        if (tab[i] != -1) {
            int p = parent(i);
            // Le parent doit être dans le tableau et non vide
            if (p < 0 || p >= taille || tab[p] == -1) {
                return false;
            }
        }
    }
    
    return true;
}

int main() {
  int tab[] = {2, 7, 5, 2, 6, -1, 9, -1, -1, 5, 11, -1, -1, 4, -1};
  int taille = sizeof(tab) / sizeof(int);
  puts("Arbre d'exemple");
  afficherTab(tab, taille);
  puts("Parcours en largeur");
  parcoursLargeurTabAB(tab, taille);
  printf("Taille: %d\n", calculerTailleTabAB(tab, taille));
  printf("Hauteur: %d\n", calculerHauteurTabAB(tab, taille, 0));
  printf("Nombre de feuilles: %d\n", compterFeuillesTabAB(tab, taille));
  printf("Est parfait: %d\n", estParfaitTabAB(tab, taille));

  puts("\nArbre parfait de hauteur 2");
  int parfait[] = {0, 1, 2, 3, 4, 5, 6};
  int tailleParfait = sizeof(parfait) / sizeof(int);
  afficherTab(parfait, tailleParfait);
  puts("Parcours en largeur");
  parcoursLargeurTabAB(parfait, tailleParfait);
  printf("Taille: %d\n", calculerTailleTabAB(parfait, tailleParfait));
  printf("Hauteur: %d\n", calculerHauteurTabAB(parfait, tailleParfait, 0));
  printf("Nombre de feuilles: %d\n",
         compterFeuillesTabAB(parfait, tailleParfait));
  printf("Est parfait: %d\n", estParfaitTabAB(parfait, tailleParfait));

  puts("\nTests de validité");
  afficherTab(tab, taille);
  printf("Valide ? -> %d\n", verifierTabAB(tab, taille));
  afficherTab(parfait, tailleParfait);
  printf("Valide ? -> %d\n", verifierTabAB(parfait, tailleParfait));
  int tabSansRacine[] = {-1, 2, 3};
  int tailleSansRacine = sizeof(tabSansRacine) / sizeof(int);
  afficherTab(tabSansRacine, tailleSansRacine);
  printf("Valide ? -> %d\n", verifierTabAB(tabSansRacine, tailleSansRacine));
  int tabInvalide[] = {2, -1, 5, -1, 2, 3, -1};
  int tailleInvalide = sizeof(tabInvalide) / sizeof(int);
  afficherTab(tabInvalide, tailleInvalide);
  printf("Valide ? -> %d\n", verifierTabAB(tabInvalide, tailleInvalide));

  return 0;
}