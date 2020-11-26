#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "myBank.h"
#define ACC "Please enter account number: "
#define FAC "Failed to read the account number\n\n"
#define FAM "Failed to read the amount\n\n"
#define DEP "Please enter amount for deposit: "
#define ITT "Invalid transaction type\n\n"
int main()
{
    char input;
    do
    {
        printf("Please choose a transaction type:\n \
O-Open Account\n \
B-Balance Inquiry\n \
D-Deposit\n \
W-Withdrawal\n \
C-Close Account\n \
I-Interest\n \
P-Print\n \
E-Exit\n");
        if (scanf(" %c", &input) == false)
        {
            printf(ITT);
        }

        else if (input == 'O')
        {
            double amount;
            printf("Please enter amount for deposit: ");
            if (scanf(" %lf", &amount) == true && amount > 0.0)
            {
                O(amount);
            }
            else
                printf(FAM);
        }
        else if (input == 'B')
        {
            int num;
            printf(ACC);
            if (scanf(" %d", &num) == false || num < 901 || num > 950)
            {
                printf(FAC);
                continue;
            }
            else
            {
                B(num - 901);
            }
        }
        else if (input == 'D')
        {
            int num;
            double amount;
            printf(ACC);
            if (scanf(" %d", &num) == false || num < 901 || num > 950)
            {
                printf(FAC);
                continue;
            }
            printf(DEP);
            if (scanf(" %lf", &amount) == false || amount <= 0.0)
            {
                printf(FAM);
            }
            else
            {
                D((num - 901), amount);
            }
        }
        else if (input == 'W')
        {
            int num;
            double amount;
            printf(ACC);
            if (scanf(" %d", &num) == false || num < 901 || num > 950)
            {
                printf(FAC);
                continue;
            }
            printf("Please enter the amount to withdraw: ");
            if (scanf(" %lf", &amount) == false || amount <= 0.0)
            {
                printf(FAM);
            }
            else
            {
                W((num - 901), amount);
            }
        }
        else if (input == 'C')
        {
            int num;
            printf(ACC);
            if (scanf(" %d", &num) == false || num < 901 || num > 950)
            {
                printf(FAC);
                continue;
            }
            else
            {
                C(num - 901);
            }
        }
        else if (input == 'I')
        {
            double rate;
            printf("Please enter interest rate: \n");
            if (scanf(" %lf", &rate) == false || rate <= 0)
            {
                printf("Failed to read the interest rate\n\n");
            }
            else
            {
                I(rate);
            }
        }
        else if (input == 'P')
        {
            P();
        }
        else if (input == 'E')
        {
            E();
        }
        else
        {
            printf(ITT);
        }
    } while (input != 'E');
    return 0;
}