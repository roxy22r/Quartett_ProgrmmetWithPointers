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
    if (*pvalueToCompare==1||*pvalueToCompare==2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int inputCompearValue() {
    int valueToCompare;
    int* pvalueToCompare = &valueToCompare; 
    printf("Geben Sie den Vergleichs wert ein: \n");
    scanf_s("%i", pvalueToCompare);
    printf("%i", valueToCompare);
    if (checkInputValue(pvalueToCompare)) {
        return *pvalueToCompare;
    }
 
    inputCompearValue();
    
}

  

int main()
{
    inputCompearValue();
    
}


