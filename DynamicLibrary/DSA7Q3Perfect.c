//Dynamic Shared Library of Perfect numbers file
#include<stdio.h>
#include<stdbool.h>
#include"A7Q3.h"

bool chkPerfect(int iNo)
{
    int iCnt = 0;
    int iSum = 0;
    for(iCnt = iNo/2; ((iCnt >= 1) && (iSum <= iNo)); iCnt--)
    {
        if((iNo % iCnt) == 0)
        {
            iSum = iSum + iCnt;
        }
    }   
    if(iSum == iNo)
    {
        return true;
    }
    else
    {
        return false;
    }
}