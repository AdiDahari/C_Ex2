#include <stdio.h>
#include <stdbool.h>
#include "myBank.h"
double bank[50][2];
int count = 0;

void O(double amount){
    if(amount <= 0) printf("Invalid Amount\n");
    else if(count < 50){
        int newNum = 0;
        while(bank[newNum][1] != false){
            newNum++;
        }
        bank[newNum][0] = amount;
        bank[newNum][1] = true;
        count++;
        printf("New account number is: %d \n", (newNum+901));
        
    }
    else{
        printf("Account could not be created! 50 Accounts already exists\n");
    }
}
void B(int aNum){
    if(bank[aNum][1] == false)  printf("This account is closed\n");
    else{
        printf("The balance of account number %d is: %0.2f\n",(aNum+901), bank[aNum][0]);
    }
}
void D(int aNum){
    if(bank[aNum][1] == false) printf("This account is closed\n");
    else{
        double amount;
        printf("Please enter the amount to deposit: ");
        if(scanf(" %lf", &amount) == false){
            printf("Failed to read the amount\n");
        }
        else if(amount < 0)
        {
            printf("Cannot deposit a negative amount\n");
        }
        else{
        bank[aNum][0] = bank[aNum][0] + amount;
        printf("The new balance is: %0.2f\n", bank[aNum][0]);
        }
    }
}
void W(int aNum){
    if(bank[aNum][1] == false) printf("This account is closed\n");
    else{
        printf("Please enter the amount to withdraw: ");
        double amount;
        if(scanf(" %lf", &amount) == false){
            printf("Failed to read the amount\n");
        }
        // else if(amount < 0)
        // {
        //     printf("Cannot withdraw a negative amount\n");
        // }
        else if(bank[aNum][0] < amount) printf("Cannot withdraw more than the balance\n");
        else{
        bank[aNum][0] = bank[aNum][0] - amount;
        printf("The new balance is: %0.2f\n", bank[aNum][0]);
        }
    }
}
void C(int aNum){
    if(bank[aNum][1] == false) printf("This account is already closed\n");
    else{
        bank[aNum][1] = false;
        printf("Closed account number %d\n", aNum+901);
        count--;
    } 
    
}
void I(int rate){
    if(rate <= 0) printf("Invalid interest rate\n");
    else{
        double nRate = (double)rate;
        for(int i = 0; i < 50; i++){
            if(bank[i][1] == true) bank[i][0] += ((nRate/100.0) * bank[i][0]);
        }
   }
}
void P(){
    if(count > 0){
         
    
        int innerCount = 0;
        for(int i = 0; i < 50; i++){
            if(innerCount == count) break;
            if(bank[i][1] == true){
                printf("The balance of account number %d is: %0.2f\n", (i + 901), bank[i][0]);
                innerCount++;
        }
    }
    }
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