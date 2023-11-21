#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE_QUEUE 10
typedef int Element;

typedef struct Queue {
    int front;
    int rear;
    Element dataQueue[MAX_SIZE_QUEUE];
} Queue;

void initQueue(struct Queue* q);
bool isItFull(struct Queue* q);
bool isItEmpty(struct Queue* q);
int size(struct Queue* q);
void push(struct Queue* q, int input);
Element pop(struct Queue* q);
void printQueue(struct Queue* q);
void qerror(int flag, const char *msg);

void initQueue(struct Queue* q) {
    q->front = 0;
    q->rear = 0;
    for(int i = 0; i < MAX_SIZE_QUEUE + 1; i++) {
        q->dataQueue[i] = 0;
    }
}

bool isItFull(struct Queue* q) {
    if(size(q) == MAX_SIZE_QUEUE - 1) {
        return true;
    } 
    return false;
}

bool isItEmpty(struct Queue* q) {
    if(q->front == q->rear) {
        return true;
    }
    return false;
}

int size(struct Queue* q) {
    return (q->rear - q->front + MAX_SIZE_QUEUE) % MAX_SIZE_QUEUE;
}

void push(struct Queue* q, int input) {
    if(!isItFull(q)) {
        q->dataQueue[q->rear] = input;
        q->rear = (q->rear + 1) % MAX_SIZE_QUEUE;
    } else {
        qerror(1, "큐가 가득 차있음");
    }
}

Element pop(struct Queue* q) {
    if(!isItEmpty(q)) {
        Element output = q->dataQueue[q->front];
        q->dataQueue[q->front] = 0;
        q->front = (q->front + 1) % MAX_SIZE_QUEUE;
        return output;
    } else {
        qerror(0, "큐가 비어있음!");
    }
}

void printQueue(struct Queue* q) {
    if(isItEmpty(q)) {
        printf("비어있음\n");
        return;
    }
    printf("현재 Queue[ %d - %d ] = ", q->front, q->rear - 1);
    for(int i = q->front; i != q->rear; i = (i + 1) % MAX_SIZE_QUEUE) {
        if(i == q->rear - 1) {
            printf("%d\n", q->dataQueue[i]);
            return;
        }
        printf("%d, ", q->dataQueue[i]);
    }
}

void qerror(int flag, const char *msg) {
    if (flag == 1) {
    printf("%s\n", msg);
    exit(1);
    } else {
        printf("%s\n", msg);
    }
}

// rear에 있는 요소는 항상 비워둔다, size의 크기는 어레이 크기 10에서 1을 뺀 9이다
// 가득 차있는 경우와 아무것도 없는 경우를 구분하기 위함.

int main () {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    initQueue(queue);

    //manipulate queue
    push(queue, 3);
    printQueue(queue);

    push(queue, 45);
    printQueue(queue);

    push(queue, 9);
    printQueue(queue);

    printf("팝: %d\n", pop(queue));
    printQueue(queue);

    printf("팝: %d\n", pop(queue));
    printQueue(queue);

    printf("팝: %d\n", pop(queue));
    printQueue(queue);

    free(queue);
}