#include "administrator.h"
#include "Customer.h"

void CreateAccount(struct cData account[10],int* AccNum){
    AccNum = *(AccNum)+1;
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
void changePass(char * adminP[7]){
    char temporaryP[10];
    while(1){
    printf("What do you want the password to be now?");
    scanf("%s",&temporaryP);
    if (strlen(temporaryP)<=6){
        strcopy(temporaryP,*(adminP));
    }else{
        printf("Too long or Too short has to be 6 characters long");
    }
   }}
