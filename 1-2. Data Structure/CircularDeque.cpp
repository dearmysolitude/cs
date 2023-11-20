#include <iostream>
#include <string>
using namespace std;
//함수 변수 선언
const int MAX_QUEUE_SIZE = 10;
typedef int Element;
Element qdata[MAX_QUEUE_SIZE] = { 0 };
int front;
int rear;
void init_queue(Element q[], int& front, int& rear);
int is_Empty(int& front, int& rear);
int is_full(int& front, int& rear);
int size(int& front, int& rear);
void qerror(string msg);
Element delete_front(int& front, int& rear); //delete front
Element peek();
void print_queue(string msg, int& front, int& rear);
//새로이 추가(원형 큐 연산에)
void add_rear(int value, int& front, int& rear);
void add_front(int value, int& front, int& rear);
Element delete_rear(int& front, int& rear);
Element get_rear(int& front, int& rear);

int main()
{
    init_queue(qdata, front, rear);
    for (int i = 1; i < 10; i++)
    {
        if (i % 2 == 1)
            add_front(i, front, rear);
        else add_rear(i, front, rear);
    }
    print_queue("원형 덱 홀수 - 짝수 ", front, rear);
    cout << "delete_front() --> " << delete_front(front, rear) << endl;
    cout << "delete_rear()  --> " << delete_rear(front, rear) << endl;
    cout << "delete_front() --> " << delete_front(front, rear) << endl;
    print_queue("원형 덱 삭제 - 홀짝홀", front, rear);
}

void init_queue(Element q[], int& front, int& rear) // 초기화
{
    front = 0;
    rear = 0;
    q = { 0 };
}
int is_Empty(int& front, int& rear) //empty일 때 1을 반환, 나머지는 0을 반환
{
    if (front == rear)
        return 1;
    else
    {
        return 0;
    }
}
int is_full(int& front, int& rear)
{
    if (((front - rear) +MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE== 1)
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
void add_rear(int value, int& front, int& rear)
{
    if (is_full(front, rear) == 1)
    {
        qerror("덱 포화 에러");
    }
    else
    {
        rear = (rear + 1) % MAX_QUEUE_SIZE;
        qdata[rear] = value;
    }
}
Element delete_front(int& front, int& rear)
{
    if (is_Empty(front, rear) == 1)
        qerror("덱 공백 에러");
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
            qerror("덱 공백 에러");
        }
    }
    else
    {
        return qdata[(front + 1) % MAX_QUEUE_SIZE];
    }
}
void print_queue(string msg, int& front, int& rear)
{
    if (front < rear)
    {
        cout << msg << "  [" << rear - front  + 1 <<  "]  =  ";
        for (int i = front; i <= rear + 1; i++)
        {
            cout << qdata[i] << " ";
        }
    }
    else
    {
        cout << msg << "  [" << 10- front + rear << "]  =  ";
        for (int i = front + 1; i < 10; i++)
        {
            cout << qdata[i] << " ";
        }
        for (int i = 0; i < rear + 1; i++)
        {
            cout << qdata[i] << " ";
        }
    }
    cout << endl;
}
void add_front(int value, int& front,  int& rear)
{
    if (is_full(front, rear) == 1)
        qerror("덱 포화 에러");
    else
    {
        qdata[front] = value;
        front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    }
}
Element delete_rear(int& front,int& rear)
{
    Element ret;
    if (is_Empty(front, rear) == 1)
        qerror("덱 공백 에러");
    ret = qdata[rear];
    rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    return ret;
}
Element get_rear(int& front, int& rear)
{
    if (is_Empty(front, rear) == 1)
        qerror("덱 공백 에러");
    else
        return qdata[rear];
}