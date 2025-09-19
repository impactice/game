#include <stdio.h>
#include <stdlib.h> // malloc, free 함수 사용
#include <conio.h>  // getch 함수 사용

// 연결 리스트 노드 구조체 정의
struct linked_list {
    char data;
    struct linked_list *link;
};

// 함수 원형 선언
void add_node(char data);
void print_linked_list(struct linked_list *now);
void print_reverse_linked_list(struct linked_list *now);

// 전역 변수로 head 포인터 선언
struct linked_list *head;

int main(void) 
{
    int count = 0;
    char key;

    // head 노드 초기화
    head = (struct linked_list*)malloc(sizeof(struct linked_list));
    head->link = NULL;

    do {
        count++;
        printf("%2d번째 문자입력 > ", count);
        key = getch(); // 사용자로부터 한 글자 입력받음
        
        if (key != 27) { // ESC 키가 아니면 노드 추가
            add_node(key);
            printf("%c\n", key);
        }

    } while (key != 27); // ESC(ASCII 27) 키를 누르면 종료

    printf("\n\n");
    printf("입력된 순서 : ");
    print_linked_list(head->link); // head는 비어있으므로 head->link 부터 시작

    printf("\n");
    printf("입력의 역순 : ");
    print_reverse_linked_list(head->link);

    printf("\n\n");
    
    // 메모리 해제 (생략되었지만 좋은 습관)
    struct linked_list *current = head;
    struct linked_list *next_node;
    while(current != NULL) {
        next_node = current->link;
        free(current);
        current = next_node;
    }

    return 0;
}

// 리스트 끝에 노드를 추가하는 함수
void add_node(char data) 
{
    struct linked_list *new_node, *last;
    last = head;

    // 마지막 노드를 찾음
    while (last->link != NULL) 
    {
        last = last->link;
    }

    new_node = (struct linked_list*)malloc(sizeof(struct linked_list));
    new_node->data = data;
    new_node->link = NULL; // 새 노드가 마지막 노드가 됨
    last->link = new_node; // 기존 마지막 노드에 새 노드를 연결
}

// 리스트를 순서대로 출력하는 함수
void print_linked_list(struct linked_list *now) 
{
    while (now != NULL) 
    {
        printf("%c ", now->data);
        now = now->link;
    }
}

// 리스트를 역순으로 출력하는 함수 (재귀 사용)
void print_reverse_linked_list(struct linked_list *now) 
{
    if (now == NULL) { // 리스트가 비었으면 종료
        return;
    }

    if (now->link != NULL) 
    {
        // 다음 노드로 재귀 호출을 먼저 함
        print_reverse_linked_list(now->link);
    }
    // 재귀 호출이 끝난 후 현재 노드의 데이터를 출력
    printf("%c ", now->data);
}