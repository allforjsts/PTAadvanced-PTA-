//D进制下的素数N各位反转过来是否还是素数.
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int isPrime(int x){
    if (x==1)
    {
        return 0;
    }
    if (x==2||x==3)
    {
        return 1;
    }else if (x%6!=1&&x%6!=5) {
        return 0;
    }
    int tmp=sqrt(x);
    for (int i = 5; i < tmp; i+=6)
    {
        if (x%i==0||x%(i+2)==0)
        {
            return 0;
        }
    }
    return 1;
}
//这个算法比米勒罗宾还是差一些的,在数据很大的时候,不过这里N是有范围的所以问题不大,
//米勒罗宾需要实现包括快速乘和幂等一些的,我当时懒得写了.
int main(){
    int N,D;
    while (1)
    {
        scanf("%d", &N);
        if (N < 0)
        {
            return 0;
        }else {
            scanf("%d", &D);
            getchar();
        }
        if (isPrime(N)==0)
        {
            printf("No\n");
            continue;
        }
        int n=N;
        int digitCount=0;
        while (n)
        {
            n/=D;
            ++digitCount;
        }
        int* digit=(int*)malloc(sizeof(int)*(digitCount+10));
        n=N;
        for (int   i = 0; i < digitCount; i++)
        {
            digit[i]=n%D;
            n/=D;
        }
        //digit放着N在D进制下的每一位.
        int *reverseDigit = (int *)malloc(sizeof(int) * (digitCount + 10));
        for (int i = 0; i < digitCount; i++)
        {
            reverseDigit[i]=digit[digitCount-1-i];
        }
        int reversedNumber=0;
        for (int i = 0; i < digitCount; i++)
        {
            int valueOfDigit=1;
            for (int j = 0; j < i; j++)
            {
                valueOfDigit*=D;
            }
            reversedNumber+=reverseDigit[i]*valueOfDigit;
        }
        if (isPrime(reversedNumber))
        {
            printf("Yes\n");
        }else
        {
            printf("No\n");
        }
    }
    
    
}
