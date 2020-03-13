#include <iostream>
#include <queue>
#include <stdio.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  ////    queue editon
  //   queue<int> queue;
  //   int floor;
  //   queue.push(0);
  //   for (int i = 0; i < n; ++i) {
  //     scanf("%d", &floor);
  //     queue.push(floor);
  //   }
  //   int sum=0;
  //   while (queue.size()-1) {
  //       int tem=queue.front();
  //       queue.pop();
  //       if (queue.front()-tem>0) {
  //         sum += (queue.front() - tem)*6+5;
  //       } else if (queue.front() - tem<0) {
  //         sum+=(tem-queue.front())*4+5;
  //       }else {
  //           sum+=5;
  //       }
  //   }
  //   cout<<sum;
  int queue[n + 5];
  int firstpoint = -1, lastpoint = 0;
  queue[lastpoint++] = 0;
  int floor;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &floor);
    queue[lastpoint++] = floor;
  }
    int sum=0;
  while (firstpoint + 2 != lastpoint) {
    if (queue[firstpoint + 1] - queue[firstpoint + 2]>0) {
      sum += (queue[firstpoint + 1] - queue[firstpoint + 2])*4+5;
    } else if (queue[firstpoint + 1] - queue[firstpoint + 2]<0) {
      sum += -(queue[firstpoint + 1] - queue[firstpoint + 2])*6+5;
    }else {
    sum+=5;
    }
    ++firstpoint;
  }
  printf("%d",sum);
}
