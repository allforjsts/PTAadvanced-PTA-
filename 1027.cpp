//火星上的颜色由6位组成分别是两位Red两位Green两位Blue
//不过他们用的是13进制0-9A-C(我们是16)
//给三个十进制的颜色(0,168),输出火星的RGB颜色

//首先输出#然后输出3个颜色,英文字母需要大写,只有1位需要补0
//用时16分钟
#include <stdio.h>
#include <vector>
int main()
{
    std::vector<int> color(1);
    int temp;
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &temp);
        color.push_back(temp);
    }
    char r[4] = {0}, g[4] = {0}, b[4] = {0};
    int i = 1;
    for (int j = 2; j > 0; j--)
    {
        temp = color[i] % 13;
        color[i] /= 13;
        if (temp < 10)
        {
            r[j] = temp + 48;
        }
        else
        {
            switch (temp)
            {
            case 10:
                r[j] = 'A';
                break;
            case 11:
                r[j] = 'B';
                break;
            case 12:
                r[j] = 'C';
                break;
            default:
                break;
            }
        }
    }
    i=2;
    for (int j = 2; j > 0; j--)
    {
        temp = color[i] % 13;
        color[i] /= 13;
        if (temp < 10)
        {
            g[j] = temp + 48;
        }
        else
        {
            switch (temp)
            {
            case 10:
                g[j] = 'A';
                break;
            case 11:
                g[j] = 'B';
                break;
            case 12:
                g[j] = 'C';
                break;
            default:
                break;
            }
        }
    }
    i=3;
    for (int j = 2; j > 0; j--)
    {
        temp = color[i] % 13;
        color[i] /= 13;
        if (temp < 10)
        {
            b[j] = temp + 48;
        }
        else
        {
            switch (temp)
            {
            case 10:
                b[j] = 'A';
                break;
            case 11:
                b[j] = 'B';
                break;
            case 12:
                b[j] = 'C';
                break;
            default:
                break;
            }
        }
    }
    printf("#%c%c%c%c%c%c",r[1],r[2],g[1],g[2],b[1],b[2]);
}
