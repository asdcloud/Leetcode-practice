#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct card {
   const char *face;
   const char *suit;
};

typedef struct card Card;

void fillDeck(Card * const, const char *[], const char *[]);//�NCARD�H��[]�@��const char�����Х��k�s 
void shuffle(Card * const);// �N�@��Card������const�k�s 
void finalCheck(Card * const, const char*[], const char*[], int &score);//�N[]�@��const char������,const�@��Card������,�q�q�M���A�åB���ƪ����ƥ��L�X��) 

int main(){
    int choice, score = 1, change[6];//�ŧi�ܼ�
    Card deck[52], field[5];
    const char *face[] = {"Ace", "Deuce", "Three",
                            "Four", "Five",
                            "Six", "Seven", "Eight",
                            "Nine", "Ten",
                            "Jack", "Queen", "King"};//�Ʀr1-13 
    const char *suit[] = {"Spades", "Hearts", "Clubs", "Diamonds"}; // ���w�q 

    srand(time(NULL)); //�H���ɶ��ؤl


    while (1){ //�ﶵ�]�� 
        int index = 0;
        printf("Please input a number: "); scanf("%d", &choice);
        if (choice == 1){ //�p�Y��ܤ@ �A�h���Ƴ]�߬�1�A�åB���L�X�ثe�o�� 
            score = 1;
            printf("Your Score: %d\n", score); //���L�{�b�o���A�H�Τ��� 
        }
        else if (choice == 2){ //�p�Y��ܤG�A�h�i��o�P�٦����C�� 
            fillDeck(deck, face, suit);
            shuffle(deck); //�~�P 
            for (int i = 0; i < 5; i++){ // �C�X���i�P�A�ä��O��ܪ��P�I�� 
                printf("%d \t %5s of %-8s%c", i + 1, deck[i].face, deck[i].suit, '\n');
                field[i] = deck[i];
            }
            do { 
                printf("Which card do you want to change?\n"); scanf("%d", &change[index]);//�߰ݭ��i�P�Q���󴫡A �w��Q�󴫪̡A��J�Ǹ�
                index++;
            } while (change[index - 1]); // ���ޭ�
            for (int i = 5; change[i - 5]; i++){
                field[change[i - 5] - 1] = deck[i];
            }
            for (int i = 0; i < 5; i++) printf("%d \t %5s of %-8s%c", i + 1, field[i].face, field[i].suit, '\n');
            finalCheck(field, face, suit, score);
        }
        else if (choice == 3) break;
    }
    printf("Game Over!!!");
    return 0;
}

void fillDeck(Card * const wDeck, const char * wFace[], const char * wSuit[]){
   for (int i = 0; i <= 51; i++) {
      wDeck[i].face = wFace[i % 13];
      wDeck[i].suit = wSuit[i / 13];
   }
}

void shuffle(Card * const wDeck){
   int index;
   Card temp;

   for (int i = 0; i <= 51; i++) {
      index = rand() % 52;
      temp = wDeck[i];
      wDeck[i] = wDeck[index];
      wDeck[index] = temp;
   }
}

void finalCheck(Card * const field, const char * face[], const char * suit[], int &score){
    int checkFace[14] = {0}, checkSuit[4] = {0};
    int flush = 0, straight = 1, ironBranch = 0, sanjo = 0, pairs = 0;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 13; j++){
            if (!strcmp(field[i].face, face[j])){
                if (!j) checkFace[13]++;
                checkFace[j]++;
                break;
            }
        }
        for (int j = 0; j < 4; j++){
            if (!strcmp(field[i].suit, face[j])){
                checkSuit[j]++;
                break;
            }
        }
    }
    for (int i = 0; i < 14; i++)
        if (checkFace[i] && checkFace[i + 1]) straight++;
    for (int i = 0; i < 13; i++){
        if (checkFace[i] == 4) ironBranch++;
        if (checkFace[i] == 3) sanjo++;
        if (checkFace[i] == 2) pairs++;
    }
    for (int i = 0; i < 4; i++){
        if (checkSuit[i] == 5){
            flush++;
            break;
        }
    }
    if (straight == 5 && flush){
        printf("Straight Flush\n");
        score *= 100;
        printf("Your Score: %d\n", score);
    }
    else if (ironBranch){
        printf("Four Of A Kind\n");
        score *= 50;
        printf("Your Score: %d\n", score);
    }
    else if (sanjo && pairs){
        printf("Full House\n");
        score *= 15;
        printf("Your Score: %d\n", score);
    }
    else if (flush){
        printf("Flush\n");
        score *= 10;
        printf("Your Score: %d\n", score);
    }
    else if (straight == 5){
        printf("Straight\n");
        score *= 8;
        printf("Your Score: %d\n", score);
    }
    else if (sanjo){
        printf("Three Of A Kind\n");
        score *= 4;
        printf("Your Score: %d\n", score);
    }
    else if (pairs == 2){
        printf("Two Pair\n");
        score *= 3;
        printf("Your Score: %d\n", score);
    }
    else if (pairs){
        printf("One Pair\n");
        score *= 2;
        printf("Your Score: %d\n", score);
    }
    else{
        printf("No Pair\n");
        score *= 0;
        printf("Your Score: %d\n", score);
    }
}
