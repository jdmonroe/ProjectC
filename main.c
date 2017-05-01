#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void clear(void);

int main() {
    int c = 1, menuSelect;
    char user[6], pass[7], a_user[6] = "admin", a_pass[7] = "admin", c_user[6] = "guest", c_pass[7] = "guest";
    struct C_Data {
        char f_name;
        char l_name;
        char city;
        char state;
        char phone;
        int id;
        char pass;
        double balance;
    };
    FILE *file;
    file = fopen("CustomerData.txt", "r");

    while

    printf("Welcome to Online Banking/ATM System\n====================================\n");
    printf("Enter your Customer/Admin ID: ");
    scanf("%s", user);
    printf("Enter your Customer/Admin Password: ");
    scanf("%s", pass);

    while(c == 1) {
        if (strcmp(user, a_user) == 0 && strcmp(pass, a_pass) == 0) {
            printf("Welcome to Online Banking/ATM System\n====================================\n");
            printf("-------------------------\nAdministrator Menu\n-------------------------\n\n");
            printf("1) Create Customer account\n2) Change Password\n3) View Customer Info\n4) Change Customer Info\n");
            printf("5) Delete Customer account\n6) Show Top 5 accounts\n7) Show customer accounts alphabetically\n8) Exit\n");
            scanf("%d", &menuSelect);
            switch (menuSelect) {
            case 1:
                printf("Customer Account created\n");
                clear();
                break;
            case 2:
                printf("Customer Account created\n");
                clear();
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
                break;
            default:
                printf("Invalid Input!\n");
                clear();
            }
        }

        else if (strcmp(user, c_user) == 0 && strcmp(pass, c_pass) == 0) {
            printf("Welcome to Online Banking/ATM System\n====================================\n");
            printf("-------------------------\nCustomer Menu\n-------------------------\n\n");
            printf("1) Change Password\n2) View Customer information\n3) View Balance\n4) Make a Deposit\n");
            printf("5) Transfer Money\n6) Withdraw Money\n7) Exit");
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
                break;
            default:
                printf("Invalid Input!\n");
            }
        }
    }
}

void clear(void)
{
    int ch;
    printf("Press ENTER to Continue");
    while ((ch = getchar()) != '\n');
    system("cls");
}

