#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 10

typedef struct Queue {
    struct Node *front;
    struct Node *rear;
    struct Node *sentinel;
} Queue;

typedef struct Node {
    int data;
    struct Node *next;
} Node;

bool isItEmpty(struct Queue *q);
void printQueue(struct Queue *q);
void enQueue(struct Queue *q, int input);
int* deQueue(struct Queue *q);
void printStatus(struct Queue *q);
void printNode(struct Node *node, struct Queue *q);
void qerror(int i);
void initQueue(struct Queue *q);
int countQueue(struct Queue *q);
int countNode(struct Node *node, int number);
void doDequeue(struct Queue *q);
void freeRemaining(struct Queue *q);
void doFree(struct Node *node);

int main() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    initQueue(q);

    enQueue(q, 4);
    printStatus(q);

    enQueue(q, 304);
    printStatus(q);

    enQueue(q, 24);
    printStatus(q);

    doDequeue(q);
    printStatus(q);

    doDequeue(q);
    doDequeue(q);
    doDequeue(q);
    printStatus(q);

    freeRemaining(q);
}

void initQueue(struct Queue *q) {
    q->sentinel = (Node*)malloc(sizeof(Node));

    q->sentinel->data = 0;
    q->sentinel->next = NULL;

    q->front = q->sentinel;
    q->rear = q->sentinel;
}

bool isItEmpty(struct Queue *q) {
    if(q->front == q->sentinel) {
        return true;
    } else {
        return false;
    }
}

void printStatus(struct Queue *q) {
    if(isItEmpty(q)) {
        printf("큐가 비어있습니다.\n");
    } else {
        printQueue(q);
    }
}

void printQueue(struct Queue *q) {
    printf("현재 큐의 상태: ");
    printNode(q->front, q);
}

void printNode(struct Node *node, struct Queue *q) {
    while(node->next != NULL) {
        printf("%d, ", node->data);
        printNode(node->next, q);
        return;
    }
    printf("%d\n", node->data);
}

void enQueue(struct Queue *q, int input) {
    if(countQueue(q) == MAX_QUEUE_SIZE) {
        qerror(1);
        return;
    }
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = input;
    newNode->next = NULL;
    if(q->front == q->sentinel) { //큐에 아무것도 없을 때
        q->front = newNode;
        q->rear = newNode;
    } else { // 그 외
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void doDequeue(struct Queue *q) {
    int* deQueueOut = deQueue(q);
    if(deQueueOut == NULL) {
        qerror(0);
    } else {
        printf("%d\n", *deQueueOut);
        free(deQueueOut);
    }
}

int* deQueue(struct Queue *q) {
    if(isItEmpty(q)) {
        return NULL;
    }
    int* output = (int*)malloc(sizeof(int));
    *output = q->front->data;
    Node *temp = q->front;
    if(temp->next == NULL) { // 마지막 남은거였다면 센티널로 바꿔야 한다.
        q->front = q->sentinel;
    } else {
        q->front = temp->next;
    }
    free(temp);
    return output;
}

int countQueue(struct Queue *q) {
    int count = 0;
    if(q->front == q->sentinel) {
        return count;
    } else {
        return countNode(q->front, count);
    }
}
int countNode(struct Node *node, int number) {
    if(node->next != NULL) {
        number += 1;
        return countNode(node->next, number);
    } else {
        return number + 1;
    }
}

void qerror(int errNum) {
    if(errNum == 0) {
        printf("큐가 비어 있습니다, deQueue 실패.\n");
    } else if(errNum == 1) {
        printf("큐가 가득 차 있습니다, enQueue 실패.\n");
    }
}

void freeRemaining(struct Queue *q) {
    if(q->front != q->sentinel) {
        doFree(q->front);
    }
    free(q->sentinel);
    free(q);
}

void doFree(struct Node *node) {
    if(node->next != NULL) {
        doFree(node->next);
        free(node);
        return;
    }
    free(node);
    return;
}