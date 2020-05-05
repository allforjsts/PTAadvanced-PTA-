//假设银行有K个窗口.黄线分成两个部分,假定每个用户使用单个窗口不能超过1小时
//给到达时间T和处理时间P
//需要给平均等待时间

//N(<=10^4)个客户K(<=100)个窗口
//N行时间
//假定没有同时到达的客户.

//输出平均等待时间,精度1位小数.

#include <algorithm>
#include <stdio.h>
#include <vector>
#include<iostream>
typedef struct node
{
    int hour,minute,second;
    long long processTime;
    long long inTime;
}node;

typedef struct window
{
        //int ID;
        long long freeTime=0;

}window;
bool cmp(node a,node b){
    return a.inTime<b.inTime;
}
using namespace std;
int main(){
    int N,K;
    cin>>N>>K;
    vector<node> custom(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d:%d:%d", &custom[i].hour, &custom[i].minute, &custom[i].second);
        scanf("%lld", &custom[i].processTime);
        custom[i].processTime*=60;
        custom[i].inTime = custom[i].hour * 60 * 60 + custom[i].minute * 60 + custom[i].second;
    }
    vector<window> wds(K);
    sort(custom.begin(),custom.end(),cmp);
    long long opentime=8*60*60;
    long long closetime=17*60*60;
    long long waitTime = 0;
    //早来的把他的处理时间延长早来的时间即可.
    for (int i = 0; i < N; i++)
    {
        if (custom[i].inTime < opentime)
        {
            custom[i].processTime += opentime - custom[i].inTime;
            waitTime += opentime - custom[i].inTime; //注意早来的等待时间也算
        }
    }
    //foreach只能读不能改.
    int idCount=0;
    int min;
    int countCount=0;
    while (idCount < N && custom[idCount].inTime < closetime)//迟来的让他爬不要浪费资源
    {
        min=0;
        for (int i = 0; i < K; i++)
        {
            if (wds[i].freeTime<wds[min].freeTime)
            {
                min=i;
            }
        }
        if (wds[min].freeTime<custom[idCount].inTime)
        {
            wds[min].freeTime = custom[idCount].inTime+custom[idCount].processTime;
            idCount++;
            countCount++;
        }else{
            waitTime += wds[min].freeTime - custom[idCount].inTime;
            wds[min].freeTime = wds[min].freeTime+custom[idCount].processTime;
            idCount++;
            countCount++;
        }
    }

    double averageMinute =0; 
    if (countCount!=0)
    {
        averageMinute = waitTime / countCount;
        averageMinute/=60;
    }
    printf("%.1lf",averageMinute);
}

