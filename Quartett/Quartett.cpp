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

typedef struct Player {
    char name[50];
    Card* pfirstCardOfList;
    Card* pLastCardOfList;
}struPlayer;


// author of mehtod Raksana
void Output(Card* firstCard) {
    Card* pTemp = firstCard;
    while (pTemp != NULL)
    {
        printf(" %s\n", pTemp->Bez);
        printf(" usetime: %i\n", pTemp->usetime);
        printf(" wight: %lf\n", pTemp->wight);
        printf("\n");
        pTemp = pTemp->pNext;
    }



}
/*
* Author of mehtod Raksana
* Dise Methode schaut,ob der Wert 1 oder 2 ist
*/
bool checkInputValue(int *pvalueToCompare) {
    
        return  (*pvalueToCompare == 1 || *pvalueToCompare == 2);
    
}
/*
* Author of mehtod Raksana
* Dise Methode fügt die Karte zum schluss hinzu
*/
void addCard(Card* cardToAdd, Player* pPlayer) {
    cardToAdd->pNext = NULL;
    pPlayer->pLastCardOfList->pNext = cardToAdd;
    pPlayer->pLastCardOfList = pPlayer->pLastCardOfList->pNext;

    printf("addCart");
    Output(pPlayer->pfirstCardOfList);
}
/*
* Author of mehtod Raksana
* Dise Methode nimmt die Liste auseinander 
* an einer  bestimmten postition
* und fügt sie wieder hinzu.
* Ein Listen Object wird weggenommen.Das Objekt,
* dass weggenommen wird wird zurück gegeben.
*/
Card* splittListAndMerge(Player* pPlayer,Card* moveTo) {
    Card* pRemovedCard = pPlayer->pfirstCardOfList;
    Card* ptemp2 = pPlayer->pfirstCardOfList;
    Card* ptemp = pPlayer->pfirstCardOfList;
    while (ptemp->pNext != NULL && moveTo != pPlayer->pfirstCardOfList)
    {
        ptemp = ptemp->pNext;
        if (ptemp->pNext == moveTo && pPlayer->pfirstCardOfList != moveTo)
        {
            pRemovedCard = ptemp->pNext;
            ptemp->pNext = ptemp->pNext->pNext;
            printf("splitted and merged Cart");
            return pRemovedCard;
            
            break;

        }


    }
   
 
}

/*
* Author of mehtod Raksana
* Dise Methode schiebt die Karte eins nach Oben.
*/
Card *moveCardUp(Player* pPlayer,Card* moveTo) {
    if (pPlayer->pfirstCardOfList!= moveTo)
    {
       return splittListAndMerge(pPlayer, moveTo);
    }else{
    Card* pRemovedCard = pPlayer->pfirstCardOfList;
      pPlayer->pfirstCardOfList = pPlayer->pfirstCardOfList->pNext;
     return pRemovedCard; 
    }
 
  
   
   

}


/*
* Author of mehtod Raksana
* Diese Methode entfernt die Karte schiebt, die näachte Karte hoch 
* und fügt die Karte zum Schluss von dem Talon hinzu
*/

Card * removeCard(Player* pPlayer, Card *pCardToRemove) {
    Card* pTemp= pPlayer->pfirstCardOfList;
    while (pTemp->pNext!= pCardToRemove->pNext->pNext)
    {
        if (pTemp==pCardToRemove)
        {
            Card* removedCard = pPlayer->pfirstCardOfList;
            Card* temp=moveCardUp(pPlayer, pCardToRemove);
            break;
            printf("::::::::::::::::::::::::::");
        }
        pTemp=pTemp->pNext;      
    }
            Output(pPlayer->pfirstCardOfList);
            return removeCard;
}


