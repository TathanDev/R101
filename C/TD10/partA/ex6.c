#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* entreeUtilisateur(int tailleMax, const char* message) {
    printf("%s (max %d caractères) : ", message, tailleMax - 1);

    char str[tailleMax + 1];
    fgets(str, sizeof(str), stdin);
    int len = strlen(str);

    if(len > tailleMax - 1) {
        printf("Dépassement de la taille maximale autorisée.\n");
        exit(1);
    }

    str[strcspn(str, "\n")] = '\0';

    char *strPoint = strdup(str);

    if (strPoint == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        exit(1);
    };
    return strPoint;
}

int main() {
    int tailleMax = 50;
    char *texte = entreeUtilisateur(tailleMax, "Entrez un texte");
    printf("Vous avez entré %d caractères:\n%s\n",strlen(texte), texte);
    free(texte);
    return 0;
}