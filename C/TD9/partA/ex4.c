#include <stdio.h>

typedef enum { VERROUILLE, DEVERROUILLE, ALARME, MAINTENANCE } EtatSysteme;

void afficherEtat(EtatSysteme etat);
void changerEtat(EtatSysteme *etat, EtatSysteme nouvelEtat);

void main() {
    EtatSysteme etat = VERROUILLE;
    printf("Etat Initial: ");
    afficherEtat(etat);

    for (int i = 0; i < 5; i++) {
        changerEtat(&etat, (etat + 1) % 4);

        printf("Changement %d: ", i + 1);
        afficherEtat(etat);

    }
}

void afficherEtat(EtatSysteme etat) {
    switch (etat) {
        case VERROUILLE:
            printf("Le système est verrouillé.\n");
            break;
        case DEVERROUILLE:
            printf("Le système est déverrouillé.\n");
            break;
        case ALARME:
            printf("Le système est en mode alarme.\n");
            break;
        case MAINTENANCE:
            printf("Le système est en mode maintenance.\n");
            break;
    }
}

void changerEtat(EtatSysteme *etat, EtatSysteme nouvelEtat) {
    *etat = nouvelEtat;
}