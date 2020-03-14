#include <cstdio>
#include <stdio.h>
using namespace std;
//注意本题和牛客网上的有一个测试用例不一致,和PTA官网完全一致,个人发现牛客数据将一个2.8499999数据在输出时输出成了2.9,本人的方案输出2.8
//估计是牛客在计算过程中就进行了舍入导致精度不一致,在PTA完全没问题.
int main() {
  int k1;
  scanf("%d", &k1);
  float exp1[2005];
  for (int i = 0; i < 2005; ++i) {
    exp1[i] = 0.0;
  }
  int getexp;
  float getcoe;
  float exp2[2005];
  for (int i = 0; i < 2005; ++i) {
    exp2[i] = 0.0;
  }
  for (int i = 0; i < k1; ++i) {
    scanf("%d%f", &getexp, &getcoe);
    exp1[getexp] = getcoe;
  }
  int k2;
  scanf("%d", &k2);
  for (int i = 0; i < k2; ++i) {
    scanf("%d%f", &getexp, &getcoe);
    for (int j = 0; j < 2005; ++j) {
      if (exp1[j] !=0.0) //浮点
      {
          exp2[j + getexp] += exp1[j] * getcoe;
      }
    }
  }
  int number=0;
  int count[100];
  for (int i=2005-1; i>=0; --i) {
    if (exp2[i]!=0.0) {
        count[number]=i;
        ++number;
    }
  }
  printf("%d",number);
  for (int i=0; i<number; ++i) {
    printf(" %d %.1f",count[i],exp2[count[i]]);
  }
  return 0;
}
