#include <iostream>
#include <string>
using namespace std;

//함수 변수 선언
const int MAX_QUEUE_SIZE = 100;
typedef int Element;
Element qdata[MAX_QUEUE_SIZE] = { 0 };
int front;
int rear;

//함수 선언
void init_queue(Element q[], int& front, int& rear);
int is_Empty(int& front, int& rear);
int is_full(int& front, int& rear);
int size(int& front, int& rear);
void qerror(string msg);
void enqueue(int value, int& rear);
Element dequeue(int& front, int& rear);
Element peek();
void print_queue(string msg);

int main()
{
    int i;
    init_queue(qdata, front, rear);
    for (int i = 1; i < 10; i++)
        enqueue(i, rear);
    print_queue("선형큐 enqueue 9회");
    cout << "dequeue() --> " << dequeue(front, rear) << endl;
    cout << "dequeue() --> " << dequeue(front, rear) << endl;
    cout << "dequeue() --> " << dequeue(front, rear) << endl;
    print_queue("선형큐 dequeue 3회");
}

void init_queue(Element q[], int& front, int& rear) // 초기화
{
    front = 0;
    rear = 0;
    q = {0};
}

int is_Empty(int& front, int& rear) //empty일 때 1을 반환, 나머지는 0을 반환
{
    if(front == 0 && rear == 0)
        return 1;
    else
    {
        return 0;
    }
}

int is_full(int& front, int& rear)
{
    if (front == 0 && rear == MAX_QUEUE_SIZE)
        return 1;
    else
    {
        return 0;
    }
}

int size(int& front, int& rear)
{
    return ((rear - front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE);
}
void qerror(string msg)
{
    cout << msg << endl;
    exit(1);
}
void enqueue(int value, int& rear)
{
    if (is_full(front, rear) == true)
    {
        qerror("큐 포화 에러");
    }
    else
    {
        rear = (rear + 1) % MAX_QUEUE_SIZE;
        qdata[rear] = value;
    }
}
Element dequeue(int& front, int&rear)
{
    if (is_Empty(front, rear) == 1)
    {
        {
            qerror("큐 공백 에러");
        }
    }
    else
    {
        front = (front + 1) % MAX_QUEUE_SIZE;
        return qdata[front];
    }
}
Element peek()
{
    if (is_Empty(front, rear) == 1)
    {
        {
            qerror("큐 공백 에러");
        }
    }
    else
    {
        return qdata[(front + 1) % MAX_QUEUE_SIZE];
    }
}
void print_queue(string msg)
{
    cout << msg << "  [" << rear - front << "]  =  ";
    for (int i = front+1; i < rear + 1; i++)
    {
        cout << qdata[i] << " ";
    }
    cout << endl;
}