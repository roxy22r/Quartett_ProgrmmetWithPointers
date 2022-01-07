#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

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
bool checkInputValue(int valueToCompare);
//
void distributeCardToPlayers(Player* player, Player* enemy, Player* cardDistributer);

Player* defineHigherCard(Player* pPlayer, Player* pEnemy, int* valueToCheck);
//
Card* getIndex(int index, Player* pPlayer);
Card* getLast(Card* pPlayer);
Player* getWinner(Player* player, Player* enemy);
//
int inputCompareValue();
//
Card* moveCardUp(Player* pPlayer, Card* moveTo);
//
void playQuartett(Player* pPlayer, Player* pEnemy);
void printWordQuartett();
//
Card* removeCard(Player* pPlayer, Card* pCardToRemove);
void radomMixOfCardStack(Player* pPlayer);
void replay(Player* pPlayer, Player* pEnemy);
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

/*Autor: Raksana
Hier wird ein logischer ablauf ausgeführt für das Spiel.
*/
int main()
{
    struPlayer* pPlayer = (struPlayer*)malloc(sizeof(struPlayer));
    struPlayer* pEnemy = (struPlayer*)malloc(sizeof(struPlayer));
    strcpy_s(pEnemy->name,"Computer");
    pPlayer = welcome(pPlayer);
    setupQuartett(pPlayer,pEnemy);
    playQuartett(pPlayer,pEnemy);

    system("pause");
    return 0;
}

/*Autor: Raksana
* Hier wird die Begrüssung ausgegeben 
* zudem wird hier eine kurz Anleitung ausgegben 
* für den Spieler.
* Zudem wird hier die Eingabe des Namens vom Spieler eingegeben.
*/
Player* welcome(Player* pPlayer) {
    printWordQuartett();
    int zahl = 0;
    int* pzahl = &zahl;
    printf("Um das Spiel zu beginnen gib die Zahl  1 ein\n");
    while (zahl != 1) {
        scanf_s(" %i", pzahl);
    }
    printf("Wie heisst du?\n");
    scanf_s(" %*s",pPlayer->name);
    printf("\nSchnelle Anleitung:\n");
    printf("Um den ersten Wert zu vergleichen von der Karte musst du 1 eingeben.\n");
    printf("Um den zweiten Wert zu vergleichen von der Karte musst du 2 eingeben.\n");
    printf("Wer den groesseren Wert hat gewinnt die Runde und bekommt die Karte vom Verlierer.\n");
    printf("Der Verlierer ist der, wo keine Karten mehr hat.\n\n");
    return pPlayer;

}
/*Autor: Raksana
* Hier wird das Quartett Spiel angefangen
* dies bedeutet, dass das Spiel so lange weiter geht bis einer der beiden
* keine Karten mehr hat.
* 
* Als erstet wird die erste Karte angezeigt vom Spieler.
* Danach wird der wert Kontrolliert, ob es d
*/
void playQuartett(Player* pPlayer,Player * pEnemy)
{
    while (sizeOfCardStack(pEnemy) != 0 && sizeOfCardStack(pPlayer) != 0)
    {

        showFirstElementOfCardStack(pPlayer);
        int compear = inputCompareValue();
        bool validValue=checkInputValue(compear);
        if (validValue) {
            setupWinnerFromRound(pPlayer, pEnemy, &compear);

            int cardOfPlayer = sizeOfCardStack(pPlayer);
            int cardOfEnemy = sizeOfCardStack(pEnemy);
            printf("Du hast: %i Karten\n", cardOfPlayer);
            printf("Der Gegner hat: %i Karten\n", cardOfEnemy);
        }
        else {
            printf("Sie dürfen nur 1 oder 2 eingeben!!\n\n\n ");
        }
    }
    Player* winner = getWinner(pPlayer, pEnemy);
    showWinner(winner);
}
/*
*/
Player* getWinner(Player* player, Player* enemy) {
    int cardOfPlayer = sizeOfCardStack(player);
    int cardOfEnemy = sizeOfCardStack(enemy);
    if (cardOfPlayer > cardOfEnemy) {
        return player;
    }
    return enemy;
}

/*
Autor: Raksana
Hier wird das Word Quartett cool Ausgegeben, 
damit es wie ein Title auisieht 
*/
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

/*Autor: Raksana
Hier wird das erstellen einer Karte aufgerufen.
Zudem werden die Karten Random vermischt und zum Schluss werden diese verteil.
Hier werden merhheitlich, die erstellten Methoden aufgerufen.
*/

void setupQuartett(Player* pPlayer,Player* pEnemy) {
    Card* pStart = allCards();
    struPlayer* pDist = (struPlayer*)malloc(sizeof(struPlayer));
    Card* pEnd = getLast(pStart);
    pDist->pfirstCardOfList = pStart;
    pDist->pLastCardOfList = pEnd;
    radomMixOfCardStack(pDist);
    distributeCardToPlayers(pPlayer, pEnemy, pDist);
}


/*Autor: Raksana
Hier wîrd der Gewinner, der Runde bestummen
dies bedeutet, dass die Karte des verliers zum gewinnner geht.
*/
void setupWinnerFromRound(Player* pPlayer, Player* pEnemy, int* valueToCheck) {
    Player* pWinner = defineHigherCard(pPlayer, pEnemy, valueToCheck);
    if (pPlayer == pWinner) {
        setupCardsOfRound(pWinner, pEnemy);
    }
    else { 
        setupCardsOfRound(pWinner, pPlayer);
    }

}


