#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

void ViewInfo(char fname[9], char lname[9], char city[11], char state[3], char phone[8]);
void ViewBalance(double balance);
void Withdraw(double* balance);
void Deposit(double* balance);


#endif // CUSTOMER_H_INCLUDED
