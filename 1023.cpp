//给一个k位的数看翻倍之后是不是原来那些数字的新排列方式
//给的数不超过20位
//long long 是十九位十进制数,所以显然自己要实现以下double
//不管yes还是no都要输出倍后的数字
//早上刚起床脑子不对劲,这题写了25分钟.
#include <stdio.h>
#include <string.h>
int main(){
    char a[25]={0};
    scanf("%s",a);
    int length=strlen(a);
    int* digit=new int[length+5];
    for (int i = 1; i < length+1; i++)
    {
        digit[i]=a[i-1]-48;
    }
    int* doubleDigit=new int[length+5];
    int borrow=0;
    for (int i = length ; i >0 ; i--)
    {
        if ((digit[i]*2+borrow)>9)
        {
            doubleDigit[i] = (digit[i] * 2 + borrow) % 10;
            borrow = 1;
        }else
        {
            doubleDigit[i] = (digit[i] * 2 + borrow);
            borrow = 0;
        }
    }
    int sign=0;
    if (borrow)
    {
        doubleDigit[0]=1;
        length++;
        printf("No\n");
        for (int i = 0; i < length; i++)
        {
            printf("%d",doubleDigit[i]);
        }
        return 0;
    }else
    {
        int num[11]={0};
        int doubled[11]={0};
        for (int i = 1; i < length+1; i++)
        {
            ++num[digit[i]];
        }
        for (int i = 1; i < length+1; i++)
        {
            ++doubled[doubleDigit[i]];
            if (doubled[doubleDigit[i]] > num[doubleDigit[i]])
            {
                sign=1;
                break;
            }
        }
        if (sign)
        {
            printf("No\n");
            for (int i = 1; i < length + 1; i++)
            {
                printf("%d", doubleDigit[i]);
            }
            return 0;
        }else
        {
            for (int i = 0; i < 10; i++)
            {
                if (doubled[i]!=num[i])
                {
                    sign=1;
                    break;
                }
                
            }
            if (sign)
            {
                
                printf("No\n");
                for (int i = 1; i < length + 1; i++)
                {
                    printf("%d", doubleDigit[i]);
                }
                return 0;
            }else
            {
                printf("Yes\n");
                for (int i = 1; i < length + 1; i++)
                {
                    printf("%d", doubleDigit[i]);
                }
                return 0;
            }
            
            
        }
        
        
    }
    
    
    
    
}
