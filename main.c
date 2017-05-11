#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ACCS 1000




int main() {
    int c, i, numAccounts, menuSelect;
    char user[6], pass[7], a_user[6] = "admin", a_pass[7] = "admin", c_user[6] = "guest", c_pass[7] = "guest";
    struct cData
    {
        char fName[9];
        char lName[9];
        char city[11];
        char state[3];
        char phone[8];
        char id[6];
        char pass[7];
        double balance;
    };
    struct cData accounts[MAX_ACCS];
    FILE *file;
    file = fopen("CustomerData.txt", "r");

    numAccounts = 0;

    for(i = 0; i < MAX_ACCS; i++) {
        while (fscanf(file, "%s %s %s %s %s %s %s %lf", accounts[i].fName, accounts[i].lName, accounts[i].city, accounts[i].state, accounts[i].phone, accounts[i].id, accounts[i].pass, &accounts[i].balance) != EOF) {
            printf("%s %s %s %s %s %s %s %.2lf\n", accounts[i].fName, accounts[i].lName, accounts[i].city, accounts[i].state, accounts[i].phone, accounts[i].id, accounts[i].pass, accounts[i].balance);
            numAccounts++;
        }
    }

    c = 1;

    while(c == 1) {
        i = 0;
        for (i; i < numAccounts; i++) {
            printf("\nWelcome to Online Banking/ATM System\n====================================\n");
            printf("Enter your Customer/Admin ID: ");
            scanf("%s", user);
            printf("Enter your Customer/Admin Password: ");
            scanf("%s", pass);
            if (strcmp(user, a_user) == 0 && strcmp(pass, a_pass) == 0) {
                printf("\nWelcome to Online Banking/ATM System\n====================================\n");
                printf("-------------------------\nAdministrator Menu\n-------------------------\n\n");
                printf("1) Create Customer account\n2) Change Password\n3) View Customer Info\n4) Change Customer Info\n");
                printf("5) Delete Customer account\n6) Show Top 5 accounts\n7) Show customer accounts alphabetically\n8) Exit\n");
                scanf("%d", &menuSelect);
                switch (menuSelect) {
                case 1:
                    printf("Customer Account created\n");
                    break;
                case 2:
                    printf("Customer Account created\n");
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    break;
                case 7:
                    break;
                case 8:
                    c = 0;
                    i = numAccounts;
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
                    printf("Customer Account created\n");
                    break;
                case 2:
                    printf("Customer Account created\n");
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    break;
                case 7:
                    c = 0;
                    i = numAccounts;
                    break;
                default:
                    printf("Invalid Input!\n");
                }
            }

            else {
                printf("Invalid User ID or Password! Try Again!\n");
                i--;
            }
        }
    }
}

