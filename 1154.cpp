//合适的顶点颜色使得任意同边节点不是相同的颜色
//用了最多K种颜色叫a (proper) k-coloring.
//是否是proper  k-coloring.

//NM<10^4 是顶点和边的总数
//M条边 两端 0-N-1
//K<=100
//K行每行代表一种上色,N个颜色,用int范围里的非负数表示
//第i个颜色就是第i个顶点的颜色

//先建立顶点
//上色然后遍历边看相邻节点颜色是不是不一样.

#include <set>
#include <stdio.h>
#include <vector>
#include <stack>
typedef struct edge
{
    int a;
    int b;
} edge;

int main(int argc, char const *argv[])
{
    int N,M;
    scanf("%d %d",&N,&M);
    std::vector<int> graph(N);
    std::vector<edge> e;
    for (int i = 0; i < M; i++)
    {
        edge temp;
        scanf("%d %d", &temp.a, &temp.b);
        e.push_back(temp);
    }
    int K;
    scanf("%d",&K);
    
    for (int i = 0; i < K; i++)
    {
        bool proper = true;
        std::set<int> colorSet;
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &graph[i]);
            colorSet.insert(graph[i]);//注意应该放到这里
        }
        for (int i = 0; i < M; i++)
        {
            int a = graph[e[i].a];
            int b = graph[e[i].b];
            //一开始我把插入颜色放在这里了,可是会有一些点没有边但是有颜色
            if (a == b)
            {
                proper=false;
                break;
            }

        }
        if (proper==false)
        {
            printf("No\n");
        }else 
        {
            printf("%lld-coloring\n",colorSet.size());
        }
    }
    

    
    
    return 0;
}
