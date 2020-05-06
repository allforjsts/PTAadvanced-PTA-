#include <math.h>
#include <stdio.h>
#include <string.h>
//比柳神的快一点,我很开心.
int main()
{
    int L, K;
    char longNum[1005];
    scanf("%d %d", &L, &K);
    getchar();
    scanf("%s", longNum);
    int length = strlen(longNum);
    int digit[1005] = {0};
    for (int i = 0; i < L; i++)
    {
        digit[i] = longNum[i] - 48;
    }
    int value[10] = {0};
    value[0] = 1;
    for (int i = 1; i < K; i++)
    {
        value[i] = value[i - 1] * 10;
    }
    int prime = 0;
    for (int i = K - 1; i < length; i++)
    {
        int num = 0;
        if (!(digit[i]&1))
        {
            if (digit[i]>2)
            {
                continue;
            }else
            {
                bool sign = false;
                for (int j = 1; j < K; j++)
                {
                    if (digit[i - j] != 0)
                    {
                        sign = true;
                    }
                }
                if (sign==false)
                {
                    prime=2;
                    break;
                }else
                {
                    continue;
                }

                
            }
            
            
        }
        
        
        
        
        for (int j = 0; j < K; j++)
        {
            num += digit[i - j] * value[j];
        }
        if (num == 2 || num == 3)
        {
            prime = num;
            break;
        }
        if (num < 2)
        {
            continue;
        }
        if (num % 6 != 1 && num % 6 != 5)
        {
            continue;
        }
        else
        {
            bool isprime=true;
            int temp = sqrt(num);
             for (int i = 5; i < temp; i += 6)
            {
                if (num % i == 0 || num % (i + 2) == 0)
                {
                    isprime=false;
                    break;
                }
            }
            if (isprime)
            {
                prime=num;
                break;
            }
        }
    }
    if (prime)
    {
        printf("%0*d",K,prime);
    }else
    {
        printf("404");
    }
    
    
}
