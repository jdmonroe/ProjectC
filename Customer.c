#include <stdio.h>
#include <stdlib.h>
#include "Customer.h"
void ViewInfo(char fname[9], char lname[9], char city[11], char state[3], char phone[8])
{
    printf("First Name: %s\nLast Name: %s\nCity: %s\nState: %s\nPhone: %s\n", fname, lname, city, state, phone);
}
void ViewBalance(double balance)
{
    printf("%.2lf", balance);
}
