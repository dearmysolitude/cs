#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int MAX_DEQUE_SIZE = 10;
typedef int Element;
typedef struct Deque {
    struct Node *sentinel_front;
    struct Node *sentinel_rear;
} Deque;
typedef struct Node {
    struct Node *next;
    struct Node *prev;
    Element element;
} Node;

void init_deque(Deque *d);
void init_sentinel(Deque *n);
bool is_empty(Deque *d);
bool is_full(Deque *d);
void d_error(int i);
void push_right(Deque *d, int input);
void push_left(Deque *d, int input);
Element pop_right(Deque *d);
Element pop_left(Deque *d);
void print_deque(Deque *d);
void free_remaining(Deque *d);
int size(Deque *d);

void main() {
    Deque *d = (Deque*)malloc(sizeof(Deque));
    init_deque(d);

    print_deque(d);

    push_left(d, 4);
    print_deque(d);

    push_left(d, 6);
    print_deque(d);

    push_right(d, 2);
    print_deque(d);

    push_right(d, 1245);
    push_right(d, 24);

    for(int i = 0; i < 5; i++) {
        push_left(d, i*10);
        print_deque(d);
    }

    printf("pop: %d\n", pop_left(d));

    printf("pop: %d\n", pop_right(d));

    print_deque(d);

    free_remaining(d);

}

void init_deque(Deque *d) {

    d->sentinel_front = (Node*)malloc(sizeof(Node));
    d->sentinel_rear = (Node*)malloc(sizeof(Node));

    init_sentinel(d);

    return;
}

void init_sentinel(Deque *d) {
    
    d->sentinel_front->element = 0;
    d->sentinel_front->next = d->sentinel_rear;
    d->sentinel_rear->prev = d->sentinel_front;
    d->sentinel_rear->element = 0;

    return;
}

bool is_empty(Deque *d) {
    if(d->sentinel_front->next == d->sentinel_rear) {
        return true;
    }
    return false;
}

bool is_full(Deque *d) {
    if(size(d) == MAX_DEQUE_SIZE) {
        return true;
    }
    return false;
}

int size(Deque *d) {
    int count = 0;
    Node* pointer = d->sentinel_front;
    while(true) {
        pointer = pointer->next;

        if(pointer == d->sentinel_rear) {
            break;
        }

        count ++;
    }
    return count;
}

void push_left(Deque *d, int input) {
    if(is_full(d)) {
        d_error(2);
        return;
    }

    Node *new_node = (Node*)malloc(sizeof(Node));

    new_node->element = input;

    d->sentinel_front->next->prev = new_node;
    new_node->next = d->sentinel_front->next;
    new_node->prev = d->sentinel_front;
    d->sentinel_front->next = new_node;

    printf("push left: %d\n", input);
}

void push_right(Deque *d, int input) {
    if(is_full(d)) {
        d_error(2);
        return;
    }

    Node *new_node = (Node*)malloc(sizeof(Node));

    new_node->element = input;

    d->sentinel_rear->prev->next = new_node;
    new_node->prev = d->sentinel_rear->prev;
    new_node->next = d->sentinel_rear;
    d->sentinel_rear->prev = new_node;

    printf("push right: %d\n", input);
}

Element pop_right(Deque *d) {
    if(is_empty(d)) {
        d_error(1);
        return;
    }
    Node *pop_node = d->sentinel_rear->prev;
    Element output = pop_node->element;

    d->sentinel_rear->prev = d->sentinel_rear->prev->prev;
    d->sentinel_rear->prev->next = d->sentinel_rear;

    free(pop_node);

    printf("pop right: %d\n", output);
    return output;
}

Element pop_left(Deque *d) {
    if(is_empty(d)) {
        d_error(1);
        return;
    }

    Node *pop_node = d->sentinel_front->next;
    Element output = pop_node->element;

    d->sentinel_front->next = d->sentinel_front->next->next;
    d->sentinel_front->next->prev = d->sentinel_front;

    free(pop_node);

    printf("pop left: %d\n", output);
    return output;
}

void d_error(int i) {
    if (i == 1) {
        printf("덱이 비어있습니다.");
        exit(1);
    } else if(i == 2) {
        printf("덱이 가득 차 있습니다.");
        exit(1);
    }
}

void print_deque(Deque *d) {
    Node *pointer = d->sentinel_front->next;

    printf("현재 덱의 상태: ");

    if(is_empty(d)) {
        printf("비어있습니다.\n");
        return;
    }

    while(pointer != d->sentinel_rear->prev) {
        printf("%d ", pointer->element);
        pointer = pointer->next;
    }

    printf("%d\n", pointer->element);

    return;
}

void free_remaining(Deque *d) {

    if(!is_empty(d)) {
        Node *pointer = d->sentinel_front->next;

        while(pointer != d->sentinel_rear) {
            pointer = pointer->next;
            free(pointer->prev);
        }

    }

    free(d->sentinel_front);
    free(d->sentinel_rear);

    free(d);

    return;
}