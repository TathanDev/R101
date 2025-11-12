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

void trierParAnnee(Bibliotheque* biblio) {
    int nbLivre = biblio->nbLivre;
    Livre* livres = biblio->livres;
    for (int i = 0; i < nbLivre - 1; i++) {
        
        Livre livre = livres[i];
        int j = i - 1;

        while (j >= 0 && livres[j].anneePub > livre.anneePub)
        {
            livres[j + 1] = livres[j];
            j--;
        }
        livres[j + 1] = livre;
    }
}

int main() {
    Bibliotheque biblio;
    biblio.nbLivre = 0;
    strcpy(biblio.nom, "Bibliotheque Centrale");

    Livre livre1 = {"1984", "George Orwell", 1949};
    Livre livre2 = {"Le Petit Prince", "Antoine de Saint-Exupéry", 1943};
    Livre livre3 = {"Fahrenheit 451", "Ray Bradbury", 1953};

    ajouterLivre(&biblio, livre1);
    ajouterLivre(&biblio, livre2);
    ajouterLivre(&biblio, livre3);

    afficherBibliothèque(&biblio);

    rechercherLivreParAuteur(&biblio, "George Orwell");

    trierParAnnee(&biblio);
    printf("Bibliotheque triee par annee de publication:\n");
    afficherBibliothèque(&biblio);

    return 0;
}