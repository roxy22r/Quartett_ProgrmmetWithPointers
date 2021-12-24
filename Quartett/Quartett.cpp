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

int main();
//
Card* allCards();
void addCard(Card* cardToAdd, Player* pPlayer);
//
bool checkInputValue(int* pvalueToCompare);
//
void distributeCardToPlayers(Player* player, Player* enemy, Player* cardDistributer);
Player* defineHigherCard(Player* pPlayer, Player* pEnemy, int* valueToCheck);
//
Card* getIndex(int index, Player* pPlayer);
Card* getLast(Card* pPlayer);
//
int inputCompareValue();
//
Card* moveCardUp(Player* pPlayer, Card* moveTo);
//
void playQuartett(Player* pPlyer);
void printWordQuartett();
//
void Output(Card* firstCard);
//
Card* removeCard(Player* pPlayer, Card* pCardToRemove);
void radomMixOfCardStack(Player* pPlayer);
//
Card* setpNextToNull(Card* card);
void setupQuartett(Player* pPlayer, Player* pEnemy);
Card* splittListAndMerge(Player* pPlayer, Card* moveTo);
int sizeOfCardStack(Player* pPlayer);
void showFirstElementOfCardStack(Player* pPlayer);
void showWinner(Player* pWinner);
void setupCardsOfRound(Player* pWinner, Player* pLoser);
void setupWinnerFromRound(Player* pPlayer, Player* pEnemy, int* valueToCheck);
//
Player* welcome(Player* pPlayer);


int main()
{
    struPlayer* pPlayer = (struPlayer*)malloc(sizeof(struPlayer));
    struPlayer* pEnemy = (struPlayer*)malloc(sizeof(struPlayer));
    //strcpy_s(pEnemy->name, "Computer");
    pPlayer = welcome(pPlayer);
    setupQuartett(pPlayer,pEnemy);
    playQuartett(pPlayer);

    system("pause");
    return 0;
}

//Autor: Raksana
Player* welcome(Player* pPlayer) {
    printWordQuartett();
    int zahl = 0;
    int* pzahl = &zahl;
    printf("Um das Spiel zu beginnen gib die Zahl  1 ein\n");
    while (zahl != 1) {
        scanf_s(" %i", pzahl);
    }
    printf("Wie heisst du?\n");
   // scanf_s(" %*s",pPlayer->name);
    printf("Schnelle Anleitung:");
    printf("Um den ersten Wert zu vergleichen von der Karte musst du 1 eingeben.\n");
    printf("Um den zweiten Wert zu vergleichen von der Karte musst du 2 eingeben.\n");
    printf("Wer den groesseren Wert hat gewinnt die Runde und bekommt die Karte vom Verlierer.\n");
    printf("Der Verlierer ist der, wo keine Karten mehr hat.\n\n");
    return pPlayer;

}
//Autor: Raksana
void printWordQuartett() {
    printf("*---------------------------------------------------------------------------------*\n");
    printf("|                                                                                |\n");
    printf("|   _______           _______  _______ _________ _______ __________________      |\n");
    printf("|  (  ___  )|\\     /|(  ___  )(  ____ )\\__   __/(  ____ \\\\__   __/\\__   __/      |\n");
    printf("|  | (   ) || )   ( || (   ) || (    )|   ) (   | (    \\/   ) (      ) (         |\n");
    printf("|  | |   | || |   | || (___) || (____)|   | |   | (__       | |      | |         |\n");
    printf("|  | |   | || |   | ||  ___  ||     __)   | |   |  __)      | |      | |         |\n");
    printf("|  | | /\\| || |   | || (   ) || (\\ (      | |   | (         | |      | |         |\n");
    printf("|  | (_\\ \\ || (___) || )   ( || ) \\ \\__   | |   | (____/\\   | |      | |         |\n");
    printf("|  (____\\/_)(_______)|/     \\||/   \\__/   )_(   (_______/   )_(      )_(         |\n");
    printf("|                                                                                |\n");
    printf("*--------------------------------------------------------------------------------*\n");
}

