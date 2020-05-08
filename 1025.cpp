//合并一下PTA的rank
//N<100个地点
//N个表每个表K<=300个考生包含ID13位和分数
//输出总人数和先排分数分数一样排id的非递减序列
//13位代表可以用longlong存,但是输出的时候切记.需要控制13位并补零.id前面的0毕竟是不可省略的.
#include <stdio.h>
#include <vector>
#include <algorithm>
typedef struct testee
{
    long long id;
    int score;
    int final_rank;
    int local_rank;
    int location_number;
} testee;
bool cmp(testee a,testee b){
    //先排分数分数一样排id
    return a.score!=b.score?a.score>b.score:a.id<b.id;
}
int main(int argc, char const *argv[])
{
    int N;
    scanf("%d",&N);
    std::vector<testee> final;
    int totalTestee=0;
    for (int l = 1; l <= N; l++)
    {
        int K;
        scanf("%d", &K);
        totalTestee=totalTestee+K;
        std::vector<testee> local;
        long long id;
        int score;
        for (int j = 0; j < K; j++)
        {
            scanf("%lld %d", &id,&score);
            testee tem;
            tem.id=id;
            tem.score=score;
            tem.location_number=l;
            local.push_back(tem);
        }
        std::sort(local.begin(),local.end(),cmp);
        int local_rank = 1;
        int sameCount=0;
        //因为要和上面比所以处理一下第一个
        local[0].local_rank=1;
        //从第二个开始
        for (int j = 1; j < local.size(); j++)
        {
            if (local[j].score==local[j-1].score)
            {
                ++sameCount;
            }else
            {
                local_rank=local_rank+1+sameCount;
                sameCount=0;
            }
            local[j].local_rank = local_rank;
                }
        final.insert(final.end(),local.begin(),local.end());
    }
    std::sort(final.begin(),final.end(),cmp);
    int final_rank=1;
    final[0].final_rank=1;
    int sameCount=0;
    for (int i = 1; i < final.size(); i++)
    {
        if (final[i].score==final[i-1].score)
        {
            ++sameCount;
            
        }else
        {
            final_rank = final_rank + 1 + sameCount;
            sameCount = 0;
        }
        
        final[i].final_rank=final_rank;
    }
    
    printf("%d\n",totalTestee);
    for(auto var : final)
    {
        printf("%013lld %d %d %d\n",var.id,var.final_rank,var.location_number,var.local_rank);
    }
    return 0;
}
