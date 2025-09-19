#include <stdio.h>
#include <stdlib.h> // malloc, free 함수
#include <conio.h>  // getch 함수

// 스택 노드의 구조체 정의
struct stack_node {
    char data;
    struct stack_node *link;
};

// 함수 원형 선언
void push(char data);
char pop(void);

// 스택의 가장 위를 가리키는 전역 포인터
struct stack_node *top = NULL;

int main(void) 
{
    int count = 0;
    char key;

    printf("문자를 입력하면 스택에 push 됩니다. (종료: ESC)\n");

    do {
        count++;
        printf("%2d 번 문자입력 > ", count);
        key = getch(); // 사용자로부터 한 글자 입력받음

        if (key != 27) { // ESC 키가 아니면 스택에 push
            push(key);
            printf("%c\n", key);
        }

    } while (key != 27); // ESC(ASCII 27) 키를 누르면 종료

    printf("\n\n");
    printf("데이터 pop과정\n");

    // 스택이 빌 때까지 pop하여 출력
    while (top != NULL) 
    {
        key = pop();
        printf("%c ", key);
    }

    printf("\n\n");
    return 0;
}

/**
 * @brief 스택에 데이터를 삽입(push)하는 함수
 */
void push(char data) 
{
    struct stack_node *new_node;
    new_node = (struct stack_node*)malloc(sizeof(struct stack_node));
    
    new_node->data = data;
    new_node->link = top; // 새 노드가 현재 top을 가리키게 함
    top = new_node;       // top을 새 노드로 변경
}

/**
 * @brief 스택에서 데이터를 삭제(pop)하고 반환하는 함수
 */
char pop(void) 
{
    // 스택이 비어있으면 오류 처리 (실제로는 더 견고하게 만들어야 함)
    if (top == NULL) {
        printf("Stack is empty!\n");
        return -1;
    }

    struct stack_node *temp;
    char data;

    data = top->data;     // top의 데이터를 임시 저장
    temp = top;           // 현재 top을 임시 저장
    top = top->link;      // top을 한 칸 아래로 내림
    free(temp);           // 이전 top의 메모리 해제
    
    return data;          // 데이터 반환
}