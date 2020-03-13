
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
  char n[105];
  cin >> n;
  int size = 0;
  for (int i = 0; i < 105; ++i) {
    if (n[i] == '\0') {
      break;
    }
    ++size;
  }
  // input
  int sum = 0;
  for (int i = 0; i < size; ++i) {
    sum += n[i] - 48; // char to int
  }
  if (sum==0) {
    cout<<"zero";
    return 0;
  }//解决0
  int cmp = sum;
  char pinyin[10];
  int digit = 0;
  while (cmp) {
    cmp /= 10;
    ++digit;
  }
  cmp = sum;
  int set[digit];//用set保存每一位从小到大,最后从大到小输出
  for (int i = 0; i < digit; ++i) {
    set[i] = cmp % 10;
    cmp /= 10;
  }
  for (int i = digit - 1; i >= 0; --i) {
    switch (set[i]) {
    case 0:
      strcpy(pinyin, "zero");
      break;
    case 1:
      strcpy(pinyin, "one");
      break;
    case 2:
      strcpy(pinyin, "two");
      break;
    case 3:
      strcpy(pinyin, "three");
      break;
    case 4:
      strcpy(pinyin, "four");
      break;
    case 5:
      strcpy(pinyin, "five");
      break;
    case 6:
      strcpy(pinyin, "six");
      break;
    case 7:
      strcpy(pinyin, "seven");
      break;
    case 8:
      strcpy(pinyin, "eight");
      break;
    case 9:
      strcpy(pinyin, "nine");
      break;
    }
    printf("%s", pinyin);
    if (i) {
      printf(" ");
    }
  }
  return 0;
}
