//加还是不加呢这是一个问题
//Cmax<=100油箱大小
//D<=30000距离,Davg<=20平均每单元汽油可以跑的距离N<=500加油站的总数
//N行每行一对非负数第i个加油站的油价,和这个站离出发点的距离.

//2位小数输出最便宜的钱.
//最开始假设油箱空
//不能到输出最长汽车能开多远.
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef struct station
{
    double price=-1.0;
    int distance=-1;
}station;

bool cmp(station a,station b){
    return a.distance==b.distance?a.price<b.price:a.distance<b.distance;
}
int main(int argc, char const *argv[])
{
    int C,D,Davg,N;
    scanf("%d %d %d %d",&C,&D,&Davg,&N);
    if (N == 0)
    {
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    vector<station> s(N+2);
    for (int i = 1; i <= N; i++)
    {
        scanf("%lf %d",&s[i].price,&s[i].distance);
    }
    s[N+1].price=0.0;
    s[N+1].distance=D;
    int longest=C*Davg;
    //input
    //开始模拟
    sort(s.begin()+1,s.end(),cmp);
    int nowDistance=0;
    int nowCount=1;
    int willbe=0;
    double finalPrice=0.0;
    double nowC=0.0;
    if (s[1].distance != 0)
    {
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    double nowPrice=s[1].price;
    willbe = longest;
    int mincnt=0;
    bool reachable=true;
    while (1)
    {
        //把当前位置到当前位置加满的所有加油站入组
        //组里如果有比当前价格低的,加油到刚好够跑到最近的低价点.
        //组里如果都比当前价格高,加足够多然后跑到价格最低的点再加.
        willbe=nowDistance+longest;
        vector<int> q;
        for (int i = nowCount; i <= N+1; i++)
        {
            if (s[i].distance>willbe)
            {
                break;
            }
            if (s[i].distance<=nowDistance)
            {
                continue;
            }
            q.push_back(i);
        }
        if (q.size() == 0 && nowDistance+longest<D)
        {
            reachable=false;
            break;
        }
        mincnt = 0;
        for (int i = 0; i < q.size(); i++)
        {
            if (s[q[i]].price <= nowPrice)
            {
                mincnt = i;
                break;
            }
            if (s[q[i]].price <= s[q[mincnt]].price)
            {
                mincnt = i;
            }
        }
        int nextcnt=q[mincnt];
        //在本站加油
        double useToNextC = (s[nextcnt].distance - nowDistance) / (double)Davg;
        if (s[nextcnt].price<=nowPrice)
        {
            double needC= useToNextC-nowC;
            if (needC>=0)
            {
                finalPrice += needC * nowPrice;
                nowC=useToNextC;
            }
        }else
        {
            double toEnd=(D-nowDistance)/(double)Davg;
            double upToC=toEnd<C?toEnd:C;
            finalPrice+=(upToC-nowC)*nowPrice;
            nowC = upToC;
        }
        //到达下一站
        nowC-=useToNextC;
        nowCount=nextcnt;
        nowDistance=s[nowCount].distance;
        nowPrice=s[nowCount].price;
        if (s[nowCount].distance==D)
        {
            break;
        }
    }
    if (reachable)
    {
        printf("%.02f",finalPrice);
    }else
    {
        printf("The maximum travel distance = %d.00", nowDistance + longest);
    }
    
    

    
    
    return 0;
}
