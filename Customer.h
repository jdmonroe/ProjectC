#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED
#define MAX_ACCS 100

//Global structure for use in banksystems.c and fucntions
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

extern struct cData accounts[MAX_ACCS];
//Prototypes for defined functions in Customer.c
void ChangePass(char pass[]);
void ViewInfo(struct cData accounts);
void ViewBalance(struct cData accounts);
void Transfer(struct cData accounts[], int numAccounts, int origAcc);
void Deposit(double* balance);
void Withdraw(double* balance);

#endif // CUSTOMER_H_INCLUDED
