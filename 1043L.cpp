//鉴于柳神这套代码比我的简洁十倍我还是贴柳神的吧.

//注意二叉搜索树的性质,排序一下preorder就是inorder了
//我这比脑子每次理解递归都挺nc的
#include <cstdio>
#include <vector>
using namespace std;
bool isMirror;
vector<int> pre, post;
void getpost(int root, int tail)
{
    if (root > tail)
        return;
    int i = root + 1, j = tail;
    if (!isMirror)
    {
        while (i <= tail && pre[root] > pre[i])
            i++;
        while (j > root && pre[root] <= pre[j])
            j--;
    }
    else
    {
        while (i <= tail && pre[root] <= pre[i])
            i++;
        while (j > root && pre[root] > pre[j])
            j--;
    }//i用来找比root大的最靠近左侧的元素j用来找比root小的最靠近右侧的元素
    if (i - j != 1)
        return;
    getpost(root + 1, j);
    getpost(i, tail);
    post.push_back(pre[root]);
}
int main()
{
    int n;
    scanf("%d", &n);
    pre.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    getpost(0, n - 1);
    if (post.size() != n)
    {
        isMirror = true;
        post.clear();
        getpost(0, n - 1);
    }
    if (post.size() == n)
    {
        printf("YES\n%d", post[0]);
        for (int i = 1; i < n; i++)
            printf(" %d", post[i]);
    }
    else
    {
        printf("NO");
    }
    return 0;
}
// 7 
// 8 6 5 7 10 8 11
