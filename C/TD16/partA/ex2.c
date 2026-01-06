#include <stdio.h>
#include <stdlib.h>

int main()
{

    // On ouvre le fichier en mode lecture
    FILE *fichier = fopen("exemple.txt", "r");
    if (fichier == NULL)
    {
        // Gestion de l'erreur
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }
    char buffer[256];
    // On lit le fichier ligne par ligne
    while (fgets(buffer, sizeof(buffer), fichier) != NULL)
    {
        printf("%s", buffer);
    }
    // On ferme le fichier
    fclose(fichier);
    return 0;
}