//不是回文数的可以操作一下变成回文数
//通过把一个数反过来在加自己
//无线循环直到回文
//给一个N<10^10(大数)和K<1000要执行的步数
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <vector>
bool isPalindromic(std::vector<int> digit)
{
    int notSign=0;
    int size=digit.size();
    if (size&1)
    {
        for (int i = 0; i < size/2; i++)
        {
            if (digit[i] != digit[size - 1 - i])
            {
                notSign=1;
                break;
            }
            
        }
        
    }else
    {
        for (int i = 0; i < size/2; i++)
        {
            if (digit[i] != digit[size - 1 - i])
            {
                notSign = 1;
                break;
            }
        }
    }
    if (notSign)
    {
        return 0;
    }else{
        return 1;
    }
    
    
}
void plusReverse(std::vector<int> *digit)
{
    std::vector<int> reverse(digit->size() + 5);
    for (int i = 0; i < digit->size(); i++)
    {
        reverse[i] = (*digit)[digit->size() - 1 - i];
    }
    int borrow = 0;
    for (int i = 0; i < digit->size(); i++)
    {
        if ((*digit)[i] + reverse[i] + borrow > 9)
        {
            (*digit)[i] = (*digit)[i] + reverse[i] + borrow - 10;
            borrow = 1;
        }
        else
        {
            (*digit)[i] = (*digit)[i] + reverse[i]+borrow;
            borrow = 0;
        }
    }
    if (borrow)
    {
        digit->push_back(borrow);
    }
}
int main(int argc, char const *argv[])
{
    std::vector<int> digit;
    char ch[20];
    scanf("%s", ch);
    int K;
    scanf("%d", &K);
    for (int i = strlen(ch) - 1; i >= 0; i--)
    {
        digit.push_back(ch[i] - 48);
    }
    //低位在低
    int count=0;
    for (int i = 0; i < K; i++)
    {
        
        if (isPalindromic(digit))
        {
            break;
        }
        ++count;
        plusReverse(&digit);
    }
    for (int i = digit.size()-1; i >=0; i--)
    {
        printf("%d", digit[i]);
    }
    printf("\n%d",count);
    
    return 0;
}
