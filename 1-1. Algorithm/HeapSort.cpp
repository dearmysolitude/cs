#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//정수 저장 힙의 구현
typedef int HNode; //힙에 저장할 항목의 자료형
//매크로
#define Key(n) (n) //힙 노드 n의 키값

const int MAX_HEAP_NODE = 101; //***전역공간에서 선언-constant
HNode heap[MAX_HEAP_NODE]; //배열을 이용해 구현한 힙(힙노드 배열)
int heap_size; //힙의 크기

//매크로-부모.자식 노드의 주소 접근
#define Parent(i) (heap[i/2]) //부모 노드
#define Left(i) (heap[i*2]) //자식 노드-왼쪽
#define Right(i) (heap[i*2+1]) //자식 노드-오른쪽

//사용하는 멤버 함수들
void print_array(int data[], int heap_size, const char msg[]);
void init_heap();
void insert_heap(HNode n);
int is_full_heap();
HNode delete_heap();
int is_empty_heap();
void print_array(int data[], int heap_size, const char msg[]);

//진입점
int main()
{
    int i, data1[10]; //데이터는 구현한 힙 데이터와는 별개임*
    srand((unsigned int)time(NULL)); //난수 초기화(현재 시간으로)
    for (i = 0; i < 10; i++)
        data1[i] = rand() % 100;
    print_array(data1, 10, "정렬 전");

    init_heap();
    for (i = 0; i < 10; i++)
        insert_heap(data1[i]);
    for (i = 9; i >= 0; i--)
        data1[i] = Key(delete_heap());
    print_array(data1, 10, "정렬 후");
    return 0;
}

//멤버 함수들
void init_heap() {
    heap_size = 0;
    return;
}

int is_full_heap() {
    if (heap_size == MAX_HEAP_NODE - 1) return 1;
}

int is_empty_heap() {
    if (heap_size == 0) return 1;
}

void insert_heap(HNode n) //삽입
{

    int i;
    if (is_full_heap()) return;
    
    i = ++(heap_size);
    while (i != 1 && Key(n) < Key(Parent(i))) {
        heap[i] = Parent(i);
        i /= 2;
    }
    heap[i] = n;

}

HNode delete_heap() { //삭제
    HNode hroot=heap[1], last;
    int parent = 1, child = 2;
    if (!is_empty_heap()) {
        hroot = heap[1];
        last = heap[heap_size--];
        while (child <= heap_size) {
            if (child < heap_size && (Key(Left(parent)) > Key(Right(parent))))
                child++;

            if (Key(last) <= Key(heap[child])) break;

            heap[parent] = heap[child];
            parent = child;
            child *= 2;
        }
        heap[parent] = last;
    }
    return hroot;
}

void print_array(int data[], int heap_size, const char msg[])
{
    int i;
    
    cout << msg << ": ";

    for (i = 0; i < heap_size; i++) {
        cout << " " << data[i] << " ";
    }

    cout << "\n";
    return;
}