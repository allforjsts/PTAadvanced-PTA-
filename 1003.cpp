#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
};
int main(void) {
  //输入,用numberOfNodes保存树的节点数(0,100),numberOfNoleafs保存非叶节点数(0,numberOfNodes),
  // list[i][j]表示i号节点的第j个儿子的编号.list被初始化成全-1,list最后一个保存i有几个儿子.
  int numberOfNodes, numberOfNoleafs;
  int id, k;
  int list[105][105];
  for (int i = 0; i < 105; ++i) {
    for (int j = 0; j < 105; ++j) {
      list[i][j] = -1;
    }
  } // initiate
  scanf("%d%d", &numberOfNodes, &numberOfNoleafs);
  for (int i = 0; i < numberOfNoleafs; ++i) {
    cin>>id>>k;
    list[id][104] = k;
    for (int j = 0; j < k; ++j) {
      cin>>list[id][j];
    }
  }; //输入结束
  //接下来就是针对list保存的关系进行遍历,这里由于要求输出每层的子叶数,故采用BFS
  //用一个数组numberOfLeafs[]保存每层的子叶数量,levelCount保存层数
  int numberOfLeafs[105] = {0};
  int levelCount = 1;//levelcount表示现在访问levelcount层
  int queue[105];
  int sign = 0;
  int firstPoint = -1;
  int lastPoint = 0;
  queue[0] = 1;
  ++lastPoint;
  int cnt = 1;  //统计如果队列的点的总数
  int cmp = 0;  //第cmp个访问的节点
  int last = 1; //当前层数的最后一个节点将被访问的编号
  while (lastPoint != firstPoint + 1) {
    sign = 0;
    cmp++;
    for (int i = 0; i < list[queue[firstPoint + 1]][104]; ++i) {
      queue[lastPoint] = list[queue[firstPoint + 1]][i];
      ++lastPoint;
      ++sign;cnt++;
    } // push
    if (!sign) {
      ++numberOfLeafs[levelCount];
    }
    if (last == cmp) {
      levelCount++;
      last = cnt;
      //之后开始访问第levelcnt层
    }
    ++firstPoint;
  }
  // output
  for (int i = 1; i < levelCount; ++i) {
    printf("%d", numberOfLeafs[i]);
    if (i != levelCount-1) {
      printf(" ");
    }
  }
}

/*
数据
2 1
01 1 02

数据
3 2
01 1 02
02 1 03

数据
3 1
1 2 2 3


数据
72 34
01 5 26 4 66 11 31
26 5 57 60 14 17 25
04 2 69 20
57 4 35 13 16 45
66 3 41 36 56
69 3 37 2 7
41 3 58 38 65
35 4 46 68 59 61
11 2 15 44
14 1 18
37 1 6
13 2 30 67
30 1 34
46 3 42 27 62
18 2 72 71
42 3 29 51 53
31 1 12
12 2 54 63
15 5 5 52 47 21 64
17 4 8 23 19 49
08 1 24
23 1 9
52 2 39 3
24 1 48
48 1 10
54 1 70
71 1 55
06 1 43
64 1 33
39 1 50
70 1 22
20 1 40
25 1 32
40 1 28

对应输出应该为:

0 0 4 14 9 7 4

数据
52 24
01 12 31 23 41 48 12 47 2 45 6 18 49 33
31 2 24 16
23 3 17 28 37
41 2 46 39
17 2 20 26
28 3 36 3 5
20 1 15
24 2 34 21
48 3 44 32 9
47 1 7
36 1 30
46 1 42
16 2 22 50
34 1 13
37 1 35
39 3 52 51 14
26 1 40
06 1 19
40 1 25
19 1 27
50 2 4 10
15 2 43 11
09 2 38 29
43 1 8


对应输出应该为:

0 6 3 12 4 2 1
*/



