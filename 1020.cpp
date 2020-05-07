//二叉树里的所有节点都是不同的数字
//给后序和中序求层序.

//iput
//N<=30个节点,后序和前序

//层序,最后没空格

//遇到前序中序后序层序的题目,大多数情况下,有一个核心就是:不用建树
//在给定中序和x序之后,实际上一颗抽象的数已经被给出了,具有树完备的属性.(包括结构等)
//但是这种抽象的属性是需要把他们结合起来看并处理的
//这里就利用这种属性来生成层序.

//逻辑大概是:(实际上就是层序的逻辑)
//进队树,树抽象成中序
//进队树的子树,找子树的行为抽象成找子树序列(这里指由中序和后序找中序子树)
//出队这个树
//写完半个小时,改了半个小时....一共59分钟
#include <queue>
#include <stdio.h>
#include <vector>
using namespace std;
typedef struct sub
{
    int left;
    int right;
    int postleft;
    int postright;
} sub;
int main()
{
    int N;
    scanf("%d", &N);
    vector<int> postOrder(N + 5);
    vector<int> inOrder(N + 5);
    for (int i = 1; i < N + 1; i++)
    {
        scanf("%d", &postOrder[i]);
    }
    for (int i = 1; i < N + 1; i++)
    {
        scanf("%d", &inOrder[i]);
    }
    vector<int> levelOrder;
    int left = 1, right = N;
    queue<sub> qu;
    sub begin;
    begin.left = left;
    begin.right = right;
    begin.postleft = left;
    begin.postright = right;
    qu.push(begin);
    while (!qu.empty())
    {
        sub temp = qu.front();
        int rootValue = postOrder[temp.postright];
        if (temp.right - temp.left == 0)
        {
            levelOrder.push_back(rootValue);
            qu.pop();
            continue;
        }
        int rootIndex = -1;
        for (int i = temp.left; i < temp.right + 1; i++)
        {
            if (inOrder[i] == rootValue)
            {
                rootIndex = i;
                break;
            }
        }

        if (rootIndex == temp.left)
        {
            levelOrder.push_back(rootValue);
            qu.pop();
            sub temp2;
            temp2.left = temp.left + 1;
            temp2.right = temp.right;
            temp2.postleft = temp.postleft;
            temp2.postright = temp.postright - 1;
            qu.push(temp2);
            continue;
        }
        if (rootIndex == temp.right)
        {
            levelOrder.push_back(rootValue);
            qu.pop();
            sub temp2;
            temp2.left = temp.left;
            temp2.right = temp.right - 1;
            temp2.postleft = temp.postleft;
            temp2.postright = temp.postright - 1;
            qu.push(temp2);
            continue;
        }
        int leftsize = rootIndex - temp.left;
        int rightsize = temp.right - rootIndex;

        sub tempLeft;
        sub tempRight;
        levelOrder.push_back(rootValue);
        qu.pop();
        tempLeft.left = temp.left;
        tempLeft.right = rootIndex - 1;
        tempLeft.postleft = temp.postleft;
        tempLeft.postright = temp.postleft + leftsize-1;
        tempRight.left = rootIndex + 1;
        tempRight.right = temp.right;
        tempRight.postleft = temp.postright -rightsize;
        tempRight.postright = temp.postright-1;
        qu.push(tempLeft);
        qu.push(tempRight);
    }
    for (int i = 0; i < N; i++)
    {
        printf("%d", levelOrder[i]);
        if (i != N-1)
        {
            printf(" ");
        }
    }
}
