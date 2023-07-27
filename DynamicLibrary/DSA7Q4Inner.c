#include<stdio.h>
#include"A7Q4.h"

int Factorial(int iNo)
{
    int iCnt = 0;
    int iCount = 0;
    for(iCnt = 1; iCnt <= (iNo/2); iCnt++)
    {
        if(iNo % iCnt == 0)
        {
            iCount++;
        }
    }
    return iCount;
}