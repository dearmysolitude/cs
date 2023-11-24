# Computer Science Practices
## C/C++ 실습 환경
### WSL2
Windows 11의 WSL2을 활용한 Ubuntu 22.04. 컴파일러: GDB. 문서 편집기는 VS Code에 C/C++ 확장기능 사용.

참고: https://code.visualstudio.com/docs/cpp/config-wsl


### AWS EC2 / Ubuntu 환경

난 서버 비용보다 커피가 더 중요해

</br>

## 1. 알고리즘 및 자료구조
KRISS와 Krafton 교육을 바탕으로 작성하였습니다.

참고로, C++로 작성된 알고리즘과 자료구조는(KRISS 공부 내용) 라이브러리로서의 사용성을 고려하지 않고 개념을 이해하기 위해 필요한 기본적인 메서드 구현에만 충실한 코드이니 참고 시 주의할 것.

#### 1-1. 알고리즘
- 정렬
    - [머지소트](./1-1.%20Algorithm/MergeSort.cpp)
    - [퀵소트](./1-1.%20Algorithm/QuickSort.cpp) TODO
    - [쉘소트](./1-1.%20Algorithm/ShellSort.cpp)
    - [버블소트](./1-1.%20Algorithm/BubbleSort.cpp)
    - [힙소트](./1-1.%20Algorithm/HeapSort.cpp)
    - [선택&삽입소트](./1-1.%20Algorithm/Selection&InsertSort.cpp)
- [DFS](./1-1.%20Algorithm/DFS.cpp)
- [Dijkstra](./1-1.%20Algorithm/Dijkstra.cpp)
- [프림](./1-1.%20Algorithm/Prim.cpp)

#### 1-2. 자료구조
- 스택 [C++](./1-2.%20Data%20Structure/Stack.cpp) / [C](./1-2.%20Data%20Structure/Stack.c)
- 선형큐 [C](./1-2.%20Data%20Structure/LinearQueue.c)
- 원형큐 [C++](./1-2.%20Data%20Structure/CircularQueue.cpp) / [C](./1-2.%20Data%20Structure/CircularQueue.c)
- [원형댁](./1-2.%20Data%20Structure/CircularDeque.cpp)
- [이진트리](./1-2.%20Data%20Structure/BinaryTree.cpp)
- [RB 트리](./1-2.%20Data%20Structure/rbtree-lab/) TODO

## 2. Network
- [webproxy-lab](./2.%20Network/webproxy-lab/)
- [Webserver.c](./2.%20Network/Webserver.c)

## 3. OperatingSystem
- [malloc-lab](./3.%20OperatingSystem/malloc-lab/)