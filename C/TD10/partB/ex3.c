#include <stdio.h>
#include <stdlib.h>

void initialiserTableau(int* tableau, int n) {
  for (int i = 0; i < n; i++) {
    tableau[i] = 0;
  }
}

int main() {
  int n = 10;
  int* tableau = malloc(n * sizeof(int));
  if (tableau == NULL) {
    fprintf(stderr, "Erreur d'allocation de mémoire\n");
    return 1;
  }
  initialiserTableau(tableau, n);
  for (int i = 0; i < n; i++) {
    printf("%d ", tableau[i]);
  }
  printf("\n");
  free(tableau);
  return 0;
}