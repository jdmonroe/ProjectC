#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Customer.h"
#include "administrator.h"

<<<<<<< HEAD
void countlines(FILE* fp,int* NumLines);
void ClearScreen(void);
void Print(struct cData accounts[], int numAccounts);
=======

>>>>>>> parent of 86a1976... Customer Menu Complete

void Print(struct cData accounts[], int numAccounts);

int main() {
<<<<<<< HEAD
    int c = 1, i, numAccounts, menuSelect,w=1,NumLines;
    char user[6], pass[7], a_user[6] = "admin", a_pass[7] = "admin";
=======
    struct cData accounts[MAX_ACCS];
    int c = 1, i, numAccounts, menuSelect, check;
    char user[6], pass[7], a_user[6] = "admin", a_pass[7] = "admin", c_user[6] = "guest", c_pass[7] = "guest";
>>>>>>> parent of 86a1976... Customer Menu Complete
    FILE *file;
    numAccounts = 0;
    file = fopen("CustomerData.txt", "r");
    countlines(file,&NumLines);
    printf("%d\n\n\n",NumLines);
    fclose(file);
    struct cData *accounts=(struct cData*)malloc(sizeof(struct cData)*(NumLines));
    file = fopen("CustomerData.txt", "r");
    for(i = 0; i < NumLines; i++) {
        fscanf(file, "%s %s %s %s %s %s %s %lf", accounts[i].fName, accounts[i].lName, accounts[i].city, accounts[i].state, accounts[i].phone, accounts[i].id, accounts[i].pass, &accounts[i].balance);
        //printf("%s %s %s %s %s %s %s %.2lf\n", accounts[i].fName, accounts[i].lName, accounts[i].city, accounts[i].state, accounts[i].phone, accounts[i].id, accounts[i].pass, accounts[i].balance);
        numAccounts++;
    }

    while(c <= 1) {
            c = 2;
            printf("\nWelcome to Online Banking/ATM System\n====================================\n");
            printf("Enter your Customer/Admin ID: ");
            gets(user);
            printf("Enter your Customer/Admin Password: ");
            gets(pass);
        while(c == 2){
            c = 1;
            for (i = 0; i < numAccounts; i++) {
                if (strcmp(user, a_user) == 0 && strcmp(pass, a_pass) == 0) {
                    printf("\nWelcome to Online Banking/ATM System\n====================================\n");
                    printf("-------------------------\nAdministrator Menu\n-------------------------\n\n");
                    printf("1) Create Customer account\n2) Change Password\n3) View Customer Info\n4) Change Customer Info\n");
                    printf("5) Delete Customer account\n6) Show Top 5 accounts\n7) Show customer accounts alphabetically\n8) Exit\n");
                    scanf("%d", &menuSelect);
                    switch (menuSelect) {
                    case 1:
                        CreateAccount(accounts, &numAccounts);
                        i = -1;
                        break;
                    case 2:
                        ChangePass(accounts[i].pass);
                        i = -1;
                        break;
                    case 3:
                        ViewAcc(accounts, numAccounts);
                        i = -1;
                        break;
                    case 4:

                        break;
                    case 5:
                        DeleteAccount(accounts, &numAccounts);
                        Print(accounts, numAccounts);
                        break;
                    case 6:
                        break;
                    case 7:
                        break;
                    case 8:
                        c = 0;
                        break;
                    default:
                        printf("Invalid Input!\n");
                    }
                }

                else if (strcmp(user, accounts[i].id) == 0 && strcmp(pass, accounts[i].pass) == 0) {
                    printf("\nWelcome to Online Banking/ATM System\n====================================\n");
                    printf("-------------------------\nCustomer Menu\n-------------------------\n\n");
                    printf("1) Change Password\n2) View Customer information\n3) View Balance\n4) Make a Deposit\n");
                    printf("5) Transfer Money\n6) Withdraw Money\n7) Exit\n");
                    scanf("%d", &menuSelect);
                    switch (menuSelect) {
                    case 1:
                        ChangePass(accounts[i].pass);
                        printf("%s", accounts[i].pass);
                        i = -1;
                        break;
                    case 2:
                        ViewInfo(accounts[i]);
                        i = -1;
                        break;
                    case 3:
                        ViewBalance(accounts[i]);
                        i = -1;
                        break;
                    case 4:
                        Deposit(&accounts[i].balance);
                        i = -1;
                        break;
                    case 5:
                        Transfer(accounts, numAccounts, i);
                        i = -1;
                        break;
                    case 6:
                        Withdraw(&accounts[i].balance);
                        i = -1;
                        break;
                    case 7:
                        c = 0;
                        break;
                    default:
                        printf("Invalid Input!\n");
                    }
                }
            }
                if (c == 1) {
                    printf("\nInvalid User ID or Password! Try again!\n");
                }

                else {
                    printf("You have been logged out! Close the program to exit.");
                }
        }
    }
}

void countlines(FILE* fp,int*NumLines){
    int lines=0;
    char ch;
    while(!feof(fp)){
        ch = fgetc(fp);
        if(ch == '\n'){
            lines++;
}}
    *NumLines=lines;
}

void Print(struct cData accounts[], int numAccounts)
{
    int i;
    for(i = 0; i < numAccounts; i++) {
        printf("%s %s %s %s %s %s %s %.2lf\n", accounts[i].fName, accounts[i].lName, accounts[i].city, accounts[i].state, accounts[i].phone, accounts[i].id, accounts[i].pass, accounts[i].balance);
    }
}


