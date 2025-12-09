# include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "lib/tableaux.h"
void afficherTab(int* tab, int taille) {
    printf("{");
    for (int i = 0; i < taille; i++) {
        printf("%d", tab[i]);
        if (i < (taille - 1)) {
            printf(", ");
        }
    }
    printf("}\n");
}

int sommeTab(int* tab, int taille) {
    int s = 0;
    for (int i = 0; i < taille; i++) {
        s += tab[i];
    }
    return s;
}

int renduMonnaieDynamique(int pieces[], int nbPiece, int montant) {
    int tableau[montant + 1];

    for (int i = 0; i <= montant; i++) {
        tableau[i] = INT_MAX;
    }
    tableau[0] = 0;

    for (int i = 1; i <= montant; i++) {
        for (int j = 0; j < nbPiece; j++) {
            if (pieces[j] <= i && tableau[i - pieces[j]] != INT_MAX) {
                int possibleMin = tableau[i - pieces[j]] + 1;
                if (possibleMin < tableau[i]) {
                    tableau[i] = possibleMin;
                }
            }
        }
    }

    int resultat = tableau[montant];
    printf("Tableau des rendus obtenus: ");
    afficherTab(tableau, montant + 1);

    return resultat;
}

int renduMonnaieDynamique2D(int pieces[], int nbPiece, int montant) {
    int rows = montant + 1;
    int tableau2D[rows][nbPiece] = {};



    int minPieces[rows];
    for (int i = 0; i < rows; i++) {
        minPieces[i] = INT_MAX;
    }
    minPieces[0] = 0;

    for (int montantCourant = 1; montantCourant <= montant; montantCourant++) {
        for (int j = 0; j < nbPiece; j++) {
            int valeur = pieces[j];
            if (valeur <= montantCourant && minPieces[montantCourant - valeur] != INT_MAX) {
                int candidat = minPieces[montantCourant - valeur] + 1;
                if (candidat < minPieces[montantCourant]) {
                    for (int k = 0; k < nbPiece; k++) {
                        tableau2D[montantCourant][k] = tableau2D[montantCourant - valeur][k];
                    }
                    tableau2D[montantCourant][j]++;
                    minPieces[montantCourant] = candidat;
                }
            }
        }
    }

    int resultat;
    if (minPieces[montant] == INT_MAX) {
        resultat = INT_MAX;
    } else {
        resultat = sommeTab(tableau2D[montant], nbPiece);
    }

    printf("Tableau des rendus obtenus (chaque ligne correspond à un montant 0..%d):\n", montant);
    for (int i = 0; i <= montant; i++) {
        printf("%2d€: ", i);
        afficherTab(tableau2D[i], nbPiece);
    }

    return resultat;
}


int main() {
  int valeurs[] = {1, 7, 23};
  int nbPiece = sizeof(valeurs) / sizeof(valeurs[0]);

  printf("Tableau des pieces: ");
  afficherTab(valeurs, nbPiece);

  int montant = 28;
  printf("Rendu dynamique du montant %d€\n", montant);

  int nbRendu = renduMonnaieDynamique2D(valeurs, nbPiece, montant);

  if (nbRendu == INT_MAX) {
    printf(
        "Il est impossible de rendre ce montant avec les pièces "
        "disponibles.\n");
  } else {
    printf("Nombre minimal de pièces/billets nécessaires : %d\n", nbRendu);
  }

  return 0;
}
