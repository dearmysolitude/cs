#include <iostream>
#include <string>

using namespace std;

//스택
// 상수 선언: 전역 변수로, 대문자 사용
const int MAX_STACK_SIZE = 10;

//자료형 선언
typedef int Element;
Element datastack[MAX_STACK_SIZE];
int top = -1; //초기화값: 스택 현재 상태

// 메서드 선언
Element pop(int& top);
Element peek();
void push(int e, int& top);
void init_stack(Element datastack[]);
int size(int& top);
bool is_Empty(int& top);
bool is_full(int& top);
void error(int errnum);
void print_stack(string msg);

int main()
{
    int i;

    //stack 초기화: 
    init_stack(datastack);
    cout << "스택 초기화: Done" << endl;
    cout << endl;

    cout << "Stack에 숫자 넣는 중" << endl;
    //스택 조작: push 1부터 9까지 넣기
    for (i = 0; i < 10; i++)
        push(i, top);
    print_stack("스택 push 9회 done: ");
    cout << endl;

    //스택 조작: pop 3번
    cout << "pop() --> " << pop(top) << endl;
    cout << "pop() --> " << pop(top) << endl;
    cout << "pop() --> " << pop(top) << endl;
    print_stack("스택 pop 3회 done: ");
    cout << endl;

    return 0;
}

void push(int e, int& top)
{
    if (is_full(top) == true)
        error(0);
    else
    {
        datastack[++ top] = e;
    }
}

Element pop(int& top)
{
    if (is_Empty(top) == true){
        error(1);
    }
    else
        return datastack[top--];
}

void init_stack(Element datastack[])
{
    for (int i = 0; i < 10; i++)
    {
        datastack[i] = {0};
    }
}
int size(int& top)
{
    return (top+1);
}

bool is_Empty(int& top)
{
    if (top == -1)
        return 1;
    else
        return 0;
}
bool is_full(int& top)
{
    if (top == MAX_STACK_SIZE - 1)
        return 1;
    else
        return 0;
}
Element peek()
{
    if (is_Empty(top) == true)
        error(1);
    return datastack[top];
}

void error(int errnum) //error num를 받아서 어떤 종류의 에러인지 구분하고 그에 따라 메세지 출력
{
    if (errnum == 0)
    {
        cout << "스택 포화 에러" << endl;
        exit(1);
    }
    else if (errnum == 1)
    {
        cout << "스택 공백 에러" << endl;
        exit(1);
    }
}
void print_stack(string msg) //입력된 메세지를 출력하는 함수
{
    const int a = size(top);
    cout << msg << "  [" << a-1 << "]  =  ";
    for (int i = 1; i < a; i++)
    {
        cout << datastack[i] << " ";
    }
    cout << endl;
}