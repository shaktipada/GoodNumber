#include<stdio.h>
#include"headerfile.h"

int equality(long nNum1, long nNum2, int nCnt) {
    int nDigit1;
	int nDigit2;
	int nFlag=0;
	for( ;nNum1 && nNum2 ;nNum1=nNum1/10, nNum2=nNum2/10 ) {
	    nDigit1=((int)nNum1)%10;
	    nDigit2=((int)nNum2)%10;
		if(nDigit1==nDigit2)
		    nFlag++;
	}
	if(nFlag>=nCnt)
	    nFlag=nCnt;
	else
	    nFlag=0;
	return nFlag;
}

int check(int nGood[], int nNum ) {
    int nFlag;
	int nCntr1;
	int nCntr2;
	int nCnt;
	int nLen;
	int nLoop;
	long nVar1;
	long nVar2;
	for(nLen=0;nLen<=nNum;nLen++);
	nLen--;
	nFlag=0;
    for(nCntr1=nLen,nCntr2=nLen-1; nCntr1>=0 && nCntr2 >=0; nCntr1-=1, nCntr2-=2) {
	    nCnt=0;
		nVar1=0;
		nVar2=0;
		for(nLoop=nLen; nLoop >= nCntr1; nLoop--,nCnt++)
		    nVar1=nVar1*10+(long)nGood[nLoop];
		for(nLoop=nCntr1-1; nLoop >= nCntr2; nLoop--)
		    nVar2=nVar2*10+(long)nGood[nLoop];
		nFlag=equality(nVar1,nVar2,nCnt);
		if(nFlag>0)
		    return nFlag;
    }
	return nFlag;
}

void computeGoodNumber(int nNum) {
	 int nGood[nNum];
     int nLoop;
	 int nRes;
	 int nCntr;
	 nGood[0]=1;
	 for(nLoop=1 ; nLoop < nNum; nLoop++) {
		 nGood[nLoop]=1;
		 nRes= check(nGood,nLoop);
		 nCntr=1;
		 while(nRes > 0) {
		     nGood[nLoop]=nGood[nLoop]+1;
			 nCntr+=1;
			 nRes=check(nGood,nLoop);
			 if(nCntr > 3 || nGood[nLoop] > 3) {
			     nLoop=nLoop-1;
				 for(nCntr=1;nCntr<=3;nCntr++)
				     if(nCntr!=nGood[nLoop-1] && nCntr!=nGood[nLoop-2]) {
					     nGood[nLoop]=nCntr;
						 break;
				     }
			 }
		 }
	 }
	 for(nLoop=0;nLoop < nNum;nLoop++)
	     printf("%d",nGood[nLoop]);
}