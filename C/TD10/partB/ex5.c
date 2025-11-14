#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int x;
  int y;
} Point;

void translate(Point *point, int dx, int dy) {
  point->x += dx;
  point->y += dy;
}

int main() {
    int size = 6;


    Point* point = malloc(sizeof(Point) * size);
    for (int i = 0; i < size; i++) {
        Point p;
        p.x = rand() % 21 - 10;
        p.y = rand() % 21 - 10;
        point[i] = p;
    }

    for (int i = 0; i < size; i++) {
        printf("Point %d: (%d, %d)\n", i, point[i].x, point[i].y);
        translate(&point[i], 2, -1);
    }

    printf("Translation et affichage des points:\n");

    for (int i = 0; i < size; i++) {
        printf("Point %d: (%d, %d)\n", i, point[i].x, point[i].y);
    }


    free(point);

}