/*
* Autor: Raksana
* Dise Methode schaut,ob der Wert 1 oder 2 ist
*/
bool checkInputValue(int valueToCompare) {
    
        return  (valueToCompare == 1 || valueToCompare == 2);
    
}
/*
* Autor: Raksana
* Dise Methode f�gt die Karte zum schluss hinzu
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
* und f�gt sie wieder hinzu.
* Ein Listen Object wird weggenommen.Das Objekt,
* dass weggenommen wird wird zur�ck gegeben.
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
* Autor: Raksana
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
* Autor: Raksana
* Diese Methode entfernt die Karte schiebt, die n�achte Karte hoch 
* und f�gt die Karte zum Schluss von dem Talon hinzu
*/

Card * removeCard(Player* pPlayer, Card *pCardToRemove) {
    Card* removed = pPlayer->pfirstCardOfList;
    Card* pTemp= pPlayer->pfirstCardOfList;
    while ( NULL != pTemp->pNext &&pTemp->pNext!= pCardToRemove->pNext->pNext)
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
* Es schaut wie viele Karten ein Spieler hat.
* pTemp ist die erste Karte vom Spieler.
* Danach wird so lange zum n�chsten Verkettungspunkt gezeigt,
* bis der Verkettungspunkt NULL ist.
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
Hier werden die Karten Random gemischt.
*/
void radomMixOfCardStack(Player *pPlayer) {
    
    srand(time(0));
    int randOne = rand() % 4;
    for (int i = 0; i < randOne; i++)
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
/*Autor: Tamara
* getIndex holt sich eine Karte an einem bestimmten Punkt in der Verkettetenliste.
*/
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
/*Autor: Raksana
*Mit dieser funktion wird die Letzte Karte geholt vom
* Talon.
*/
Card* getLast(Card* pPlayer) {
    Player tempPlayer;
    Player *pTempPlayer = &tempPlayer;
    pTempPlayer->pfirstCardOfList = pPlayer;
    int indexLastCard=sizeOfCardStack(pTempPlayer);
   return getIndex(indexLastCard,pTempPlayer);
   

}

//Autor: Tamara
//Hier werden die Karten zu den Spieler verteilt.
void distributeCardToPlayers(Player* player,Player* enemy, Player* cardDistributer) {
    Card* secondCardStack = getIndex(5, cardDistributer);
    Card* firstCardStack = removeCard(cardDistributer, secondCardStack);
    player->pfirstCardOfList = firstCardStack;
    Card* lastFirst= getIndex(4, player);
    lastFirst =setpNextToNull(lastFirst);
    enemy->pfirstCardOfList = secondCardStack;
    player->pLastCardOfList = getLast(firstCardStack);
    enemy->pLastCardOfList = getLast(secondCardStack);
     
    
}
/*Autor: Tamara
* Hier werden die Elemente im Quartett aufgelistet
* */
void showFirstElementOfCardStack(Player* pPlayer) {
    printf("\n\n$.Bezeichnung: %s \n",pPlayer->pfirstCardOfList->Bez);
    printf("1.Nutzungszeit:%i \n",pPlayer->pfirstCardOfList->usetime);
    printf("2.Gewicht: %lf \n\n",pPlayer->pfirstCardOfList->wight);
}

/*Autor: Raksana
*/
int inputCompareValue() {
    int valueToCompare;
    int* pvalueToCompare = &valueToCompare;
    printf("Geben Sie den Vergleichs wert ein: \n");
    scanf_s(" %i", pvalueToCompare);
    return *pvalueToCompare;

}
/*Autor: Raksana
* Diese Methode setzt pNext auf NUL
*/
Card* setpNextToNull(Card* card) {
    card->pNext = NULL;
    return card;
}

/*Autor: Raksana
* Hier wird die hoehere Karte definiert.
* Dies bedeutet, das der aus gewählte wert verglichen wird.
*Damit gibt es den Spieler zurück der Gewonnen hat.
*/
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
/*Autor: Raksana
* Hier wird die velierer Karte und gewinner Karte, in den Talon vom
* Gewinner zu unterst gelegt.
* 
*/
void setupCardsOfRound(Player* pWinner,Player* pLoser) {
    Card* winnCard = removeCard(pLoser, pLoser->pfirstCardOfList);
    Card* firstCardWinner = removeCard(pWinner, pWinner->pfirstCardOfList);
    winnCard = setpNextToNull(winnCard);
    firstCardWinner=setpNextToNull(firstCardWinner);
    addCard(winnCard,pWinner);
    addCard(firstCardWinner, pWinner);
}


/* Autor: Tamara
* Hier wird der Gewinner ausgegeben
*/
void showWinner(Player* pWinner) {
    printf ("Der Gewinner ist %s \n",&pWinner->name);


}
/*
*/
void replay(Player *pPlayer, Player *pEnemy) {
    int value=0;
    printf("Willst du nocheinmal eine Runde Quartett Spielen?\n");
    printf("Dan gib 1 ein sonst 2\n");
    scanf_s(" %i", value);
    if (value==1) {
        pEnemy->pfirstCardOfList=NULL;
        pPlayer->pfirstCardOfList=NULL;
        setupQuartett(pPlayer, pEnemy);
        playQuartett(pPlayer, pEnemy);
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





