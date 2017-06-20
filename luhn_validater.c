#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char * userInput();
void runChecker(char * inputNum);

int main()
{
    printf("LUHN ALGORITHM\n");
    char * inputNum = userInput();
    runChecker(inputNum);
    return 0;
}

char * userInput()
{
    char * inputNum = malloc(sizeof(char) * 16);
    int i = 0;
    
    printf("Enter your credit card number: ");
    scanf("%s", inputNum);
    
    if(strlen(inputNum) != 16)
    {
        printf("Please input your valid 16 digit credit card number\n");
        exit(1);
    }
    
    for(i = 0; i < strlen(inputNum); i++)
    {
        if(!isdigit(inputNum[i]))
        {
            printf("Please make sure only numbers are entered");
            exit(1);
        }
    }
    
    return inputNum;
}

void runChecker(char * inputNum)
{
    int cardNum[100] = {0};
    int reversecardNum[100] = {0};
    int i = 0;
    int oddSum = 0;
    
    for(i = 0; i < strlen(inputNum); i++)
    {
        cardNum[i] = inputNum[i] - '0';
    }
    
    int j = 0;
    
    for(i = (strlen(inputNum)- 1); i >= 0; i--)
    {
        reversecardNum[j] = cardNum[i];
        j++;
    }
    
    for(i = 0; i < strlen(inputNum); i = i + 2)
    {
        oddSum = oddSum + reversecardNum[i];
    }
    
    int storeVal = 0;
    int firstPlace = 0;
    int secondPlace = 0;
    int sumPlace = 0;
    int evenSum = 0;
    int totalSum = 0;
    
    for(i = 1; i< strlen(inputNum); i = i + 2)
    {
        storeVal = reversecardNum[i] * 2;
        sumPlace = 0;
        
        if(storeVal > 9)
        {
            firstPlace = storeVal % 10;
            storeVal = storeVal / 10;
            secondPlace = storeVal;
            sumPlace = firstPlace + secondPlace;
        }
        evenSum = evenSum + sumPlace;
    }
    
    totalSum = oddSum + evenSum;
    
    if(totalSum % 10 == 0)
    {
        printf("Yes this is a valid card\n");
    }
    
    else
    {
        printf("No, this is an invalid card\n");
    }
    
    
}