//Autor: Raksana
void setupQuartett(Player* pPlayer,Player* pEnemy) {
    Card* pStart = allCards();
    struPlayer* pDist = (struPlayer*)malloc(sizeof(struPlayer));
    Card* pEnd = getLast(pStart);
    pDist->pfirstCardOfList = pStart;
    pDist->pLastCardOfList = pEnd;
    radomMixOfCardStack(pDist);
    distributeCardToPlayers(pPlayer, pEnemy, pDist);
}
//Autor: Raksana
void playQuartett(Player* pPlayer,Player* pEnemy) {
    while (sizeOfCardStack(pPlayer) != 0 || sizeOfCardStack != 0)
    {

        showFirstElementOfCardStack(pPlayer);
        int compear = inputCompareValue();
        setupWinnerFromRound(pPlayer,pEnemy, &compear);
    }
}
//Autor: Raksana
void setupWinnerFromRound(Player* pPlayer, Player* pEnemy, int* valueToCheck) {
    Player* pWinner = defineHigherCard(pPlayer, pEnemy, valueToCheck);
    if (pPlayer == pWinner) {
        setupCardsOfRound(pWinner, pEnemy);
    }
    else {
        setupCardsOfRound(pWinner, pPlayer);
    }

}
/*Autor: Tamara
* Erstellen von Karten -> Informationen der verschiedenen Laptops
*/
Card* allCards() {
    // 1.) Apple MacBook Pro(2021)
    struCard* pcard = (struCard*)malloc(sizeof(struCard));
    strcpy_s(pcard->Bez, "Apple MacBook Pro(2021)");
    pcard->usetime = 17;
    pcard->wight = 1.6;
    pcard->pNext = NULL;
    struCard* pStartPlayer = pcard;

    // 2.) ACER Swift 1-C0WY
    pcard = (struCard*)malloc(sizeof(struCard));
    strcpy_s(pcard->Bez, "ACER Swift 1-C0WY");
    pcard->usetime = 16;
    pcard->wight = 1.5;
    pcard->pNext = NULL;
    pStartPlayer->pNext = pcard;
    struCard* pCard2 = pcard;

    // 3.) HP Pavilion Aero 13
    pcard = (struCard*)malloc(sizeof(struCard));
    strcpy_s(pcard->Bez, "HP Pavilion Aero 13");
    pcard->usetime = 10;
    pcard->wight = 1.0;
    pcard->pNext = NULL;
    pCard2->pNext = pcard;
    struCard* pCard3 = pcard;

    // 4.) MICROSOSFT Surface Go
    pcard = (struCard*)malloc(sizeof(struCard));
    strcpy_s(pcard->Bez, "MICROSOSFT Surface Go");
    pcard->usetime = 13;
    pcard->wight = 1.110;
    pcard->pNext = NULL;
    pCard3->pNext = pcard;
    struCard* pCard4 = pcard;

    // 5.) LENOVO V15
    pcard = (struCard*)malloc(sizeof(struCard));
    strcpy_s(pcard->Bez, "LENOVO V15");
    pcard->usetime = 6;
    pcard->wight = 1.85;
    pcard->pNext = NULL;
    pCard4->pNext = pcard;
    struCard* pCard5 = pcard;

    // 6.) HUAWEI MateBook D15
    pcard = (struCard*)malloc(sizeof(struCard));
    strcpy_s(pcard->Bez, "HUAWEI MateBook D15");
    pcard->usetime = 7;
    pcard->wight = 1.53;
    pcard->pNext = NULL;
    pCard5->pNext = pcard;
    struCard* pCard6 = pcard;

    // 7.) LENOVO ThinkPad P17
    pcard = (struCard*)malloc(sizeof(struCard));
    strcpy_s(pcard->Bez, "LENOVO ThinkPad P17");
    pcard->usetime = 8;
    pcard->wight = 3.67;
    pcard->pNext = NULL;
    pCard6->pNext = pcard;
    struCard* pCard7 = pcard;

    // 8.) DELL Latitude 7410
    pcard = (struCard*)malloc(sizeof(struCard));
    strcpy_s(pcard->Bez, "DELL Latitude 7410");
    pcard->usetime = 6;
    pcard->wight = 1.33;
    pcard->pNext = NULL;
    pCard7->pNext = pcard;
    struCard* pCard8 = pcard;

    // 9.) HP OMEN
    pcard = (struCard*)malloc(sizeof(struCard));
    strcpy_s(pcard->Bez, "HP OMEN");
    pcard->usetime = 6;
    pcard->wight = 2.45;
    pcard->pNext = NULL;
    pCard8->pNext = pcard;
    struCard* pCard9 = pcard;

    // 10.) ASUS E210MA
    pcard = (struCard*)malloc(sizeof(struCard));
    strcpy_s(pcard->Bez, "ASUS E210MA");
    pcard->usetime = 5;
    pcard->wight = 1.05;
    pcard->pNext = NULL;
    pCard9->pNext = pcard;
    struCard* pCard10 = pcard;
    return pStartPlayer;
}

