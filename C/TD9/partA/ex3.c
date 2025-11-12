#include <stdio.h>
#include <math.h>

typedef  struct {
    char lettre;
    double x;
    double y;
} Point;

void affichePoint(Point p);

int main() {
    Point p1;
    Point p2;

    scanf("%f", &p1.x);
    scanf("%f", &p1.y);
    scanf(" %c", &p1.lettre);
    affichePoint(p1);

    
    scanf("%f", &p2.x);
    scanf("%f", &p2.y);
    scanf(" %c", &p2.lettre);
    affichePoint(p2);

    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    double distance = sqrtf(dx*dx + dy*dy);
    printf("Distance entre les points %c et %c : %.6f\n", p1.lettre, p2.lettre, distance);

    return 1;
}


void affichePoint(Point p) {
    printf("%c(%d, %d)\n", p.lettre, p.x, p.y);
}