//TODO: Raksana
void welcome() {
//name input player 
//and short explaination of game
}

                                   
//TODO: Raksana
void radomMixOfCardStack(Player *pPlayer) {
  
    for (int i = 0; i < 5; i++)
    {
        Card * pTemp = pPlayer->pfirstCardOfList;
        int randNr=rand() % 4;
        int* pRandNr = &randNr;
        int j=0;
        for (int *pj = &j; *pj < *pRandNr; *pj++) {
        
            pTemp = pTemp->pNext;
        }
        Card *toEnd=moveCardUp(pPlayer,pTemp);
        addCard(toEnd,pPlayer);
        printf("//////////RANDOM////////");
        Output(pPlayer->pfirstCardOfList);
    }
    
    

}
//TODO: Tamara
void distributeCardToPlayers(Player* player,Player* enemy, Player* cardDistributer) {
    Card* splittedCardStack = getindex(5, cardDistributer);
     removeCard();

    //Give each player their Stack of Cards
}
//TODO: Tamara
void getFirstElementOfCardStack() {
    //Get First element of player and enemy of Stack ^^
}
// author of mehtod Raksana
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

// author of mehtod Raksana
Player defineHigherCard(Player* pPlayer, Player* pEnemy, int* valueToCheck) {
    Card* enemy= pEnemy->pfirstCardOfList;
    Card* player= pPlayer->pfirstCardOfList;

    if ((*valueToCheck == 1 && player->usetime > enemy->usetime) || (*valueToCheck == 2 && player->wight > enemy->wight))
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

/*Autor: Tamara
* Es schaut wie viele Karten ein Spieler hat
*/
void sizeOfCardStack(Player* pPlayer) {
    int count = 0;
    Card* pTemp = pPlayer->pfirstCardOfList;
    while (pTemp->pNext != NULL)
    {
        pTemp = pTemp->pNext;
        count++;
    }
    printf("count i: %i\n",count);
}

//TODO: Tamara
void showWinner() {
    //show who and ask if player wannt's to play again
}

/*Autor: Tamara
* Erstellen von Karten -> Informationen der verschiedenen Laptops
*/
int main()
{
    //1.) Apple MacBook Pro (2021)
    struCard* pcard  = (struCard*)malloc(sizeof(struCard));
    strcpy_s(pcard->Bez,"Apple MacBook Pro(2021)");
    pcard->usetime = 17;
    pcard->wight = 1.6;
    pcard->pNext = NULL;
    struCard* pStartPlayer=pcard;
   
    // 2.) 
    pcard = (struCard*)malloc( sizeof(struCard));
    strcpy_s(pcard->Bez, "ACER Swift 1-C0WY");
    pcard->usetime = 16;
    pcard->wight = 1.5;
    pcard->pNext = NULL;
    pStartPlayer->pNext = pcard;
    struCard* pCard2 = pcard;
    //
    pcard = (struCard*)malloc(sizeof(struCard));
    strcpy_s(pcard->Bez, "3Card");
    pcard->usetime = 4;
    pcard->wight = 1.7;
    pcard->pNext = NULL;
    pCard2->pNext = pcard;
    struCard* pCard3 = pcard;
    //
    pcard = (struCard*)malloc(sizeof(struCard));
    strcpy_s(pcard->Bez, "4Card");
    pcard->usetime = 5;
    pcard->wight = 8.6;
    pcard->pNext = NULL;
    pCard3->pNext = pcard;
    struCard* pCard4 = pcard;
    //
    pcard = (struCard*)malloc(sizeof(struCard));
    strcpy_s(pcard->Bez, "5Card");
    pcard->usetime = 6;
    pcard->wight = 4.6;
    pcard->pNext = NULL;
    pCard4->pNext = pcard;
    struCard* pCard5 = pcard;
    //
    //    
    pcard = (struCard*)malloc(sizeof(struCard));
    strcpy_s(pcard->Bez, "6Card");
    pcard->usetime = 7;
    pcard->wight = 9.6;
    pcard->pNext = NULL;
    pCard5->pNext = pcard;
    struCard* pCard6 = pcard;
    //strat eneamy Card Talon

    struPlayer* pPlayer = (Player*)malloc(sizeof(Player));
    pPlayer->pfirstCardOfList = pStartPlayer;
    pPlayer->pLastCardOfList = pCard6;
    sizeOfCardStack(pPlayer);
    Output(pPlayer->pfirstCardOfList);
    system("pause");
    return 0;
}

