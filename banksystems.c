#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Customer.h"
#include "administrator.h"


void countlines(FILE* fp,int* NumLines);
void ClearScreen(void);
void Print(struct cData accounts[], int numAccounts);
void WriteFile(FILE *file, struct cData accounts[], int numAccounts); // Prototypes for Functions in main


int main() {
    struct cData accounts[MAX_ACCS];
    int c = 1, i, numAccounts, menuSelect, w = 1, NumLines;
    char user[6], pass[7], a_user[6] = "admin", a_pass[7];
    FILE *file,*fp2;
    fp2 = fopen("Admin.txt","r+");
    fscanf(fp2,"%s",a_pass);                            // opens the Admin and assigns Password
    fclose(fp2);
    file = fopen("CustomerData.txt", "r+");             // counts how many files to begin with
    countlines(file,&NumLines);
    fclose(file);
    file = fopen("CustomerData.txt", "r");

    numAccounts = 0;

    for(i = 0; i < NumLines; i++) {            // File to Structure
        fscanf(file, "%s %s %s %s %s %s %s %lf", accounts[i].fName, accounts[i].lName, accounts[i].city, accounts[i].state, accounts[i].phone, accounts[i].id, accounts[i].pass, &accounts[i].balance);
        numAccounts++;
    }

    while(c <= 1) {
            w=1;
            c = 2;
            printf("Welcome to Online Banking/ATM System\n====================================\n");
            printf("Enter your Customer/Admin ID: ");               //Login
            gets(user);
            printf("Enter your Customer/Admin Password: ");
            gets(pass);
            system("cls");
        while(c == 2){
            c = 1;
            for (i = 0; i < numAccounts; i++) {
                if (strcmp(user, a_user) == 0 && strcmp(pass, a_pass) == 0) { //First checks if user is admin
                    while (w == 1) {
                        printf("Welcome to Online Banking/ATM System\n====================================\n");
                        printf("-------------------------\nAdministrator Menu\n-------------------------\n\n");
                        printf("1) Create Customer account\n2) Change Password\n3) View Customer Info\n4) Change Customer Info\n");
                        printf("5) Delete Customer account\n6) Show Top 5 accounts\n7) Show customer accounts alphabetically\n8) Exit\n");
                        scanf("%d", &menuSelect);
                        system("cls");                      // Prints Admin Menu
                        switch (menuSelect) {
                        case 1:
                            CreateAccount(accounts, &numAccounts);
                            ClearScreen();
                            i = -1;
                            break;
                        case 2:                        // Cases for each option
                            w = 2;
                            c = 0;
                            ChangePass(a_pass);
                            fp2 = fopen("Admin.txt","w+");
                            fprintf(fp2,"%s",a_pass);
                            fclose(fp2);
                            printf("Your Password has changed you will have to re-log in to continue\n");
                            printf("================================================================\n");
                            ClearScreen();
                            i = -1;
                            break;
                        case 3:
                            ViewAcc(accounts, numAccounts);
                            ClearScreen();
                            i = -1;
                            break;
                        case 4:
                            ChangeInfo(accounts, numAccounts);
                            break;
                        case 5:
                            DeleteAccount(accounts, &numAccounts);
                            Print(accounts, numAccounts);
                            ClearScreen();
                            break;
                        case 6:
                            TopFive(accounts, numAccounts);
                            ClearScreen();
                            break;
                        case 7:
                            ViewNames(accounts, numAccounts);
                            ClearScreen();
                            break;
                        case 8:
                            c = 0;
                            w = 2;
                            getchar();
                            break;
                        default:
                            printf("Invalid Input!\n");
                        }
                    }
                }

                else if (strcmp(user, accounts[i].id) == 0 && strcmp(pass, accounts[i].pass) == 0) {//Checks if user is customer
                    while(w == 1){
                        printf("Welcome to Online Banking/ATM System\n====================================\n");
                        printf("-------------------------\nCustomer Menu\n-------------------------\n\n");
                        printf("1) Change Password\n2) View Customer information\n3) View Balance\n4) Make a Deposit\n");
                        printf("5) Transfer Money\n6) Withdraw Money\n7) Exit\n");
                        scanf("%d", &menuSelect);
                        system("cls");                         //Prints Customer Menu
                        switch (menuSelect) {
                        case 1:
                            ChangePass(accounts[i].pass);
                            w = 2;
                            c = 0;
                            printf("Your Password has changed you will have to re-log in to continue\n");
                            printf("================================================================\n");
                            ClearScreen();
                            break;
                        case 2:
                            ViewInfo(accounts[i]);
                            ClearScreen();
                            break;
                        case 3:
                            ViewBalance(accounts[i]);
                            ClearScreen();
                            break;
                        case 4:
                            Deposit(&accounts[i].balance);
                            ClearScreen();
                            break;
                        case 5:
                            Transfer(accounts, numAccounts, i);
                            ClearScreen();
                            break;
                        case 6:
                            Withdraw(&accounts[i].balance);
                            ClearScreen();
                            break;
                        case 7:
                            c = 0;
                            w = 2;
                            getchar();
                            break;
                        default:
                            printf("<><><><><><><>\nInvalid Input!\n<><><><><><><>\n");
                        }
                    }
                }
            }
                if (c == 1) {
                    printf("<><><><><><><><><><><><><><><><><><><><><>\n");
                    printf("Invalid User ID or Password! Try again!\n");
                    printf("<><><><><><><><><><><><><><><><><><><><><>\n\n");
                }

                else {
                    i=-1;
                    WriteFile(file, accounts, numAccounts);  // Updates whenever user exits
                    system("cls");
                    printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
                    printf("You have been logged out! Close the program to exit.\n");
                    printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n\n");
                }
        }
    }
return 0;}

void countlines(FILE* fp,int*NumLines){
    int lines = 0;   //checks how many lines in file at beginning
    char ch;
    while (!feof(fp)){
        ch = fgetc(fp);
        if(ch == '\n'){
             lines++;
        }
    }
    *NumLines = lines + 1;
}

void Print(struct cData accounts[], int numAccounts)//Print the Structure
{
    int i;
    for(i = 0; i < numAccounts; i++) {
        printf("%s %s %s %s %s %s %s %.2lf\n", accounts[i].fName, accounts[i].lName, accounts[i].city, accounts[i].state, accounts[i].phone, accounts[i].id, accounts[i].pass, accounts[i].balance);
    }
}
void ClearScreen(void){// Cleans the screen for a more fluid program
    while (1){
        if (getchar()!='/n'){
            printf("Enter Any Key to continue ");
            while(getchar()!='\n');
            system("cls");
            break;
        }
    }
}
void WriteFile(FILE *file, struct cData accounts[], int numAccounts)
{
    int i;

    file = fopen("CustomerData.txt", "w+");
    for(i = 0; i < numAccounts; i++) {
            if (i==numAccounts-1){
                fprintf(file, "%s %s %s %s %s %s %s %.2lf", accounts[i].fName, accounts[i].lName, accounts[i].city, accounts[i].state, accounts[i].phone, accounts[i].id, accounts[i].pass, accounts[i].balance);
            }else{
                fprintf(file, "%s %s %s %s %s %s %s %.2lf\n", accounts[i].fName, accounts[i].lName, accounts[i].city, accounts[i].state, accounts[i].phone, accounts[i].id, accounts[i].pass, accounts[i].balance);
    }
    }
    fclose(file);
}
