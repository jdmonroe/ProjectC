#include <stdio.h>
#include <stdlib.h>
#include "Customer.h"

void ViewInfo(char fname[9], char lname[9], char city[11], char state[3], char phone[8])
{
    printf("First Name: %s\nLast Name: %s\nCity: %s\nState: %s\nPhone: %s\n", fname, lname, city, state, phone);
}
void ViewBalance(double balance)
{
    printf("%.2lf", balance);
}
void Withdraw(double* balance){
    double amount=0;
    while (1){
    printf("How much do you want to withdraw?");
    scanf("%lf",&amount);
    if (*(balance)-amount>0&& amount>0){
        *(balance)-=amount;
        break;
    }else{
        printf("\nInsufficient Funds\n");
    }
    }
}
void Deposit(double* balance){
    double amount=0;
    while (1){
    printf("How much do you want to Deposit?");
    scanf("%lf",&amount);
    if (amount>0){
        *(balance)+=amount;
        break;
    }else{
        printf("\nNegative Amount Not Allowed\n");
    }
    }
}
