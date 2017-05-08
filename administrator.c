#include <stdio.h>
#include <stdlib.h>
#include "administrator.h"
#include "Struct.h"

extern struct cData account;
void CreateAccount(struct cData account[10],int* AccNum){
    printf("First Name:");
    scanf("%s",account[*(AccNum)].fName);
    printf("Last Name:");
    scanf("%s",account[*(AccNum)].lName);
    printf("City:");
    scanf("%s",account[*(AccNum)].city);
    printf("State:");
    scanf("%s",account[*(AccNum)].state);
    printf("Phone Number:");
    scanf("%s",account[*(AccNum)].phone);
    printf("ID:");
    scanf("%s",account[*(AccNum)].id);
    printf("Password:");
    scanf("%s",account[*(AccNum)].pass);
    printf("Balance:");
    scanf("%lf",account[*(AccNum)].balance);
}
