#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

void PrintCustomerMenu(void);
void CustomerMenu(int choice);//Functions for Menu Choices will be inside this function
                              //  (since you can't call a function inside a function)
/**Functions inside CustomerMenu:
 void ChangePassword(int* userID);
 void ViewCustomer(int* UserID);
 void ViewBalance(int* userID);
 void MakeDeposit(int* userID);
 void TransferMoney(int* userID);
 void WithdrawMoney (int* userID);**/
#endif // CUSTOMER_H_INCLUDED
