#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef struct {
  Node* front;
  Node* rear;
} Queue;

void enqueue(Queue* q, int value) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = value;
  newNode->next = NULL;
  if (q->rear == NULL) {
    q->front = newNode;
    q->rear = newNode;
  } else {
    q->rear->next = newNode;
    q->rear = newNode;
  }
}

int dequeue(Queue* q) {
  if (q->front == NULL) {
    printf("Erreur : la file est vide\n");
    return -1;
  }
  Node* temp = q->front;
  int value = temp->data;
  q->front = q->front->next;
  if (q->front == NULL) {
    q->rear = NULL;
  }
  free(temp);
  return value;
}

int main() {
  Queue q = {NULL, NULL};

  enqueue(&q, 1);
  enqueue(&q, 2);
  enqueue(&q, 3);

  printf("Défilé : %d\n", dequeue(&q));
  printf("Défilé : %d\n", dequeue(&q));

  return 0;
}

/**
 * Ce programme utilise une structure de file (queue) pour ajouter et retirer des éléments.
 * La fonction `enqueue` ajoute un élément à la fin de la file, tandis que la fonction `dequeue` retire le premier élément de la file.
 * 
 * 
 * Dans le programme, on créer une file, on y ajoute trois éléments (1, 2, 3), puis on retire et affiche les deux premiers éléments.
 */