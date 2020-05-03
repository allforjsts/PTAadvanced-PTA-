//给N个城市和M条路,这里先假设给的是一个连通图
//咨询假设K个城市可能沦陷,那么沦陷的每个城市需要加几条路使城市从新连通(显而易见这个范围是[0,N-2])
#include <stdio.h>
#include <stdlib.h>
int main()
{
        // input
        // NMK就是题目里的NMK用highways存路用concern存需要check的city.
        int N, M, K;
        scanf("%d %d %d", &N, &M, &K);
        getchar();
        //动态申请一个二维数组highways,因为这里N可以取到1000所以要么动态定义要么写在全局变量里,Cpp的stack没有这么大.
        // //cpp写法
        //   int **highways = new int *[1024];
        //   for (int i = 0; i < N; i++)
        //   {
        //         highways[i]=new int [1024];
        //   }
        // //释放
        //   for (int i = 0; i < N; i++)
        //   {
        //       delete[] highways[i];
        //   }
        //   delete[] highways;

        //c写法
        int **highways = (int **)malloc(sizeof(int *) * N);
        for (int i = 0; i < N; i++)
        {
                *(highways + i) = (int *)malloc(sizeof(int) * N);
        }
        // for (int  i = 0; i < N; i++)
        // {
        //         free(*(highways+i));
        // }
        // free(highways);
        for (int i = 0; i < N; i++)
        {
                for (int j = 0; j < N; j++)
                {
                        *(*(highways + i) + j) = 0;
                }
        }
        //read road
        int i1, i2;
        for (int i = 0; i < M; i++)
        {
                scanf("%d %d", &i1, &i2);
                highways[i1-1][i2-1]=1;

                *(*(highways + i2 - 1) + i1 - 1) = 1;
        }
        // //check
        // for (int i = 0; i < N; i++)
        // {
        //         for (int j = 0; j < N; j++)
        //         {
        //                 printf("%d ", *(*(highways + i) + j));
        //                 printf("%d",highways[i][j]);
        //                 printf("\t");
        //         }
        //         printf("\n");
        // }

        //read concerned cities
        int* concern=(int*)malloc(sizeof(int)*K);
        for (int i = 0; i < K; i++)
        {
                scanf("%d",concern+i);
        }
        
        //input finished;
       
        //找有几个连通分量
        int *visited = (int *)malloc(sizeof(int) * N);
        int *countOfRoad=(int *)malloc(sizeof(int)*K);
        for (int i = 0; i < K; i++)
        {
                countOfRoad[i]=0;
        }
        
        for (int i1 = 0; i1 < K; i1++)
        {
                for (int i = 0; i < N; i++)
                {
                        *(visited + i) = 0;
                }
                int lostCity=concern[i1]-1;
                ++visited[lostCity];
                

                int* stack=(int*)malloc(sizeof(int)*N);
                for (int j = 0; j < N; j++)
                {
                        stack[j]=-1;
                }
                
                int sign=1;
                while (sign==1)
                {
                        int topPoint = 0;
                        stack[topPoint] = 0;
                        while (visited[stack[topPoint]] == 1)
                        {
                                ++stack[topPoint];
                                stack[topPoint]%=N;
                        }
                        visited[stack[topPoint]] = 1;
                        ++topPoint;
                        while (topPoint != 0)
                        {
                                --topPoint;
                                int tempt = stack[topPoint];
                                for (int i = 0; i < N; i++)
                                {
                                        if (highways[tempt][i] == 1 && visited[i] == 0 && i != lostCity && tempt != lostCity) //tempt!=lostCity这句好像没什么用.
                                        //这里就是遍历路进栈连通城市,但是注意不能把被摧毁的城市和它的通路用上.
                                        {
                                                stack[topPoint] = i;
                                                visited[i] = 1;
                                                ++topPoint;
                                        }
                                }
                        }
                        sign=0;
                        for (int i = 0; i < N; i++)
                        {
                                if (visited[i] == 0)
                                {
                                        sign = 1;
                                        break;
                                }
                        }
                        if (sign == 1)
                        {
                                ++countOfRoad[i1];
                        }
                }
                free(stack);
        }
        
        for (int i = 0; i < K; i++)
        {
                printf("%d\n",countOfRoad[i]);
        }
        
        

        //release resources
        free(visited);
        free(countOfRoad);
        free(concern);
        for (int  i = 0; i < N; i++)
        {
                free(*(highways+i));
        }
        free(highways);
}
