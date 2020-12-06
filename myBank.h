#ifndef MYBANK_H
#define MYBANK_H
#define ROW 50
#define COL 2

extern double MATRIX[ROW][COL];

void openAccount(int counter);
void checkBalance();
void depositing();
void withrawal();
void closeAccount();
void interest();
void printAllOpen();
void exitallprogram();




#endif 
