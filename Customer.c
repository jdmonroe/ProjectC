#include <stdio.h>
#include <stdlib.h>
#include "Customer.h"


void ChangePass(char* pass)
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
    printf("%.2lf", accounts.balance);
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
void Transfer(struct cData accounts[], int numAccounts, int origAcc)
{
    char accountID[6];
    int amount, i;

    printf("Please enter the account ID to transfer to: ");
    scanf("%s", accountID);
    printf("Enter the amount to transfer: ");
    scanf("%d", &amount);

    for (i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].id, accountID) == 0){
            accounts[i].balance += (double)amount;
            accounts[origAcc].balance -= (double)amount;
            printf("%lf\n", accounts[i].balance);
            printf("Transfer was successful!\n");
            break;
        }

    }


}
