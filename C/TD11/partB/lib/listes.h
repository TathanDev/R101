
typedef struct Noeud {
  int valeur;
  struct Noeud* suivant;
} Noeud;

void afficherListe(Noeud* tete);

unsigned longueurListe(Noeud* tete);

Noeud* creerListeDunTab(int tab[], int taille);


void libererListe(Noeud* tete);

void ajouterFin(Noeud **tete, int nbAInserer);

void supprimerNombres(Noeud **tete, int nbASupprimer);