// Autor: Raksana
void Output(Card* firstCard) {
    Card* pTemp = firstCard;
    while (pTemp != NULL)
    {
        printf(" %s\n", pTemp->Bez);
        printf(" Nutzungszeit: %i\n", pTemp->usetime);
        printf(" Gewicht: %lf\n", pTemp->wight);
        printf("\n");
        pTemp = pTemp->pNext;
    }



}
/*
* Autor der Methode Raksana
* Dise Methode schaut,ob der Wert 1 oder 2 ist
*/
bool checkInputValue(int *pvalueToCompare) {
    
        return  (*pvalueToCompare == 1 || *pvalueToCompare == 2);
    
}
/*
* Autor der Methode Raksana
* Dise Methode fügt die Karte zum schluss hinzu
*/
void addCard(Card* cardToAdd, Player* pPlayer) {
    cardToAdd->pNext = NULL;
    pPlayer->pLastCardOfList->pNext = cardToAdd;
    pPlayer->pLastCardOfList = pPlayer->pLastCardOfList->pNext;
}
/*
* Autor der Methode Raksana
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
     
        if (ptemp->pNext == moveTo && pPlayer->pfirstCardOfList != moveTo)
        {
            pRemovedCard = ptemp->pNext;
            ptemp->pNext = ptemp->pNext->pNext;
           
            return pRemovedCard;
            
            break;

        }
        ptemp = ptemp->pNext;
    }
 
}

/*
* Autor der Methode Raksana
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
    Card* removed = pPlayer->pfirstCardOfList;
    Card* pTemp= pPlayer->pfirstCardOfList;
    while (pTemp->pNext!= pCardToRemove->pNext->pNext)
    {
        if (pTemp==pCardToRemove)
        {
            removed = pPlayer->pfirstCardOfList;
            Card* temp=moveCardUp(pPlayer, pCardToRemove);
            break;
          
        }
        pTemp=pTemp->pNext;      
    }
            return removed;
}



/*Autor: Tamara
* Es schaut wie viele Karten ein Spieler hat
*/
int sizeOfCardStack(Player* pPlayer) {
    int count = 0;
    Card* pTemp = pPlayer->pfirstCardOfList;
    while (pTemp->pNext != NULL)
    {
        pTemp = pTemp->pNext;
        count++;
    }
    return count;
}
                                   
/*Autor: Raksana

*/
void radomMixOfCardStack(Player *pPlayer) {
  
    for (int i = 0; i < 5; i++)
    {
    Card * pTemp = pPlayer->pfirstCardOfList;
        int randNr=rand() % 4;
       
     
        for (int pj =0; pj < randNr; pj++) {
        
            pTemp = pTemp->pNext;
        }
        Card *toEnd=moveCardUp(pPlayer,pTemp);
        addCard(toEnd,pPlayer);
     
    }
    
 
}
Card* getIndex (int index, Player* pPlayer) {
    Card *pTemp = pPlayer->pfirstCardOfList;
    int countDown=index;
    while (countDown!=0)
    
   {
        pTemp = pTemp->pNext;
       countDown--;
    }
    return pTemp;
    

}
Card* getLast(Card* pPlayer) {
    Player tempPlayer;
    Player *pTempPlayer = &tempPlayer;
    pTempPlayer->pfirstCardOfList = pPlayer;
    int indexLastCard=sizeOfCardStack(pTempPlayer);
   return getIndex(indexLastCard,pTempPlayer);
   

}

//TODO: Tamara
void distributeCardToPlayers(Player* player,Player* enemy, Player* cardDistributer) {
    Card* secondCardStack = getIndex(5, cardDistributer);
    Card* firstCardStack = removeCard(cardDistributer, secondCardStack);
    player->pfirstCardOfList = firstCardStack;
    Card* lastFirst= getIndex(4, player);
    lastFirst =setpNextToNull(lastFirst);
    enemy->pfirstCardOfList = secondCardStack;
    player->pLastCardOfList = getLast(firstCardStack);
    enemy->pLastCardOfList = getLast(secondCardStack);
     
    //Give each player their Stack of Cards
}
// TODO: Tamara
void showFirstElementOfCardStack(Player* pPlayer) {
    printf("$.Bezeichnung: %s \n",pPlayer->pfirstCardOfList->Bez);
    printf("1.Nutzungszeit:%i \n",pPlayer->pfirstCardOfList->usetime);
    printf("2.Gewicht: %lf \n",pPlayer->pfirstCardOfList->wight);

    //Get First element of player and enemy of Stack ^^
}

// Autor der Methode Raksana
int inputCompareValue() {
    int valueToCompare;
    int* pvalueToCompare = &valueToCompare;
    printf("Geben Sie den Vergleichs wert ein: \n");
    scanf_s("%i", pvalueToCompare);
    printf("%i", valueToCompare);
    if (checkInputValue(pvalueToCompare)) {
        return *pvalueToCompare;
    }

    return *pvalueToCompare;

}
Card* setpNextToNull(Card* card) {
    card->pNext = NULL;
    return card;
}

// Autor der Methode Raksana
//winnerIs
Player * defineHigherCard(Player* pPlayer, Player* pEnemy, int* valueToCheck) {
    Card* enemy= pEnemy->pfirstCardOfList;
    Card* player= pPlayer->pfirstCardOfList;

    if ((*valueToCheck == 1 && player->usetime > enemy->usetime) || (*valueToCheck == 2 && player->wight > enemy->wight))
    {
        return pPlayer;
    }
    else {
        return pEnemy;
    }
}
//TODO: Raksana
void setupCardsOfRound(Player* pWinner,Player* pLoser) {
    Card* winnCard = removeCard(pLoser, pLoser->pfirstCardOfList);
    Card* firstCardWinner = removeCard(pWinner, pWinner->pfirstCardOfList);
    winnCard = setpNextToNull(winnCard);
    firstCardWinner=setpNextToNull(firstCardWinner);
    addCard(winnCard,pWinner);
    addCard(firstCardWinner, pWinner);
}


//TODO: Tamara
void showWinner(Player* pWinner) {
    //show who won and ask if player wants to play again
}







