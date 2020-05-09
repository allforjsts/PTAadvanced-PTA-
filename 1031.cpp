//下降n1,走平n2,上n3
//n1=n2=max{k|k<=n2for all 3<=n2<=N}
//n1+n2+n3-2=N;
//N>=5<=80

//5-80个char
#include <stdio.h>
#include<cstring>
int main(int argc, char const *argv[])
{
    char a[85];
    scanf("%s",a);
    int length=strlen(a);
    int n1,n2,n3;
    n1=(length+2)/3;
    n2 = (length + 2) / 3;
    n3=length+2-n1-n2;
    for (int i = 0; i < n1-1; i++)
    {
        printf("%c",a[i]);
        for (int j = 0; j < n3-2; j++)
        {
            printf(" ");
        }
        printf("%c\n",a[length-1-i]);
    }
    for (int i = 0; i < n3; i++)
    {
        printf("%c",a[n1-1+i]);
    }
    
    return 0;
}

