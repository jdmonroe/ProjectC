#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Customer.h"


void ChangePass(char pass[])
{
    char newPass[7];
    while(1){
        printf("Please enter new password: ");
        scanf("%s", newPass);
        if (strlen(newPass) <= 6){
            strcpy(pass, newPass);
            printf("\nYour password has been changed!\n");
            break;
        }
        else {
            printf("Password must be less than 7 characters! Try Again!\n");
        }
    }


}
void ViewInfo(struct cData accounts)
{
    printf("First Name: %s\nLast Name: %s\nCity: %s\nState: %s\nPhone: %s\n", accounts.fName, accounts.lName, accounts.city, accounts.state, accounts.phone);
}
void ViewBalance(struct cData accounts)
{
    printf("Your current balance: %.2lf\n", accounts.balance);
}
void Deposit(double* balance)
{
    double amount=0;
    while (1){
    printf("How much do you want to Deposit?");
    scanf("%lf",&amount);
    if (amount>0){
        *(balance)+=amount;
        break;
    }

    else{
        printf("\nNegative Amount Not Allowed\n");
    }
    }
}
void Withdraw(double* balance)
{
    double amount=0;
    while (1){
    printf("How much do you want to Withdraw?");
    scanf("%lf",&amount);
    if (amount > 0 && (*balance - amount) > 0){
        *(balance)-=amount;
        break;
    }

    else{
        printf("\nNegative Amount Not Allowed\n");
    }
    }
}
void Transfer(struct cData accounts[], int numAccounts, int origAcc)
{
    char accountID[6];
    int amount, i,o=0;
    while (o==0){
        printf("Enter the amount to transfer: ");
        scanf("%d", &amount);
        getchar();
        if (amount > 0 && (accounts[origAcc].balance -(double)amount) > 0){
            o=1;}
            else{
                printf("You can't transfer that amount!");}}
    o=0;
    while (o==0){
        printf("Please enter the account ID to transfer to: ");
        scanf("%s", accountID);
        for (i = 0; i < numAccounts; i++) {
                if (strcmp(accounts[i].id, accountID) == 0){
                    if (strcmp(accounts[origAcc].id,accounts[i].id)==0){
                        printf("You can't Transfer to yourself!\n\n");
                        i=-1;
                        break;}
                    accounts[i].balance += (double)amount;
                    accounts[origAcc].balance -= (double)amount;
                    printf("Transfer was successful!\n");
                    o+=1;
                    break;
                    }
                    }
                    printf("That account does not exist\n");
                    i=-1;
                    o=0;
                    }
}
