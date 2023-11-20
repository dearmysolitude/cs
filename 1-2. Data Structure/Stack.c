#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct stack {
    struct Node *top;
} stack;

void push(stack *s, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
}

char pop(stack *s) {
    if(s->top == NULL) {
        printf("스택이 비어있습니다.");
    } else {
        Node *temp = s->top;
        int data = temp->data;
        s->top = temp->next;
        free(temp);
        return data;
    }
}

void initStack(stack *s) {
    s->top = NULL;
}

int main() {
    stack *s = (stack*)malloc(sizeof(stack));
    initStack(s);

    printf("4 푸시\n");
    push(s, 4);
    printf("6 푸시\n");
    push(s, 6);
    printf("9 푸시\n");
    push(s, 9);

    printf("팝: %d\n", pop(s));
    printf("팝: %d\n", pop(s));
    printf("팝: %d\n", pop(s));

    free(s);

    return 0;
}