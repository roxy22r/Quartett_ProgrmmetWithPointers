#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

typedef struct Card{
    char Bez[50];
    int usetime ; 
    double wight;
    struct Card* pNext;
} struCard;

bool checkInputValue(int *pvalueToCompare) {
    return  (*pvalueToCompare == 1 || *pvalueToCompare == 2);
    
   
}
//TODO: Raksana
void removeCard() {
}

//TODO: Raksana
void addCard() {
}
//TODO: Raksana
void welcome() {
//name input player 
//and short explaination of game
}

 //TODO: Tamara
void addCardsTofakeList () {
  
    //add Carts to spesific address 
}
//TODO: Raksana
void radomMixOfCardStack(Card *pFirstCard,Card *pLastCard) {
    //self explaint
}
//TODO: Tamara
void distributeCardsToPlayers(Card* pFirstCard, Card* pLastCard) {
    //Give each player their Stack of Cards
}
//TODO: Tamara
void getFirstElementOfCardStack() {
    //Get First element of player and enemy of Stack ^^
}
int inputCompareValue() {
    int valueToCompare;
    int* pvalueToCompare = &valueToCompare;
    printf("Geben Sie den Vergleichs wert ein: \n");
    scanf_s("%i", pvalueToCompare);
    printf("%i", valueToCompare);
    if (checkInputValue(pvalueToCompare)) {
        return *pvalueToCompare;
    }

    inputCompareValue();

}

char defineHigherCard(Card* playerCard, Card* enemyCard, int* valueToCheck) {
    char player = 'P';
    char enemy = 'E';
    char* pPlayer = &player;
    char* pEnemy = &player;

    if ((*valueToCheck == 1 && playerCard->usetime > enemyCard->usetime) || (*valueToCheck == 2 && playerCard->wight > enemyCard->wight))
    {
        return *pPlayer;
    }
    else {
        return *pEnemy;
    }
}
//TODO: Raksana
void addCardToListOfWinnerAndPutSecondTo() {
    //Get first cart of loser and set behinde stack of winner with first card of winner
}
//TODO: Tamara
void checkListSizeOfPlayers() {
    //Check the List Of Players every round
    //if 0 ||/0 than winner is Player with not Zero Cards
}
//TODO: Tamara
void showWinner() {
    //show who and ask if player wannt's to play again
}

int main()
{
    inputCompareValue();
    //add methods togehter
}


