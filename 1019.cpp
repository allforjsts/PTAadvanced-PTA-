//看是不是回文数
//给一个十进制N(<10^9)和进制b(<10^9),看N在b进制下是否是回文数
//输出是否是回文数和N在b进制的每一位.末尾不能有空格
//用时十分钟吧..还吃了几次泡面
#include <stdio.h>
#include <vector>
using namespace std;
int main()
{
    int N, b;
    scanf("%d %d", &N, &b);
    int temporary = N;
    vector<int> digit;
    while (temporary)
    {
        digit.push_back(temporary % b);
        temporary /= b;
    }
    int sign = 0;
    if (digit.size() & 1)
    {

        for (int i = 0; i < digit.size() / 2; i++)
        {
            if (digit[i] != digit[digit.size() - 1 - i])
            {
                sign = 1;
                break;
            }
        }
    }
    else
    {
        for (int i = 0; i < digit.size() / 2; i++)
        {
            if (digit[i] != digit[digit.size() - 1 - i])
            {
                sign = 1;
                break;
            }
        }
    }
    if (sign == 0)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }

    for (int i = 0; i < digit.size(); i++)
    {
        printf("%d", digit[digit.size() -1-i]);
        if (i != digit.size()-1)
        {
            printf(" ");
        }
    }
}
