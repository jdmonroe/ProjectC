#include "administrator.h"
#include "Customer.h"

void CreateAccount(struct cData accounts[], int* AccNum)
{
    *AccNum = *(AccNum)+1;
    printf("First Name:");
    scanf("%s",accounts[*(AccNum)].fName);
    printf("Last Name:");
    scanf("%s",accounts[*(AccNum)].lName);
    printf("City:");
    scanf("%s",accounts[*(AccNum)].city);
    printf("State:");
    scanf("%s",accounts[*(AccNum)].state);
    printf("Phone Number:");
    scanf("%s",accounts[*(AccNum)].phone);
    printf("ID:");
    scanf("%s",accounts[*(AccNum)].id);
    printf("Password:");
    scanf("%s",accounts[*(AccNum)].pass);
    printf("Balance:");
    scanf("%lf",accounts[*(AccNum)].balance);

}
void ViewAcc(struct cData accounts[],int numAcc){
    int i,o=0;
    char AAcc[7];
    printf("Enter the Account ID you wish to view: ");
    scanf("%d",AAcc);
    for(i=0;i<numAcc;i++){
        if(strcmp(AAcc,accounts[i].id)==0){
            printf("%s %s %s %s %s %s %s %.2lf\n", accounts[i].fName, accounts[i].lName, accounts[i].city, accounts[i].state, accounts[i].phone, accounts[i].id, accounts[i].pass, accounts[i].balance);
            o=1;
            break;
        }else if(i==numAcc-1&&o!=1){
                 printf("Sorry that ID doesn't exist");
                 }
    }
}
void DeleteAccount(struct cData accounts[], int* AccNum)
{
    char deleted[6];
    int i;

    printf("\nEnter the ID of the account to be deleted: ");
    scanf("%s", deleted);

    for (i = 0; i < *AccNum; i++) {
        if (strcmp(accounts[i].id, deleted) == 0) {
            printf("%d\n", i);
            break;
        }
    }
    printf("%d\n", i);
    for (i; i < *AccNum - 1; i++) {
        printf("%d\n", i);
        accounts[i] = accounts[i + 1];
    }

    *AccNum -= 1;
}

