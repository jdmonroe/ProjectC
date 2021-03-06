//Source file for all of the administrator menu functions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "administrator.h"
#include "Customer.h"
//CreateAccount allows administrator to add a new account to file, while making sure inputs are correct
void CreateAccount(struct cData accounts[], int* AccNum)
{
    char first[9], last[9], city[11], state[3], phone[8], id[6], pass[7];
    double balance;


//Each part contains a while loop to verify input, then changes value once it fits format
    while (1){
        printf("First Name: ");
        scanf("%s", first);

        if (strlen(first) <= 8){
            strcpy(accounts[*AccNum].fName, first);
            break;
        }
        else{
            printf("Must be no more than 8 characters!\n");
        }
    }
    while (1){
        printf("Last Name: ");
        scanf("%s", last);
        if (strlen(last) <= 8){
            strcpy(accounts[*AccNum].lName, last);
            break;
        }
        else {
            printf("Must be no more than 8 characters!\n");
        }
    }
    while (1) {
        printf("City: ");
        scanf("%s", city);
        if (strlen(city) <= 10){
            strcpy(accounts[*AccNum].city, city);
            break;
        }
        else {
            printf("Must be no more than 10 characters!\n");
        }
    }
    while (1){
        printf("State: ");
        scanf("%s", state);
        if (strlen(state) <= 2){
            strcpy(accounts[*AccNum].state, state);
            break;
        }
        else {
            printf("Must be no more than 2 characters!\n");
        }
    }
    while (1){
        printf("Phone Number: ");
        scanf("%s", phone);
        if (strlen(phone) <= 7){
            strcpy(accounts[*AccNum].phone, phone);
            break;
        }
        else {
            printf("Must be no more than 7 characters!\n");
        }
    }
    while (1){
        printf("ID: ");
        scanf("%s", id);
        if (strlen(id) <= 5){
            strcpy(accounts[*AccNum].id, id);
            break;
        }
        else {
            printf("Must be no more than 5 characters!\n");
        }
    }
    while (1){
        printf("Password: ");
        scanf("%s", pass);
        if (strlen(pass) <= 6){
            strcpy(accounts[*AccNum].pass, pass);
            break;
        }
        else {
            printf("Must be no more than 6 characters!\n");
        }
    }
    while (1) {
        printf("Balance: ");
        scanf("%lf", &balance);
        if (balance >= 0) {
            accounts[*AccNum].balance = balance;
            *AccNum += 1;
            break;
        }
        else {
            printf("Balance must be greater than 0!\n");
        }
    }
}
//ViewAcc allows administrator to view an account by typing the account's ID number
void ViewAcc(struct cData accounts[],int numAcc){
    int i,o = 0;
    char AAcc[7];
    printf("Enter the Account ID you wish to view: ");
    scanf("%s",AAcc);
    system("cls");
//For loop cycles through structure to find the account ID that was typed in, will give warning if ID is not found
    for(i=0;i<numAcc;i++){
        if(strcmp(AAcc,accounts[i].id)==0){
            printf("First Name:\t%s\nLast Name:\t%s\nCity:\t\t%s\nState:\t\t%s\nPhone:\t\t%s\nID:\t\t%s\nPassword:\t%s\nBalance:\t%.2lf\n", accounts[i].fName, accounts[i].lName, accounts[i].city, accounts[i].state, accounts[i].phone, accounts[i].id, accounts[i].pass, accounts[i].balance);
            o=1;
            break;
        }else if(i==numAcc-1&&o!=1){
                 printf("Sorry that ID doesn't exist");
                 }
    }
}
//TopFive show the administrator the Top 5 accounts based on their balance
void TopFive(struct cData accounts[], int AccNum)
{
    int i, j;
//Bubble sort is used to find the highest account balances, then prints the top 5 accounts
    for (i = 0; i < AccNum - 1; i++){
        for (j = 0; j < AccNum - i - 1; j++) {
            if (accounts[j].balance < accounts[j + 1].balance) {
                accounts[AccNum + 1] = accounts[j];
                accounts[j] = accounts[j + 1];
                accounts[j + 1] = accounts[AccNum + 1];
                accounts[AccNum + 1] = accounts[AccNum + 2];
            }
        }
    }
    system("cls");
    printf("\t\t\t5 Accounts with Most Money\n");
    printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
    for (i = 0;i < 5; i++){
        printf("%d)%s %s %s %s %s %.2lf\n\n",i+1,accounts[i].fName, accounts[i].lName, accounts[i].city, accounts[i].state, accounts[i].phone,accounts[i].balance);
    }
}
//ChangeInfo allows administrator to change any info of a specific account
void ChangeInfo(struct cData accounts[], int AccNum){
    char first[9], last[9], city[11], state[3], phone[8], id[6], pass[7];
    double balance;
    int choice, i,o=0;
    char changed[6];
//While loop to verify the account ID that is entered
    while (o == 0){
            printf("\nEnter the ID of the account to be changed: ");
            scanf("%s", changed);
            for (i = 0;i < AccNum; i++) {
                if (strcmp(accounts[i].id, changed) == 0) {
                    printf("%d\n", i);
                    o=1;
                    break;
        }
    }      if (o == 0){
            printf("That Account Doesn't Exist\n");}
}

//Using a switch/case we can change individual aspects of a customer's account and each are input validated
    system("cls");
    printf("What do you want to change?");
    printf("1)First Name\n2)Last Name\n3)City\n4)State\n5)Phone Number\n6)ID\n7)Password\n8)Balance");
    scanf("%d",&choice);
    system("cls");
    switch(choice){
        case 1:
            while (1){
        printf("First Name: ");
        scanf("%s", first);

        if (strlen(first) <= 8){
            strcpy(accounts[i].fName, first);
            break;

        }
        else{
            printf("Must be no more than 8 characters!\n");
        }
    }

            break;
        case 2:
                while (1){
        printf("Last Name: ");
        scanf("%s", last);
        if (strlen(last) <= 8){
            strcpy(accounts[i].lName, last);
            break;
        }
        else {
            printf("Must be no more than 8 characters!\n");
        }
    }

            break;
        case 3:
            while (1) {
        printf("City: ");
        scanf("%s", city);
        if (strlen(city) <= 10){
            strcpy(accounts[i].city, city);
            break;
        }
        else {
            printf("Must be no more than 10 characters!\n");
        }
    }

            break;
        case 4:
             while (1){
        printf("State: ");
        scanf("%s", state);
        if (strlen(state) <= 2){
            strcpy(accounts[i].state, state);
            break;
        }
        else {
            printf("Must be no more than 2 characters!\n");
        }
    }

            break;
        case 5:
                while (1){
        printf("Phone Number: ");
        scanf("%s", phone);
        if (strlen(phone) <= 7){
            strcpy(accounts[i].phone, phone);
            break;
        }
        else {
            printf("Must be no more than 7 characters!\n");
        }
    }

            break;
        case 6:
                while (1){
        printf("ID: ");
        scanf("%s", id);
        if (strlen(id) <= 5){
            strcpy(accounts[i].id, id);
            break;
        }
        else {
            printf("Must be no more than 5 characters!\n");
        }
    }

            break;
        case 7:
                while (1){
        printf("Password: ");
        scanf("%s", pass);
        if (strlen(pass) <= 6){
            strcpy(accounts[i].pass, pass);
            break;
        }
        else {
            printf("Must be no more than 6 characters!\n");
        }
    }

            break;
        case 8:
                while (1) {
        printf("Balance: ");
        scanf("%lf", &balance);
        if (balance >= 0) {
            accounts[i].balance = balance;
            break;
        }

        default:
            printf("Invalid Input!");
    }

}
}
//ViewNames allows administrator to input a letter and view accounts that have the last name that starts with that letter in alphabetical order
void ViewNames(struct cData accounts[], int AccNum)
{
    char userInput;
    int i, o = 0;
    printf("Please input the a letter to list accounts by: ");
    scanf("%s", &userInput);
    userInput = toupper(userInput);
    while (o == 0) {
		for (i = 0; i < AccNum; i++){
			if (accounts[i].lName[0] == userInput) {
				printf("%s, %s %s %s %s %s %s %.2lf\n", accounts[i].lName, accounts[i].fName, accounts[i].city, accounts[i].state, accounts[i].phone, accounts[i].id, accounts[i].pass, accounts[i].balance);
			}
		}
		if (o == 1) {
			printf("No Accounts With that letter");
		}
    }
}
//DeleteAccount allows administrator to remove an account by account ID
void DeleteAccount(struct cData accounts[], int* AccNum)
{
    char deleted[6];
    int i, o = 0;
	while (o == 0) {
		printf("\nEnter the ID of the account to be deleted: ");
		scanf("%s", deleted);

		for (i = 0; i < *AccNum; i++) {
			if (strcmp(accounts[i].id, deleted) == 0) {\
				o = 1;
				break;
			}
		}
		if ( o == 1) {
			printf("That Account Doesn't Exist\n");
		}
	}
    for (i; i < *AccNum; i++) {
        accounts[i] = accounts[i + 1];
    }

    *AccNum -= 1;
}

