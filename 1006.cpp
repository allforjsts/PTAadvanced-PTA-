
#include <cstdio>
#include <iostream>
#include <limits.h>
#include <stdio.h>
#include <string>
using namespace std;
int main() {
  int m;
  scanf("%d", &m);
  int hour;
  int minute;
  int second;
  int trueintimebysecond[m];
  int trueouttimebysecond[m];
  string idNumber[m]; //这里用字符数组也可以,稍微麻烦一点点
  int min=INT32_MAX;
  int mincnt=-1;
  int max=0;
  int maxcnt=-1;
  for (int i = 0; i < m; ++i) {
    getchar();
    cin >> idNumber[i];
    scanf("%d:%d:%d", &hour, &minute, &second);
    getchar();
    trueintimebysecond[i] = hour * 3600 + minute * 60 + second;
    if (trueintimebysecond[i]<min) {
    min=trueintimebysecond[i];
    mincnt=i;
    }
    scanf("%d:%d:%d", &hour, &minute, &second);
    trueouttimebysecond[i] = hour * 3600 + minute * 60 + second;
    if (trueouttimebysecond[i]>max) {
        max=trueouttimebysecond[i];
        maxcnt=i;
    }
  }
  printf("%s %s",idNumber[mincnt].c_str(), idNumber[maxcnt].c_str());
  //input
  
}
