//N<=40000课程数
//K<=2500课程总数
//课程号i[1,K] 注册学生数
//Ni个学术的名字 3个大写字符和一个数字
//最后一行是N个来查询的学生

//打印名称 课程总数 课程号的升序 行末不能有空格
//我自己是用map做的,这里贴的是柳神的思路
//说一个map的思路,构造一个map里面存名字和课程链表头结点.每轮读取课程往name对应的链表里插一个课程,find一下提取链表然后排序输出
//里面一个很核心的就是把三个英文字母加一个数字的name变成一个int
//这个思路是大写英文字符只能在26范围之内,这样构件一个26*26*26的数(可以把英文字母理解成26进制)就可以存下,然后在*10把最低的10位用来存后面的数字
//然后在使用的时候解码就行.柳神真美啊.
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int getid(char *name)
{
    int id = 0;
    for (int i = 0; i < 3; i++)
        id = 26 * id + (name[i] - 'A');
    id = id * 10 + (name[3] - '0');
    return id;
}
const int maxn = 26 * 26 * 26 * 10 + 10;
vector<int> v[maxn];
int main()
{
    int n, k, no, num, id = 0;
    char name[5];
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d %d", &no, &num);
        for (int j = 0; j < num; j++)
        {
            scanf("%s", name);
            id = getid(name);
            v[id].push_back(no);
        }
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%s", name);
        id = getid(name);
        sort(v[id].begin(), v[id].end());
        printf("%s %lu", name, v[id].size());
        for (int j = 0; j < v[id].size(); j++)
            printf(" %d", v[id][j]);
        printf("\n");
    }
    return 0;
}
