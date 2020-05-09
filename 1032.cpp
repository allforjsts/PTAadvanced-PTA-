//找一样的部分,我一开始还以为是KMP没想到是静态链表
//N<10^5
//这个数据结构里有一个非常关键的点
//在指向同一个元素之后,后面的所有元素都会是一样的,即出现第一个一样之后所有都一样

#include <vector>
typedef struct node
{
    bool isVisited = false;
    char data;
    int next=-1;
} node;

#include <stdio.h>
int main(int argc, const char** argv) {
    int ad1,ad2;
    int N;

    scanf("%d %d %d",&ad1,&ad2,&N);
    std::vector<node> all(100000);
    int ad,next;
    char data;
    for (int i = 0; i < N; i++)
    {
        scanf("%d %c %d", &ad, &data, &next);
        all[ad].data=data;
        all[ad].next=next;
    }
    next=ad1;
    while (next!=-1)
    {
        all[next].isVisited=true;
        next=all[next].next;
    }
    next=ad2;
    while (next != -1)
    {
        if (all[next].isVisited)
        {
            break;
        }
        next = all[next].next;
    }

    if (next == -1)
    {
        printf("-1");
        
    }else
    {
        printf("%05d", next);
    }
    
    
    
    
    return 0;
}
