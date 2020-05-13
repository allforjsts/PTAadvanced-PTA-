//标题告诉我们,正正得正,负负得负.得到最多的正数
//Nc优惠卷集合个数
//Np产品集合个数
//NcNp<=10^5>=1数字不超int
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
bool cmp1(int a, int b)
{
    return a > b;
}
bool cmp2(int a,int b){
    return a<b;
}
int main(int argc, char const *argv[])
{
    int Nc, Np;
    scanf("%d", &Nc);
    vector<int> couponP, couponN;
    int temp;
    for (int i = 0; i < Nc; i++)
    {
        scanf("%d", &temp);
        if (temp > 0)
        {
            couponP.push_back(temp);
        }
        else if (temp < 0)
        {
            couponN.push_back(temp);
        }
    }
    scanf("%d", &Np);
    vector<int> productP, productN;
    for (int i = 0; i < Np; i++)
    {
        scanf("%d", &temp);
        if (temp > 0)
        {
            productP.push_back(temp);
        }
        else if (temp < 0)
        {
            productN.push_back(temp);
        }
    }
    sort(couponN.begin(), couponN.end(), cmp2);
    sort(couponP.begin(), couponP.end(), cmp1);
    sort(productN.begin(), productN.end(), cmp2);
    sort(productP.begin(), productP.end(), cmp1);
    int couponCount = 0;
    int productCount = 0;
    long long int money = 0;
    //正优惠卷找正产品
    while (couponCount < couponP.size() && productCount < productP.size())
    {
        //本节点操作
        money += couponP[couponCount] * productP[productCount];
        //到下一个节点去
        ++couponCount, ++productCount;
    }
    //负优惠卷找负产品
    couponCount = 0, productCount = 0;
    while (couponCount < couponN.size() && productCount < productN.size())
    {
        money += couponN[couponCount] * productN[productCount];

        ++couponCount,++productCount;
    }
    printf("%lld",money);
    return 0;
}
