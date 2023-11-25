# Data Structure 구현 로그

## Stack

### [with C](Stack.c)
#### 구현
- Stack과 Node struct를 새로운 type으로 typedef하였다.
- 노드가 추가될 때마다 노드를 동적으로 할당하였음.
- 노드의 pop/push는 항상 Stack의 top에서 이루어졌으며, 각각 malloc과 free로 메모리 할당이 이루어지게 구현하였음.
- 마지막에 동적으로 할당되었던 메모리를 일괄적으로 해제하는 메서드 freeRemaining을 추가
- empty일 때 pop할 경우에 메세지만 출력하고 아무것도 하지 않음.
- 최대 길이는 설정하지 않았다.

#### freeRemaining 관련 이슈
- 처음에는 끝단을 분리하여 처리하여 번거로움을 줄이고자 하였으나(stack에 아무것도 없는 경우/아닌 경우)
- doFree 메서드가 현재의 할당노드를 NULL한지 판단하여 아니라면 재귀하고 NULL일 경우는 아무런 일도 하지 않도록 하도록 변경하여 코드가 더 간결해질 수 있었다(스택 자체의 작동이 간단하여 가능했다).

### [with C++: 교과서](Stack.cpp)
- list를 사용하였고 동적 할당은 활용하지 않음.
- full하거나 empty할 때에 오류를 발생시키고 프로그램을 종료시켰다.
- 다양한 역할을 하는 메서드들을 분리하여 각각 구현하였다.

## Linear Queue

### [with C](LinearQueue.c)
#### 구현
- Stack.cpp과 Stack.c의 내용을 종합하여 구현하였다.
- MAX_QUEUE_SIZE 설정
- Queue의 Node 숫자를 재귀 함수를 통해 세도록 하였다.
- 에러 메세지 출력 메서드
- 센티넬을 stack 구조체 내에 할당하여 스택이 비어있는지 아닌지 판단하는데 사용하였다.
- freeRemaining 메서드로 남아있는 모든 메서드를 free하였다: 역시 재귀함수를 사용

#### 발생 이슈
Sentinel을 사용하는 것이 메모리 할당을 해제할 때 예외를 발생시켰다: **Segmentation fault**

→ freeRemaining 메서드가 Sentinel에 도달했을 때 제대로 된 처리가 되지 않아 잘못된 메모리 구역을 free하는 경우가 발생하였기 때문.

## [Circular Queue]

### [with C]

### [with C++]

## Circular Dequeue

### with C

### with C++
