#include <stdio.h>
#include <stdlib.h>

// Node structure for stack
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Stack structure
typedef struct Stack {
    Node* top;
} Stack;

typedef struct Queue {
    Stack s1, s2;
} Queue;
void initStack(Stack* s) {
    s->top = NULL;
}

void push(Stack* s, int val) {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (!temp) {
        printf("Memory allocation failed!\n");
        return;
    }
    temp->data = val;
    temp->next = s->top;
    s->top = temp;
}
int pop(Stack* s) {
    if (s->top == NULL) {
        printf("Underflow condition\n");
        return -1; 
    }
    Node* temp = s->top;
    int val = temp->data;
    s->top = temp->next;
    free(temp);
    return val;
}
int isEmpty(Stack* s) {
    return s->top == NULL;
}
void initQueue(Queue* q) {
    initStack(&q->s1);
    initStack(&q->s2);
}
void enqueue(Queue* q, int val) {
    push(&q->s1, val);
    printf("%d enqueued.\n", val);
}
int dequeue(Queue* q) {
    if (isEmpty(&q->s1) && isEmpty(&q->s2)) {
        printf("Queue underflow! Cannot dequeue.\n");
        return -1;
    }
    if (isEmpty(&q->s2)) {
        while (!isEmpty(&q->s1)) {
            int val = pop(&q->s1);
            push(&q->s2, val);
        }
    }
    return pop(&q->s2);
}
void display(Queue* q) {
    if (isEmpty(&q->s1) && isEmpty(&q->s2)) {
        printf("Queue is empty.\n");
        return;
    }
    Stack temp;
    initStack(&temp);

    Node* ptr = q->s2.top;
    while (ptr) {
        push(&temp, ptr->data);
        ptr = ptr->next;
    }
    while (!isEmpty(&temp)) {
        printf("%d ", pop(&temp));
    }
    ptr = q->s1.top;
    while (ptr) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
int main() {
    Queue q;
    initQueue(&q);
    int choice, val;
    while (1) {
        printf("\n--- Queue using Two Stacks ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(&q, val);
                break;
            case 2:
                val = dequeue(&q);
                if (val != -1)
                    printf("Dequeued: %d\n", val);
                break;
            case 3:
                printf("Queue: ");
                display(&q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}