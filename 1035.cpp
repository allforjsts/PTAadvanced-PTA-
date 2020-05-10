//改字符串
//N<=1000行
//每行一个user name 和一个密码
//都是不超过10位的char 没空格
//输出m个被改过的user name和密码.
//没有没改的另行输出

#include <stdio.h>
#include <vector>
#include<cstring>
typedef struct node
{
    char name[11]={0};
    char passward[11]={0};
}node;

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d",&N);
    std::vector<node> list(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%s %s",list[i].name,list[i].passward);
    }
    //input
    bool isModify=false;
    std::vector<int> modified;
    for (int i = 0; i < N; i++)
    {
        isModify=false;
        for (int j = 0; j < strlen(list[i].passward); j++)
        {
            switch (list[i].passward[j])
            {
            case '1':
            isModify=true;
                list[i].passward[j]='@';
                break;
            case '0':
                isModify = true;
                list[i].passward[j] = '%';
                break;
            case 'l':
                isModify = true;
                list[i].passward[j] = 'L';
                break;
            case 'O':
                isModify = true;
                list[i].passward[j] = 'o';
                break;
            default:
                break;
            }
        }
        if (isModify)
        {
            modified.push_back(i);
        }
    }
    if (modified.size())
    {
        printf("%d\n",(int)modified.size());
        for (int i = 0; i < modified.size(); i++)
        {
            printf("%s %s\n", list[modified[i]].name, list[modified[i]].passward);
        }
        
    }else
    {
        if (N==1)
        {
            printf("There is 1 account and no account is modified");
        }else
        {
            printf("There are %d accounts and no account is modified",N);
        }
        
        
    }
    
    

    return 0;
}
