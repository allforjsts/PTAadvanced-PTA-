#include <cstdio>
#include <stdint.h>
#include <stdio.h>
using namespace std;

int main() {
  int k;
  scanf("%d", &k);
  getchar();
  int list[k];
  for (int i = 0; i < k; ++i) {
    scanf("%d", &list[i]);
  }
  if (k==1) {
    printf("%d %d %d", list[0], list[0], list[0]);
    return 0;
  }
  // input
  int max = INT32_MIN, maxfront = -1, maxafter = -1;
  int sum = list[0], front = 0, after = 0;
  for (int i = 0; i < k; ++i) {
    if (list[i] > max) {
      max = list[i];
      maxfront = i;
    }
  }
  if (max < 0) {
    printf("0 %d %d", list[0], list[k - 1]);
    return 0;
  } else if (max == 0) {
    printf("0 %d %d", list[maxfront], list[maxfront]);
    return 0;
  }
  max=0;
  maxfront=-1;
  while (after <k) {
      sum=0;
      for (int i=0; i<after-front+1; i++) {
        sum+=list[front+i];
      }
    if (max < sum) {
      maxfront = front;
      maxafter = after;
      max = sum;
    }else if (sum<0) {if (after+1<k) {
        front = after + 1;
    }else {
    break;
    }
    }
    ++after;
  }
  printf("%d %d %d", max, list[maxfront], list[maxafter]);
  return 0;
}
/*
data
10
-10 1 2 3 4 -5 -23 3 7 -21

output
10 1 4

data
10
-10 1 2 3 3 -5 -23 3 7 -21

output
10 3 7

data
10
-10 1 2 3 4 -5 -2 3 7 -21

ouput
13 1 7

data
1
3

output
3 3 3

data
3
-1 -2 -3

output
0 -1 -3

data
3
-1 0 -3

output
0 0 0
*/
