//Source file for all of the customer menu functions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Customer.h"
//ChangePass allows customer to change their account password if it passes validation
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
//ViewInfo allows customers to view their bank account information
void ViewInfo(struct cData accounts)
{
    printf("First Name: %s\nLast Name: %s\nCity: %s\nState: %s\nPhone: %s\n", accounts.fName, accounts.lName, accounts.city, accounts.state, accounts.phone);
}
//ViewBalance allows customers to view current balance at the bank
void ViewBalance(struct cData accounts)
{
    printf("Your current balance: %.2lf\n", accounts.balance);
}
//Deposit allows customers to make a deposit to their account as long as it is greater than 0
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
//Withdraw allows customers to pull money from their account as long as they have the funds and the amount pulled is not lower than 0
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
//Transfer allows customer to remove a balance above 0 and less than their balance from their account and put it into another account by their ID
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
