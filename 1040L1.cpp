//最长回文子串问题

//先写个双指针试一下吧

#include <stdio.h>
#include <string.h>
using namespace std;
int main(int argc, char const *argv[])
{
    char st[1005];
    scanf("%[^\n]", st);
    int length = strlen(st);
    int max=1;
    for (int i = 0; i < length - 1; i++)
    {
        int count=0;
        if (st[i]==st[i+1])
        {
            //比偶
            count=2;
            for (int j = 0; j < (i<(length-i-2)?i:(length-i-2)); j++)
            {
                if (st[i-1-j]==st[i+2+j])
                {
                    count+=2;
                }else
                {
                    break;
                }
            }
            if (count>max)
            {
                max=count;
            }
        }
        if ((i-1)>=0&&(st[i-1] == st[i + 1]))
        {
            //比奇
            count=3;
            for (int j = 0; j < (i-1 < (length - i - 2) ? i-1 : length - i - 2); j++)
            {
                if (st[i -2- j] == st[i+2+ j])
                {
                    count += 2;
                }
                else
                {
                    break;
                }
            }
            if (count > max)
            {
                max = count;
            }
        }
    }
    printf("%d",max);
    return 0;
}
