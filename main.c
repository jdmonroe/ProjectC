#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char pass[7], user[6], a_user[6] = "admin", a_pass[7] = "admin", c_user[6] = "guest", c_pass[7] = "guest";
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



    printf("Welcome to Online Banking/ATM System\n====================================\n");
    printf("Enter your Customer/Admin ID: ");
    scanf("%s", user);
    printf("Enter your Customer/Admin Password: ");
    scanf("%s", pass);

    if (strcmp(user, a_user) == 0 && strcmp(pass, a_pass) == 0) {
        printf("Welcome to Online Banking/ATM System\n====================================\n");
        printf("-------------------------\nAdministrator Menu\n-------------------------\n\n");
        printf("1) Create Customer account\n2) Change Password\n3) View Customer Info\n4) Change Customer Info\n");
        printf("5) Delete Customer account\n6) Show Top 5 accounts\n7) Show customer accounts alphabetically\n8) Exit\n");
    }

    else if (strcmp(user, c_user) == 0 && strcmp(pass, c_pass) == 0) {
        printf("Welcome to Online Banking/ATM System\n====================================\n");
        printf("-------------------------\nCustomer Menu\n-------------------------\n\n");
        printf("1) Change Password\n2) View Customer information\n3) View Balance\n4) Make a Deposit\n");
        printf("5) Transfer Money\n6) Withdraw Money\n7) Exit");
    }
}
