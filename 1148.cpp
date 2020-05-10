//狼人杀(本人没玩过)
//五个人分两拨,2个狼人,其中之一说谎,还有一个人类说谎.(一共2说谎的)
//N个玩家里面2个狼人,有一个狼说谎,一个人说谎,指出狼人

//N>=2 N<=100
//N行每行是第i个玩家的声明,正数指认那个玩家是人,负数指认那个玩家是狼

//有解输出最小解序列
//没解说出No Solution

#include <cmath>
#include <stdio.h>
#include <vector>
#include<iostream>
int main(int argc, char const *argv[])
{
    int N;
    scanf("%d",&N);
    std::vector<int> said(N+1);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d",&said[i]);
    }
    for (int i = 1; i <=N; i++)
    {
        for (int j = i+1; j <= N; j++)
        {
            std::vector<int> good(N + 1, 1);
            std::vector<int> lie;
            // for (int l = 1; l < N; l++)
            // {
            //     good[l]=1;
            // }
            good[i]=-1;
            good[j]=-1;
            for (int k = 1; k <= N; k++)
            {
                if (said[k] * good[std::abs(said[k])] < 0) //第k个人说的第said[k]个人的情况和假设的第said[k]个人的情况不相符
                {
                    lie.push_back(k);
                }
                
            }
            if (lie.size()==2&&good[lie[0]]+good[lie[1]]==0)//恰好有两个人说谎,而且两个人在假设里一个是好人一个是狼
            {
                std::cout << i << " " << j;
                return 0;
            }
            
            
        }
        
    }
    std::cout<<"No Solution";
    return 0;
}
