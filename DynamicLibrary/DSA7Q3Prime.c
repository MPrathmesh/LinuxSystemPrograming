//Dynamic Shared Library prime numbers file
#include<stdio.h>
#include<stdbool.h>
#include"A7Q3.h"

bool chkPrime(int iNo)
{
    int iCnt = 0;
    int iFactCnt = 0;
    for(iCnt = 2; iCnt <= iNo/2; iCnt++)
    {
        if(iNo % iCnt == 0)
        {
            iFactCnt++;
        }
    }

    if(iFactCnt == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
