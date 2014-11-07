#include<stdio.h>
#include"headerfile.h"

int main(int argc, char **argv) {
    
	if(argc==2) {
	    int nNum;
		nNum=atoi(argv[1]);
		if(nNum >= 1 && nNum <= 41)
		    computeGoodNumber(nNum);
		else
	        printf("\nError: no of digit should be > 0");
	}
	else
	    printf("\nError: no of digit should be > 0");
    printf("\n\n");
	return 0;
}
