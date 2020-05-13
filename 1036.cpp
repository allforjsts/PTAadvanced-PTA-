//N行学生数据 name gender ID grade
//name ID 不超过 10位 gender是F或者M grade[0,100] 保证成绩不重复

//输出3行
//name ID 最高分的女学生
//name Id 最低分的男学生
//输出差 
//缺少输出Absent 第三行输出NA
//主要思想就是在线存住最大的女和最小的男,没存到也要有标记(这里用了一个范围之外的数标记)
#include <stdio.h>
#include <vector>
typedef struct student
{
    char name[11]={0};
    char ID[11]={0};
    short grade=-1;
}student;
using namespace std;
int main(int argc, char const *argv[])
{
    student male;
    male.grade=101;
    student female;
    female.grade=-1;
    int N;
    scanf("%d",&N);
    char gender;
    char name[11]={0};
    char ID[11]={0};
    short grade=-1;
    for (int i = 0; i < N; i++)
    {
        scanf("%s %c %s %hd",name,&gender,ID,&grade);
        if (gender=='M')
        {
            if (grade<male.grade)
            {
                for (int j = 0; j < 11; j++)
                {
                    male.name[j]=name[j];
                    male.ID[j]=ID[j];
                }
                male.grade=grade;
            }            
        }else
        {
            if (grade > female.grade)
            {
                for (int j = 0; j < 11; j++)
                {
                    female.name[j] = name[j];
                    female.ID[j] = ID[j];
                }
                female.grade = grade;
            }
        }    
    }
    if (female.grade==-1&&male.grade==101)
    {
        printf("Absent\nAbsent\nNA");
        return 0; 
    }
    if (female.grade==-1)
    {
        printf("Absent\n%s %s\nNA", male.name, male.ID);
        return 0;
    }
    if (male.grade==101)
    {
        printf("%s %s\nAbsent\nNA", female.name, female.ID);
        return 0;
    }
    printf("%s %s\n%s %s\n%d", female.name, female.ID,male.name,male.ID,female.grade-male.grade);

    return 0;
}
