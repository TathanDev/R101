#include <stdio.h>


typedef struct {
  int numerateur;
  int denominateur;
} Rationnel;

Rationnel simplifierRationnel(Rationnel r) {
  int diviseur = 2;
  while (r.numerateur >= diviseur && r.denominateur >= diviseur) {
    if (r.numerateur % diviseur == 0 && r.denominateur % diviseur == 0) {
      r.numerateur /= diviseur;
      r.denominateur /= diviseur;
    } else {
      diviseur++;
    }
  }
  return r;
}

Rationnel lireRationnel() {
  Rationnel r;
  printf("Entrez le numérateur (un entier): ");
  scanf("%d", &r.numerateur);
  printf("Entrez le dénominateur (un entier != 0): ");
  scanf("%d", &r.denominateur);
  while (r.denominateur == 0){
      printf("Erreur: le dénominateur ne peut pas être zéro. Veuillez entrer un dénominateur différent de zéro: ");
      scanf("%d", &r.denominateur);
  }
  r = simplifierRationnel(r);
  afficherRationnel(r);
  return r;
}

void afficherRationnel(Rationnel r) {
  printf("%d/%d", r.numerateur, r.denominateur);
}

Rationnel sommeRationnels(Rationnel r1, Rationnel r2) {
  Rationnel somme;
  somme.numerateur = r1.numerateur * r2.denominateur + r2.numerateur * r1.denominateur;
  somme.denominateur = r1.denominateur * r2.denominateur;
  somme = simplifierRationnel(somme);
  return somme;
}

void main() {
  Rationnel r1 = lireRationnel();
  Rationnel r2 = lireRationnel();

  Rationnel somme = sommeRationnels(r1, r2);

  printf("La somme des deux rationnels est:\n ");
  afficherRationnel(r1);
  printf(" + ");
  afficherRationnel(r2);
  printf(" = ");
  afficherRationnel(somme);
  printf("\n");
}