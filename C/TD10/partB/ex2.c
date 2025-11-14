#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int x;
  int y;
} Point;

int main() {
  Point* point = malloc(sizeof(Point));
  point->x = 5;
  point->y = 10;
  printf("Point: (%d, %d)\n", point->x, point->y);
  free(point);
  return 0;
}