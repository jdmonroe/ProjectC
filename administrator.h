#ifndef ADMINISTRATOR_H_INCLUDED
#define ADMINISTRATOR_H_INCLUDED
#include "Customer.h"
//Prototypes for defined functions in administrator.c
void CreateAccount(struct cData accounts[],int* AccNum);
void ViewAcc(struct cData account[], int numAcc);
void DeleteAccount(struct cData accounts[], int* AccNum);
void ChangeInfo(struct cData accounts[], int AccNum);
void TopFive(struct cData accounts[], int AccNum);
void ViewNames(struct cData accounts[], int AccNum);
#endif // ADMINISTRATOR_H_INCLUDED
