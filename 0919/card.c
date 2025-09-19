#include <stdio.h>
#include <string.h>

struct trump {
    char order;
    char shape[4];     // UTF-8 문자 저장용
    char number[3];    // "10"까지 저장 가능
};

void make_card(struct trump m_card[]) {
    int i, j;
    char shape[4][4] = {"♠", "◆", "♥", "♣"};

    for (i = 0; i < 4; i++) {
        for (j = i * 13; j < i * 13 + 13; j++) {
            m_card[j].order = i;
            strcpy(m_card[j].shape, shape[i]);

            int num = j % 13 + 1;
            switch (num) {
                case 1:
                    strcpy(m_card[j].number, "A");
                    break;
                case 11:
                    strcpy(m_card[j].number, "J");
                    break;
                case 12:
                    strcpy(m_card[j].number, "Q");
                    break;
                case 13:
                    strcpy(m_card[j].number, "K");
                    break;
                default:
                    sprintf(m_card[j].number, "%d", num);
                    break;
            }
        }
    }
}

void print_deck(struct trump m_card[]) {
    for (int i = 0; i < 52; i++) {
        printf("%s%s ", m_card[i].shape, m_card[i].number);
        if ((i + 1) % 13 == 0) printf("\n");
    }
}

int main() {
    struct trump deck[52];
    make_card(deck);
    print_deck(deck);
    return 0;
}