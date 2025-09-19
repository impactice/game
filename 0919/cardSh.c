#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 카드 한 장의 정보를 담는 구조체
struct trump {
    int order;        // 무늬 (0:♠, 1:◆, 2:♥, 3:♣)
    char shape[3];    // 무늬 기호
    int number;       // 카드 숫자 (A, 2~10, J, Q, K)
};

// 함수 원형 선언
void make_card(struct trump m_card[]);
void display_card(struct trump m_card[]);
void shuffle_card(struct trump m_card[]);

// 메인 함수
int main(void) 
{
    // 랜덤 시드 초기화 (매번 다른 순서로 섞기 위함)
    srand(time(NULL));

    struct trump card[52]; // 52장의 카드 덱 생성

    make_card(card);      // 1. 순서대로 카드 생성
    shuffle_card(card);   // 2. 카드 섞기
    display_card(card);   // 3. 섞인 결과 출력

    return 0;
}

/**
 * @brief 52장의 트럼프 카드를 순서대로 생성하는 함수
 * @param m_card 카드 덱 배열
 */
void make_card(struct trump m_card[]) 
{
    int i, j;
    char shape[4][3] = {"♠", "◆", "♥", "♣"};

    for (i = 0; i < 4; i++) 
    {
        for (j = i * 13; j < i * 13 + 13; j++) 
        {
            m_card[j].order = i;
            strcpy(m_card[j].shape, shape[i]);
            m_card[j].number = j % 13 + 1;

            // 숫자 1, 11, 12, 13을 A, J, Q, K 문자로 변환
            switch (m_card[j].number) 
            {
                case 1:
                    m_card[j].number = 'A';
                    break;
                case 11:
                    m_card[j].number = 'J';
                    break;
                case 12:
                    m_card[j].number = 'Q';
                    break;
                case 13:
                    m_card[j].number = 'K';
                    break;
            }
        }
    }
}

/**
 * @brief 카드 덱의 순서를 무작위로 섞는 함수 (피셔-예이츠 셔플 알고리즘)
 * @param m_card 카드 덱 배열
 */
void shuffle_card(struct trump m_card[]) 
{
    int i, rand_idx;
    struct trump temp; // 카드를 임시로 저장할 변수

    for (i = 51; i > 0; i--) 
    {
        // 0부터 i까지의 범위에서 무작위 인덱스 선택
        rand_idx = rand() % (i + 1);

        // 현재 카드(i)와 무작위로 선택된 카드(rand_idx)를 교환
        temp = m_card[i];
        m_card[i] = m_card[rand_idx];
        m_card[rand_idx] = temp;
    }
}

/**
 * @brief 52장의 카드를 화면에 출력하는 함수
 * @param m_card 카드 덱 배열
 */
void display_card(struct trump m_card[]) 
{
    int i;
    for (i = 0; i < 52; i++) 
    {
        // 무늬 출력
        printf("%s", m_card[i].shape);

        // 숫자 또는 문자 출력
        if (m_card[i].number > 10) // 'A', 'J', 'Q', 'K'인 경우
        {
            printf("%c\t", (char)m_card[i].number);
        }
        else // 2 ~ 10인 경우
        {
            printf("%d\t", m_card[i].number);
        }

        // 13장마다 줄바꿈
        if ((i + 1) % 13 == 0) 
        {
            printf("\n");
        }
    }
}