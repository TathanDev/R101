#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x;
    int y;
} Point;

int comparePoints(const void *a, const void *b)
{
    Point *pointA = (Point *)a;
    Point *pointB = (Point *)b;

    int distanceA = pointA->x * pointA->x + pointA->y * pointA->y;
    int distanceB = pointB->x * pointB->x + pointB->y * pointB->y;

    if (distanceA != distanceB)
    {
        return distanceA - distanceB;
    }
    else
    {
        return pointA->y - pointB->y;
    }
}

void afficherPoints(Point points[], int taille)
{
    for (int i = 0; i < taille; i++)
    {
        int distance = points[i].x * points[i].x + points[i].y * points[i].y;
        printf("(%d, %d) --d->  %d\n", points[i].x, points[i].y, distance);
    }
}

int main()
{
    int taille = 5;

    Point points[taille];

    // Initialisation des points avec des valeurs aléatoires
    for (int i = 0; i < taille; i++)
    {
        points[i].x = rand() % 10; // Valeurs aléatoires entre 0 et 9
        points[i].y = rand() % 10;
    }

    printf("Affichage des points aléatoires et distances au centre:\n");
    afficherPoints(points, taille);

    printf("\nTri avec qsort par distance au centre\n");
    qsort(points, taille, sizeof(Point), comparePoints);
    afficherPoints(points, taille);

    return 0;
}