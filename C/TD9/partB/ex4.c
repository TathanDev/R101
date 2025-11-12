#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nom[100];
    int nbLivre;
    Livre livres[100];
} Bibliotheque;

typedef struct {
    char titre[100];
    char auteur[100];
    int anneePub;
} Livre;

void ajouterLivre(Bibliotheque* biblio, Livre livre) {
    if (biblio->nbLivre < 100) {
        biblio->livres[biblio->nbLivre] = livre;
        biblio->nbLivre++;
    } else {
        printf("Bibliotheque pleine!\n");
    }
}

void afficherBibliothèque(Bibliotheque* biblio) {
    printf("Bibliotheque: %s, Nombre de livres: %d\n", biblio->nom, biblio->nbLivre);
    for (int i = 0; i < biblio->nbLivre; i++) {
        printf("Titre : %s, Auteur: %s, Année: %d\n", biblio->livres[i].titre, biblio->livres[i].auteur, biblio->livres[i].anneePub);
    }
}

void rechercherLivreParAuteur(Bibliotheque* biblio, char* auteur) {
    printf("Livres de l'auteur %s:\n", auteur);
    for (int i = 0; i < biblio->nbLivre; i++) {
        if (strcmp(biblio->livres[i].auteur, auteur) == 0) {
            printf("Titre : %s, Année: %d\n", biblio->livres[i].titre, biblio->livres[i].anneePub);
        }
    }
}