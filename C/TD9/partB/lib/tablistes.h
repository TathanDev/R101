#pragma once
#define TAILLE_TAB 256


typedef struct 
{
    int size;
    int tab[TAILLE_TAB];
} TabListe;

void afficherTabListe(TabListe* liste);

void ajouterElt(TabListe* liste, int element);
void retirerElt(TabListe* liste);