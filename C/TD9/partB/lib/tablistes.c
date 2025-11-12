#include <stdio.h>
#include <stdlib.h>
#include "tablistes.h"

/**
 * Cette exercise fut réaliser sur mon pc portable ou le c ne fonctionne pas ce qui veut dire que je n'ai pas pus tésté le code.
 * Il est possible qu'il y ai des erreurs de syntaxes ou autres.
 *
 */

void afficherTabListe(TabListe* liste) 
{
    printf("[");
    for (int i = 0; i < liste->size; i++) 
    {
        printf("%d", liste->tab[i]);
        if (i < liste->size - 1) {
            printf(", ");
        }
    }
    printf("]");
    printf("\n");
}

void ajouterElt(TabListe* liste, int element) 
{
    if (liste->size < TAILLE_TAB) 
    {
        liste->tab[liste->size] = element;
        liste->size++;
    } 
    else 
    {
        printf("Liste pleine!\n");
    }
}
void retirerElt(TabListe* liste) {
    if (liste->size > 0) {
        liste->size--;
    } 
    else {
        printf("Liste vide!\n");
    }
}