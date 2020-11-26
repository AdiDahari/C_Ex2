#include <stdio.h>
#include <stdbool.h>
#include "myBank.h"
double bank[50][2];
int count = 0;
void O(double amount){
    if(count < 50){
        int newNum = 0;
        while(bank[newNum][1] != false){
            newNum++;
        }
        bank[newNum][0] = amount;
        bank[newNum][1] = true;
        count++;
        printf("New account number is: %d\n\n", (newNum+901));
        
    }
    else{
        printf("Account could not be created! 50 Accounts already exists\n\n");
    }
}
void B(int aNum){
    if(bank[aNum][1] == false)  printf("This account is closed\n\n");
    else{
        printf("The balance of account number %d is: %0.2f\n\n",(aNum+901), bank[aNum][0]);
    }
}
void D(int aNum, double amount){
    if(bank[aNum][1] == false) printf("This account is closed\n\n");
    else{
        bank[aNum][0] = bank[aNum][0] + amount;
        printf("The new balance is: %0.2f\n\n", bank[aNum][0]);
    }
}
void W(int aNum, double amount){
    if(bank[aNum][1] == false) printf("This account is closed\n\n");
    else if(bank[aNum][0] < amount) printf("Cannot withdraw more than the balance\n\n");
    else{
        bank[aNum][0] = bank[aNum][0] - amount;
        printf("The new balance is: %0.2f\n\n", bank[aNum][0]);
    }
}
void C(int aNum){
    if(bank[aNum][1] == false) printf("This account is closed\n\n");
    else{
        bank[aNum][1] = false;
        printf("Account %d is now closed\n\n", aNum+901);
    } 
    count--;
}
void I(double rate){
    for(int i = 0; i < 50; i++){
        if(bank[i][1] == true) bank[i][0] += ((rate/100) * bank[i][0]);
    }
}
void P(){
    if(count == 0) printf("No accounts open!\n");
    int innerCount = 0;
    for(int i = 0; i < 50; i++){
        if(innerCount == count) break;
        if(bank[i][1] == true){
            printf("The balance of account number %d is: %0.2f\n", (i + 901), bank[i][0]);
            innerCount++;

        }
    }
    printf("\n");
}
void E(){
    int innerCount = 0;
    for(int i = 0; i < 50; i++){
        if(innerCount == count) break;
        if(bank[i][1] == true){
            bank[i][1] = false;
            innerCount++;

        }
    }
}
