# Data Structure 구현 로그

## Stack

선형 데이터구조로, LIFO/FILO순서를 따른다. pop연산과 push연산을 하며, 배열/연결 리스트를 사용하여 구현할 수 있다.

### C
[구현](Stack.c)

- Stack과 Node struct를 새로운 type으로 typedef하였다.
- 노드가 추가될 때마다 노드를 동적으로 할당하였음.
- 노드의 pop/push는 항상 Stack의 top에서 이루어졌으며, 각각 malloc과 free로 메모리 할당이 이루어지게 구현하였음.
- 마지막에 동적으로 할당되었던 메모리를 일괄적으로 해제하는 메서드 freeRemaining을 추가
- empty일 때 pop할 경우에 메세지만 출력하고 아무것도 하지 않음.
- 최대 길이는 설정하지 않았다.

freeRemaining 관련 이슈
- 처음에는 끝단을 분리하여 처리하여 번거로움을 줄이고자 하였으나(stack에 아무것도 없는 경우/아닌 경우)
- doFree 메서드가 현재의 할당노드를 NULL한지 판단하여 아니라면 재귀하고 NULL일 경우는 아무런 일도 하지 않도록 하도록 변경하여 코드가 더 간결해질 수 있었다(스택 자체의 작동이 간단하여 가능했다).

### C++: 교과서
[구현](Stack.cpp)
- list를 사용하였고 동적 할당은 활용하지 않음.
- full하거나 empty할 때에 오류를 발생시키고 프로그램을 종료시켰다.
- 다양한 역할을 하는 메서드들을 분리하여 각각 구현하였다.

</br>

## Queue

FIFO 원칙을 따른다. Enqueue/Dequeue연산을 지원한다. 배열을 사용하여 구현하기도 하지만, 연결리스트를 사용하여 구현하기도 한다.

### Linear Queue: C
[구현](LinearQueue.c)
- Stack.cpp과 Stack.c의 내용을 종합하여 구현하였다.
- MAX_QUEUE_SIZE 설정
- Queue의 Node 숫자를 재귀 함수를 통해 세도록 하였다.
- 에러 메세지 출력 메서드
- 센티넬을 stack 구조체 내에 할당하여 스택이 비어있는지 아닌지 판단하는데 사용하였다.
- freeRemaining 메서드로 남아있는 모든 메서드를 free하였다: 역시 재귀함수를 사용

발생 이슈

Sentinel을 사용하는 것이 메모리 할당을 해제할 때 예외를 발생시켰다: **Segmentation fault**

→ freeRemaining 메서드가 Sentinel에 도달했을 때 제대로 된 처리가 되지 않아 잘못된 메모리 구역을 free하는 경우가 발생하였기 때문.

### Circular Queue: C
[구현](CircularQueue.c)
- Linear queue와는 다르게 리스트로 구현하였다: 정적할당
- front와 rear는 리스트의 index를 가르키는 int이고, circular queue이므로 숫자를 다룰 때 % MAX_QUEUE_SIZE가 요긴하게 사용되었다: 해당 연산을 통해 MAX_QUQUE_SIZE 내의 숫자로만 index가 돌도록 조작할수 있다.
- Circular QUEUE의 경우에는 MAX_QUEUE_SIZE보다 하나 작은 갯수의 요소를 가지게 하여 front와 rear가 같은 곳을 가르키는 원소가 하나도 없는 경우와 구분하게 한다.

### Circular Queue: C++
[구현](CircularQueue.cpp)
- 교재대로 구현한 circular queue
- 리스트의 선언과 동시에 초기화하는 C++ 만의 문법을 C에서는 사용할 수 없다는 것을 처음 발견한 코드
    - { 0 }과 같은 일괄 초기화는 C에서는 사용할 수 없다.
    - C에서는 선언과 동시에 초기화가 이루어져야 한다.
    - C++은 C보다 엄격한 타입 검사를 하며, 배열 크기는 타입의 일부로, 컴파일 시점에 알려져야 한다: 선언과 초기화 분리 가능

</br>

## Deque

Deque은 앞/뒤에서 데이터를 push/pop할 수 있는 기능을 제공하는 자료구조이다. 이중 연결 리스트나 배열을 통해 구현한다.

</br>

### Linear Dequeu: C

### Circular Dequeu: C++
[구현](CircularDeque.cpp)
- 배열을 통해 일정 크기의 데이터를 관리하는 원형덱의 형태로 구현하였다.
- 배열의 인덱스를 덱의 요소에 접근하는 방법으로 사용하였다.
- 동적할당 없음. Circular로 순환하는 것은 배열의 인덱스 크기로 나눈 나머지를 사용하여 배열 내에서 순환하도록 하였다.

