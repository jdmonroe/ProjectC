#ifndef ADMINISTRATOR_H_INCLUDED
#define ADMINISTRATOR_H_INCLUDED
#include "Customer.h"

void CreateAccount(struct cData accounts[],int* AccNum);
void ViewAcc(struct cData account[], int numAcc);
void DeleteAccount(struct cData accounts[], int* AccNum);
#endif // ADMINISTRATOR_H_INCLUDED
