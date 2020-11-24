#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

typedef enum {
    false,
    true
} bool;

bool handle_quit() {
    char quit = 0;
    scanf("%c", &quit);
    if (quit == 'q') {
        printf("Quitting...");
        return true;
    }
    return false;
}

int x;
char r[6]= "";
char a[]= "A";
char tw[]= "2";
char tr[]= "3";
char fo[]= "4";
char fi[]= "5";
char si[]= "6";
char se[]= "7";
char e[]= "8";
char n[]= "9";
char te[]= "10";
char j[]= "J";
char Q[]= "Q";
char k[]= "K";

char suit[6]= "";
char d[]= "D";
char c[]= "C";
char h[]= "H";
char s[]= "S";
char YES;


void printRandoms(int lower, int upper,
                  int count)
{
    int i;
    for (i = 0; i < count; i++) {
        int num = (rand() %
                   (upper - lower + 1)) + lower;

        if (num == 1) {
            strcpy(r,a);
        }
        else if (num == 2) {
            strcpy(r,tw);
        }
        else if (num == 3) {
            strcpy(r,tr);
        }
        else if (num == 4) {
            strcpy(r,fo);
        }
        else if (num == 5) {
            strcpy(r,fi);
        }
        else if (num == 6) {
            strcpy(r,si);
        }
        else if (num == 7) {
            strcpy(r,se);
        }
        else if (num == 8) {
            strcpy(r,e);
        }
        else if (num == 9) {
            strcpy(r,n);
        }
        else if (num == 10) {
            strcpy(r,te);
        }
        else if (num == 11) {
            strcpy(r,j);
        }
        else if (num == 12) {
            strcpy(r,Q);
        }
        else if (num == 13) {
            strcpy(r,k);

        }
        else {
            printf("Please Choose valid Card");
        }
    }

}

void chooseRandoms(int min, int max, int load)
{
    int i;
    for (i = 0; i < load; i++) {
        int num1 = (rand() %
                    (max - min + 1)) + min;

        if (num1 == 1) {
            strcpy(suit,d);
        }
        else if (num1 == 2) {
            strcpy(suit,c);
        }
        else if (num1 == 3) {
            strcpy(suit,h);
        }
        else if (num1 == 4) {
            strcpy(suit,s);
        }
        else {
            printf("Please Choose valid Card");
        }
    }
}

int main()

{
    printf("\n\n\t\t\t\t\tLets Play the Random Card game\n\n\n");
    printf("Press q at any time to quit the Game\n");
    printf("Press Enter to Start\n\n");
    if (handle_quit()) {
        return 0;
    }
    char guess[20];
    char sguess[20];

    int lower = 10, upper = 13, count = 1;
    int min = 1, max = 4, load = 1;
    srand(time(0));

    printRandoms(lower, upper, count);
    chooseRandoms(min, max, load);
    char y;
    while(YES == y) {

        for (int i = 2; ;i--) {
            printf("Choose the Card\n");
            scanf("%s", guess);
            printf("Choose the Suit\n");
            scanf("%s", sguess);
            int rc = strcmp(r, guess);
            int sc = strcmp(suit, sguess);
            {

                if (rc == 0 && sc == 0) {
                    printf("Yay! You win.");
                    return 0;
                }
                else if (handle_quit()) {
                    return 0;
                }
                else {
                    printf("Incorrect guess.\n");


                }
                if (handle_quit()) {
                    return 0;
                }
                if (i == 0) {
                    printf("You have run out of moves. Game over! \n\n");
                    printf("Would you like to play again? Press y to continue or q to quit.\n");
                    scanf("%c", &YES);
                    if (YES == 'y' || YES == 'Y') {


                    }
                    if(YES == 'q'|| YES == 'Q') {
                        printf("Quitting....\n");
                        break;

                    }
                    if(YES == 'q'|| YES == 'Q') {
                        printf("Thank you for playing");
                        break;

                    }
                }


            }
            if (handle_quit()) {
                return 0;
            }
        }
        if(YES == 'q'|| YES == 'Q') {
            printf("Thank you for playing");
            break;
        }
    }

    return 0;
}