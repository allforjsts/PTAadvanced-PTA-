//中位数奇数项是中间的,偶数项是中间靠前的.(size-1)/2
//两个序列的中位数指两个序列的并集非递减序列的中位数

//给的两个数列是递增的.
//N个数<2*10^5,数字在long int 范围内.一共2行
//..本来暴力法是写着玩的没想到居然过了,对了不要用cin,数据很多用cin很可能超时
//cin可以//ios::sync_with_stdio(false);加速一点但是还是比scanf慢
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>
bool cmp(long int a,long int b){
    return a<b;
}
int main(int argc, char const *argv[])
{
    int N1,N2;
    std::cin>>N1;
    std::vector<long int> s1(N1);
    for (int i = 0; i < N1; i++)
    {
        scanf("%ld",&s1[i]);
    }
    std::cin>>N2;
    std::vector<long int> s2(N2);
    for (int i = 0; i < N2; i++)
    {
        scanf("%ld", &s2[i]);
    }
    s1.insert(s1.end(),s2.begin(),s2.end());
    std::sort(s1.begin(),s1.end(),cmp);
    std::cout<<s1[(s1.size()-1)/2];
    return 0;
}
