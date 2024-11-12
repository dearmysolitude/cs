# Computer Science Practices

구현이 덜 된 webproxy와 rbtree 다시 작성 예정

## C/C++ 실습 환경
### WSL2
Windows 11의 WSL2을 활용한 Ubuntu 22.04. 컴파일러: GDB. 문서 편집기는 VS Code에 C/C++ 확장기능 사용.

참고: https://code.visualstudio.com/docs/cpp/config-wsl

- Webproxy-lab 에서 발생하는 `bits/libc-header-start.h: No such file or directory`문제는 64비트 운영체제에서 32비트로 컴파일하려고 하기때문에 발생한다. `sudo apt-get install gcc-multilib g++-multilib`를 통해 해결할 수 있다.

### AWS EC2 / Ubuntu 환경

### VMware 가상화 / Ubuntu 환경

## 1. 알고리즘 및 자료구조
KRISS와 Krafton 교육을 바탕으로 작성하였습니다.

참고로, C++로 작성된 알고리즘과 자료구조는(KRISS 공부 내용) 라이브러리로서의 사용성을 고려하지 않고 개념을 이해하기 위해 필요한 기본적인 메서드 구현에만 충실한 코드이니 참고 시 주의할 것.

#### 1-1. [알고리즘](./1-1.%20Algorithm/)
- 정렬
    - 머지소트
    - 퀵소트 TODO
    - 쉘소트
    - 버블소트
    - 힙소트
    - 선택&삽입소트
- DFS
- Dijkstra
- 프림

#### 1-2. [자료구조](1-2.%20Data%20Structure/)
- 스택 
- 선형큐
- 원형큐
- 원형댁
- 이진트리
- [RB 트리] TODO

## 2. [Network](2.%20Network/)
- webproxy-lab
- Webserver.c

## 3. [OperatingSystem](3.%20OperatingSystem/)
- malloc-lab