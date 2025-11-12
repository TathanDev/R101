//| stdin: 13 -1 3 7 -9
#include <stdio.h>
#include <stdlib.h>

#include "../lib/tableaux.h"

int main() {
  int taille = 5;
  int* tableau = tableauScanfTaille(taille);

  afficherTab(tableau, taille);

  free(tableau);

  return 0;
}