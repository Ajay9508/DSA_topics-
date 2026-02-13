#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coff;
    int exp;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

void enqueue(Queue* q, int coff, int exp) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->coff = coff;
    temp->exp = exp;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

void display(Queue* q) {
    Node* temp = q->front;
    while (temp != NULL) {
        printf("%dx^%d", temp->coff, temp->exp);
        if (temp->next != NULL) printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

Queue add_Poly(Queue* q1, Queue* q2) {
    Queue result;
    initQueue(&result);

    Node* p1 = q1->front;
    Node* p2 = q2->front;

    while (p1 && p2) {
        if (p1->exp == p2->exp) {
            int sumcoff = p1->coff + p2->coff;
            if (sumcoff != 0)
                enqueue(&result, sumcoff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->exp > p2->exp) {
            enqueue(&result, p1->coff, p1->exp);
            p1 = p1->next;
        } else {
            enqueue(&result, p2->coff, p2->exp);
            p2 = p2->next;
        }
    }

    while (p1) {
        enqueue(&result, p1->coff, p1->exp);
        p1 = p1->next;
    }
    while (p2) {
        enqueue(&result, p2->coff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

int main() {
    Queue P1, P2;
    initQueue(&P1);
    initQueue(&P2);
 int n1, n2, coeff, pow;

    // Input for first polynomial
    printf("Enter number of terms in P1: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        printf("Enter coefficient and power for term %d: ", i + 1);
        scanf("%d %d", &coeff, &pow);
        enqueue(&P1, coeff, pow);
    }

    // Input for second polynomial
    printf("Enter number of terms in P2: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        printf("Enter coefficient and power for term %d: ", i + 1);
        scanf("%d %d", &coeff, &pow);
        enqueue(&P2, coeff, pow);
    }
    printf("P1 = ");
    display(&P1);

    printf("P2 = ");
    display(&P2);

    Queue Result = add_Poly(&P1, &P2);
    printf("Result = ");
    display(&Result);

    return 0;
}