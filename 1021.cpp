//一个连通的和acyclic的图可以是一颗数,树高由选择的根节点决定
//找到使树高最高的根节点the deepest root
//N<=10^4节点,节点编号是1-N,于是有N-1条边
//输出最深根节点的编号如果不唯一按序号依次输出,给的不是树的情况打印error输出连通分量.

//实际上是找叶节点
#include <queue>
#include <stdio.h>
#include <vector>
#include <set>
#include<algorithm>
typedef struct treeNode
{
    int id;
    int level;
    struct treeNode *next=NULL;
}treeNode;
bool cmp(int a,int b){
    return a<b;
}
int main(int argc, char const *argv[])
{
    int N;
    scanf("%d",&N);
    std::vector<treeNode> cities(N + 5);
    for (int i = 1; i <= N; i++)
    {
        treeNode *temp = new treeNode;
        temp->id=i;
        cities[i]=*temp;
    }
    
    for (int j = 0; j < N-1; j++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        //给城市a加个邻接
        treeNode *it=&cities[a];
        while (it->next!=NULL)
        {
            it=it->next;
        }
        treeNode *temp=new treeNode;
        temp->id=b;
        it->next=temp;
        //给城市b加个邻接
        it=&cities[b];
        while (it->next != NULL)
        {
            it = it->next;
        }
        temp = new treeNode;
        temp->id = a;
        it->next = temp;
    }
    //检查是不是树
    bool *isVisited=new bool[N+5];
    for (int i = 1; i <= N; i++)
    {
        isVisited[i]=false;
    }
    int countOfK=0;
    for (int i = 1; i <=N; i++)
    {
        if (isVisited[i]==true)
        {
            continue;
        }
        isVisited[i] = true;
        ++countOfK;
        std::queue<int> que;
        cities[i].level = 1;
        que.push(i);
        while (!que.empty())
        {
            treeNode *temporary = cities[que.front()].next;
            while (temporary!=NULL)
            {
                if (isVisited[temporary->id]==false)
                {
                    cities[temporary->id].level = cities[que.front()].level + 1;
                    que.push(temporary->id);
                    isVisited[temporary->id] = true;
                    temporary = temporary->next;
                }else
                {
                    temporary = temporary->next;
                }
                
                
            }
            que.pop();
        }
        
    }
    if (countOfK!=1)
    {
        printf("Error: %d components",countOfK);
        return 0;
    }
    std::set<int> cnt;
    int max=-1;
    for (int i = 1; i <= N; i++)
    {
        if (cities[i].level>max)
        {
            max = cities[i].level;
        }
        
    }
    
    
    for (int i = 1; i <= N; i++)
    {
        if (cities[i].level == max)
        {
            cnt.insert(i);
            continue;
        }
    }
    for (int i = 1; i <= N; i++)
    {
        isVisited[i] = false;
    }
    
    isVisited[*cnt.begin()] = true;
    ++countOfK;
    std::queue<int> que2;
    cities[*cnt.begin()].level = 1;
    que2.push(*cnt.begin());
    while (!que2.empty())
    {
        treeNode *temporary = cities[que2.front()].next;
        while (temporary != NULL)
        {
            if (isVisited[temporary->id] == false)
            {
                cities[temporary->id].level = cities[que2.front()].level + 1;
                que2.push(temporary->id);
                isVisited[temporary->id] = true;
                temporary = temporary->next;
            }
            else
            {
                temporary = temporary->next;
            }
        }
        que2.pop();
    }
    max = -1;
    for (int i = 1; i <= N; i++)
    {
        if (cities[i].level > max)
        {
            max = cities[i].level;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (cities[i].level == max)
        {
            cnt.insert(i);
            continue;
        }
    }
    std::vector<int> cnt1;
    for(auto var : cnt)
    {
        cnt1.push_back(var);
    }
    sort(cnt1.begin(),cnt1.end(),cmp);
    for (int i = 0; i < cnt1.size(); i++)
    {
        printf("%d\n",cnt1[i]);
    }
    
    return 0;
}

