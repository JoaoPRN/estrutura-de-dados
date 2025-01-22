#include<stdio.h>
 
int main()
{
    int n, garrafasCheias;
    while(scanf("%d",&n)==1)
    {
        if(n==0)
            break;
        garrafasCheias=0;
        while(n>=3)
        {
            n=(n-3)+1;
            garrafasCheias+=1;
 
        }
        if(n==2)
            garrafasCheias+=1;
        printf("%d\n",garrafasCheias);
    }
    return 0;
}