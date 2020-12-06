#include <stdio.h>
#include "myBank.h"
double MATRIX[ROW][COL]={0};			//initing the bank matrix

//openAccount function gets the place of the last bank account that was open
//will change the firs place in the row to 1, and the secont place to the scaned deposit 
void openAccount(int counter){
    double amount;
    printf("Please enter amount for deposit: \n");
    if(scanf("%lf", &amount) != 1){
        printf("Failed to read the amount\n");
        }
    else if(amount<1){
        printf("Invalid amount\n");
    }
    MATRIX[counter][0] = 1;
    MATRIX[counter][1] = amount;
}

//prints the balance of the accout number was scanned 
void checkBalance(){
    int account_number;
    printf("Please enter account number: \n");
    if(scanf("%d", &account_number) != 1){
    printf("Failed to read the account number\n");
    }  
    if(account_number < 901 || account_number > 950 ){
        printf("Invalid account number\n");
    }
    if (MATRIX[account_number-901][0]==1){
        printf("your account balance is %0.2lf \n", MATRIX[account_number-901][1]);
    }
    else{
        printf("This account is closed \n");
    }
}
//add the given deposit to the given bank number account 
void depositing(){
    int account_number;
    double amount;
    printf("Please enter account number: \n");
    if(scanf(" %d", &account_number) != 1){
        printf("Failed to read the account number\n");
        return;
    }
    if(account_number < 901 || account_number > 950 ){
        printf("Invalid account number\n");
        return;
    }
    printf("Please enter the amount to deposit: \n");
    if(scanf(" %lf", &amount) != 1){
        printf("Failed to read the amount\n");
    }
    if(amount < 0){
        printf("Cannot deposit a negative amount\n");
    }
    if (MATRIX[account_number-901][0]==1){
        MATRIX[account_number-901][1]=MATRIX[account_number+901][1]+amount;
        printf("new account balance is: %0.2lf \n", MATRIX[account_number+901][1]);
    }
    else{
        printf("This account is closed");
        return;
    }
}

//substruct the given deposit from the given bank account number
void withrawal(){
    int account_number;
    double amount;
    printf("Please enter account number: \n");
    if(scanf(" %d", &account_number) != 1){
        printf("Failed to read the account number\n");
        return;
    }
    printf("Please enter the amount to withdraw:: \n");
    
     if(scanf(" %lf", &amount) != 1){
        printf("Failed to read the amount\n");
    }
    if(account_number < 901 || account_number > 950 ){
        printf("Invalid account number\n");
        return;
    }
    if (MATRIX[account_number-901][0] == 1) {
	if (MATRIX[account_number-901][1]<amount){
		printf("Cannot withdraw more than the balance");
	}
	else{
        	MATRIX[account_number-901][1] = MATRIX[account_number-901][1] - amount;
        	printf("new account balance is: %0.2lf \n", MATRIX[account_number-901][1]);
	}
    }
    else
        printf("This account is closed \n");
}

//will change the firs place in the row to 0, and the secont place to 0 
void closeAccount(){
    int account_number;
    printf("Please enter account number: \n");
     if(scanf(" %d", &account_number) != 1){
        printf("Failed to read the account number\n");
    }
    if(account_number < 901 || account_number > 950 ){
        printf("Invalid account number\n");
        return;
    }
    if (MATRIX[account_number-901][0] == 1){
        MATRIX[account_number-901][0] = 0;
	MATRIX[account_number-901][1] = 0;
        printf("account has been closed. \n");
    }
    else
        printf("This account is already closed \n");
}

//add a given % interest rate to all the open accounts
void interest(){
    int interest;
    printf("Please enter interest rate: \n");
    if(scanf(" %d", &interest) != 1){
        printf("Failed to read the interest rate\n");
    }
    if(interest < 0 || interest > 100){
        printf("Invalid interest rate\n");
    }
    for(int i; i<50; i++){
        if (MATRIX[i-901][0] == 1){
            MATRIX[i-901][1] = MATRIX[i-901][1]*(interest+100)/100;
        }
    }
}

//prints current deposit on all open accounts
void printAllOpen(){
    for(int i;i<50;i++){
        if (MATRIX[i-901][0]==1){
            printf("the balance of account number is: %d and current balance is: %0.2lf \n", i+901, MATRIX[i+901][1]);
        }
    }
}

//closes all accounts
void exitallprogram(){
    for(int i;i<50;i++){
        MATRIX[i-901][0] = 0;
	MATRIX[i-901][1] = 0;
    }
}

