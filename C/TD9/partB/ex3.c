#include <stdio.h>
#include <stdlib.h>

#define MAX_ETUDIANTS 100

typedef struct {
    int ine;
    char nom[20];
    char prenom[20];
    double note;
} Etudiant;

void afficherEtu(Etudiant etu) {
    printf("%d: %s %s (Note: %.2f)\n", etu.ine, etu.nom, etu.prenom, etu.note);
}

void initialiserListeEtudiants(Etudiant liste[]) {
    for(int i = 0; i < sizeof(liste) / sizeof(liste[0]); i++) {
        liste[i].ine = 0; 
    }
}

int nbEtudiant(Etudiant liste[]) {
    int count = 0;
    for(int i = 0; i < MAX_ETUDIANTS; i++) {
        if(liste[i].ine != 0) {
            count++;
        }
    }
    return count;
}

void afficherListe(Etudiant liste[]) {
    for(int i = 0; i < sizeof(liste) / sizeof(liste[0]); i++) {
        if(liste[i].ine != 0) {
            afficherEtu(liste[i]);
        }
    }
}

void insererEtu(Etudiant t[], Etudiant nouvelEtudiant) {
  int i = nbEtudiant(t);

  if (i >= MAX_ETUDIANTS) {
    fprintf(stderr, "Nb d'étudiants maximum atteint\n");
    return;
  }

  if (i == 0) {
    t[0] = nouvelEtudiant;
    return;
  }


  int j = i - 1; //Le max d'étudiants - 1 car a la fin le dernier etudiant sera forcément trié.
  while (j >= 0 && t[j].ine > nouvelEtudiant.ine) { //tant que j est positif et que l'ine de l'étudiant j est plus grand que celui du nouvel étudiant
    t[j + 1] = t[j]; //on décale l'étudiant j vers la droite
    j--;
  }

  t[j + 1] = nouvelEtudiant;
}

int rechercherEtu(Etudiant t[], int numero) {
    int indice = -1;
    for(int i = 0; i < nbEtudiant(t); i++) {
        if(t[i].ine == numero) {
            indice = i;
            break;
        }
    }
    return indice;
}

int main() {
  // Déclaration de la liste d'étudiants
  Etudiant liste[MAX_ETUDIANTS];

  // initialise la liste en mettant les ine à 0
  initialiserListeEtudiants(liste);

  puts("Ajout de trois étudiants en les affichant");
  Etudiant etu1 = {123, "Seydoux", "Laura", 15.3};
  afficherEtu(etu1);
  insererEtu(liste, etu1);

  Etudiant etu2 = {324, "Alexis", "Manenti", 5.9};
  afficherEtu(etu2);
  insererEtu(liste, etu2);

  Etudiant etu3 = {255, "Camélia", "Jordana", 9.9};
  afficherEtu(etu3);
  insererEtu(liste, etu3);

  printf("\nVoici la liste de %d étudiants triée par ine\n", nbEtudiant(liste));
  afficherListe(liste);

  // Recherche d'un étudiant
  int numeroRecherche;
  printf("\nEntrez un numéro d'étudiant à rechercher: ");
  scanf("%d", &numeroRecherche);

  int indice = rechercherEtu(liste, numeroRecherche);
  if (indice != -1) {
    Etudiant etu = liste[indice];
    if (etu.note > 10) {
      printf("ADMIS:) ");
    } else if (etu.note >= 8) {
      printf("RATTRAPAGE:! ");
    } else {
      printf("RECALÉ! ");
    };
    afficherEtu(etu);
  } else {
    printf("Étudiant non trouvé.\n");
  }

  return 0;
}
