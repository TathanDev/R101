#include <stdio.h>
#include <stdlib.h>


int main() {

    char *ptrChara = NULL;
    ptrChara = (char*)malloc(260 * sizeof(char));
    printf("Entrer un chemin d'accés: ");
    scanf("%259s", ptrChara);

    int i = 0;
    while (*ptrChara != '\0')
    {
        printf("%c ", *ptrChara);
        ptrChara++;
        i++;
    }
    printf("\nLa longueur de la chaine est: %d\n", i);
    return 0;
}