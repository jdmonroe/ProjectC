#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


int main(){
    int x,y;
    x=login();
    if (x==0){
        while(1){
            y = PrintAdminMenu();
            if(y==8){
                break;
            }else{
                AdminMenu(y);}}
    }else{
        while(1){
            y = PrintCustomerMenu();
            if(y==7){
                break;
            }else{
                CustomerMenu(y);}}}
return 0;}
