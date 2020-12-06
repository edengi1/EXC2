#include <stdio.h>
#include "myBank.h"

int main(){
	
	int counter =0;		//last free account number. to keep track for the next new openAccount func
    	char func = 'a';	
    	printf(" Please choose a transaction type: \n");
      printf(" O-Open Account\n");
      printf(" B-Balance Inquiry\n");
      printf(" D-Deposit\n");
      printf(" W-Withdrawal\n");
      printf(" C-Close Account\n");
      printf(" I-Interest\n");
      printf(" P-Print\n");
      printf(" E-Exit\n");
    	scanf("	%c", &func);
    	while (func!= 'E') {
        	switch (func) {
            	case 'O':{
                	openAccount(counter++);
                	break;
		}	
            	case 'B':{
                	checkBalance();
                	break;
		}
            	case 'D':{
                	depositing();
                	break;
		}
            	case 'W':{
                	withrawal();
                	break;
		}
            	case 'C':{
                	closeAccount();
                	break;
		}
            	case 'I':{
                	interest();
                	break;
		}
            	case 'P':{
                	printAllOpen();
                	break;
		}
            	case 'E':{
                	exitallprogram();
                	break;
		}
            	default:
                	printf(" Invalid transaction type");
        }
    }
	return 0;
}
