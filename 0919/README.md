# 카드, 피아노, 자료구조 등을 구현 
# 🎮 게임 프로그래밍 (C 언어 응용)

> 경성대학교 강의자료 기반 정리  

이 자료는 **C 언어를 이용한 게임 프로그래밍 응용**을 다룹니다.  
트럼프 카드 프로그램, 음계 출력, 데이터 구조(연결 리스트/스택)와 같은 응용 모듈 예제를 포함합니다.  

---

## 📑 목차
- [📌 학습 내용](#-학습-내용)
- [🃏 카드 프로그래밍](#-카드-프로그래밍)
- [🎵 음계와 피아노 건반](#-음계와-피아노-건반)
- [🔗 자료 구조](#-자료-구조)
- [📖 참고 자료](#-참고-자료)

---

## 📌 학습 내용

- **카드 프로그래밍**
  - 구조체를 이용한 카드 표현
  - 카드 섞기 알고리즘 (난수 활용)
- **음계와 소리 출력**
  - 옥타브와 12평균율
  - 주파수를 계산하여 `Beep` 함수로 출력
  - 숫자 키 입력 → 해당 음 출력
- **자료 구조 응용**
  - 연결 리스트 (게임 Replay 기능)
  - 스택 (수건 더미, 카드 게임 예시)
  - 동적 메모리 관리 (`malloc`, `free`)
  - 문자열 정렬 (대소문자 변환 후 정렬)

---

## 🃏 카드 프로그래밍

### 카드 구조체 정의
```c
typedef struct {
    int order;     // 카드 순위
    char shape[4]; // 카드 모양 (♠ ◆ ♥ ♣)
    char number[3];// 숫자 또는 문자 (A,2~10,J,Q,K)
} Card;
```

### 카드 섞기 (방법 2)
```c
void shuffle(Card *deck, int n) {
    int i, rnd;
    Card temp;
    for(i=0; i<n; i++) {
        do {
            rnd = rand() % n;
        } while (rnd == i);
        temp = deck[i];
        deck[i] = deck[rnd];
        deck[rnd] = temp;
    }
}
```

---

## 🎵 음계와 피아노 건반

### 옥타브와 주파수
- 기준: **A (라) = 440Hz**
- 12평균율 → 한 옥타브를 12개 반음으로 분할  
- 각 음의 주파수 = `440 * pow(2, n/12)`  

### 주파수 계산 함수
```c
int index[] = {0, 2, 4, 5, 7, 9, 11, 12};

int calc_frequency(int octave, int idx) {
    double base = 32.7032; // 옥타브 1의 도(C)
    return (int)(base * pow(2, octave-1 + index[idx]/12.0));
}
```

### Beep 함수 활용
```c
#include <windows.h>
#include <math.h>

int main(void) {
    int i;
    int freq[] = {261, 293, 329, 349, 392, 440, 493, 523}; // 도~도
    for(i=0;i<8;i++) {
        Beep(freq[i], 500); // 0.5초
    }
    return 0;
}
```

---

## 🔗 자료 구조

### 연결 리스트 (게임 Replay 응용)
```c
typedef struct Node {
    char key;
    struct Node *next;
} Node;

Node *head = NULL;

void insert(char key) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = head;
    head = newNode;
}
```

### 스택 (카드 더미 예시)
```c
typedef struct Node {
    int data;
    struct Node *link;
} Node;

Node *top = NULL;

void push(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = top;
    top = newNode;
}

int pop() {
    if(top == NULL) return -1;
    int data = top->data;
    Node *temp = top;
    top = top->link;
    free(temp);
    return data;
}
```

---

## 📖 참고 자료

- [카드 섞기](https://yeolco.tistory.com/64)  
- [옥타브와 주파수](https://jaimemin.tistory.com/212)  
- [루트 제곱근 계산](https://manniz.tistory.com/entry/C%EC%96%B8%EC%96%B4-%EB%A3%A8%ED%8A%B8%EC%A0%9C%EA%B3%B1%EA%B7%BC-%EC%9D%84-%EA%B5%AC%ED%95%98%EB%8A%94-2%EA%B0%80%EC%A7%80-%EB%B0%A9%EB%B2%95sqrt-pow-%EC%86%8C%EC%8A%A4-%EC%BD%94%EB%93%9C)  
- [자료 구조 개요](https://e-koreatech.step.or.kr)  
- [동적 메모리 관리](https://dojang.io/mod/page/view.php?id=285)  
- [연결 리스트 구현](https://claude-u.tistory.com/72)  
- [시각화 도구 (Visualgo)](https://visualgo.net/)  
- *명품 C언어 프로젝트* (생능출판, 안기수)  

---
