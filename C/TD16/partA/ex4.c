#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SUDOKU_FILE "sudokus.txt"
#define SUDOKU_LUS "sudolus.txt"
#define GRID_SIZE 82  // 81 chiffres + le caractère de fin de chaîne


bool estValide(const char* grille) {
  // Vérifie que la grille contient exactement 81 caractères
  if (strlen(grille) == 81) {

    for(int i = 0; i < 81; i++) {
      if (grille[i] < '0' || grille[i] > '9') {
        return false; // Caractère non valide
      }
    }

    return true;
  }
    return false;
}

bool estDejaFaite(const char* grille) {
  FILE* f = fopen(SUDOKU_LUS, "r");
  if (f == NULL) {
    perror("Problème lors de l'ouverture du fichier");
    exit(1);
  }

  char ligne[GRID_SIZE];
  while (fgets(ligne, sizeof(ligne), f) != NULL) {
    // Retire le caractère de nouvelle ligne
    ligne[strcspn(ligne, "\n")] = 0;
    if (strcmp(ligne, grille) == 0) {
      fclose(f);
      return true;
    }
  }

  fclose(f);
  return false;
}

void ajouterAFichier(const char* grille, const char* nomFichier) {
  FILE* f = fopen(nomFichier, "a");
  if (f == NULL) {
    perror("Problème lors de l'ouverture du fichier");
    exit(1);
  }

  fprintf(f, "%s\n", grille);
  fclose(f);
}

void ajouterSudoku(const char* grille) {
    ajouterAFichier(grille, SUDOKU_FILE);
    ajouterAFichier(grille, SUDOKU_LUS);
}

int main() {
  // crée le fichier s'il n'existe pas sans l'effacer grâce au mode "a"
  FILE* f = fopen(SUDOKU_FILE, "a");
  if (f == NULL) {
    perror("Problème lors de l'ouverture du fichier");
    exit(1);
  }
  fclose(f);

  // boucle infinie
  while (true) {
    // Entrée utilisateur
    printf("\nEntrez une grille de sudoku (ou STOP pour arrêter): ");

    char grille[GRID_SIZE] = "";
    scanf("%s", grille);

    // arrêt de la boucle si STOP
    if (strcmp(grille, "STOP") == 0) break;

    // Vérifications
    if (!estValide(grille)) {
      puts(
          "\t:( La grille est invalide!\n\t\tune grille doit contenir "
          "exactement 81 chiffres");
    } else if (estDejaFaite(grille)) {
      puts("\t:( La grille a déjà été faite");
    } else {
      // ajout de la grille
      ajouterSudoku(grille);
      puts("\t:) Grille ajoutée avec succès");
    }
  }

  // Message de fin
  printf("\n\tMerci, les nouvelles grilles ont été ajoutées au fichier %s",
         SUDOKU_FILE);
  return 0;
}
