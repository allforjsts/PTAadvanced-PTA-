//20分的题,基本秒杀,但是这个题里面没有给出数据限定的范围,估计测试里又要恶心人了
//这题居然用了15分钟.主要因为喝了个奶吃了个膜片,膜片真好吃.

#include <stdint.h>
#include <stdio.h>
int main(){
    double a[3]={0.0};    
    double b[3]={0.0};
    double c[3] = {0.0};
    float amax = INT32_MIN;
    float bmax = INT32_MIN;
    float cmax = INT32_MIN;
    int acnt,bcnt,ccnt;
    scanf("%lf %lf %lf",&a[0],&a[1],&a[2]);
    for (int i=0; i<3; ++i) {
        if (amax<a[i]) {
            amax=a[i];
            acnt=i;
        }
    }
    switch (acnt) {
        case 0:
        printf("W ");break;
        case 1:
        printf("T ");break;
        case 2:
        printf("L ");break;
    }
    getchar();
    scanf("%lf %lf %lf", &b[0], &b[1], &b[2]);
    for (int i = 0; i < 3; ++i) {
      if (bmax < b[i]) {
        bmax = b[i];
        bcnt = i;
      }
    }
    switch (bcnt) {
    case 0:
      printf("W ");
      break;
    case 1:
      printf("T ");
      break;
    case 2:
      printf("L ");
      break;
    }
    getchar();    
    scanf("%lf %lf %lf",&c[0],&c[1],&c[2]);
    for (int i = 0; i < 3; ++i) {
      if (cmax < c[i]) {
        cmax = c[i];
        ccnt = i;
      }
    }
    switch (ccnt) {
    case 0:
      printf("W ");
      break;
    case 1:
      printf("T ");
      break;
    case 2:
      printf("L ");
      break;
    }
    getchar();
    printf("%.2f",(amax*bmax*cmax*0.65-1)*2);
    return 0;
}
