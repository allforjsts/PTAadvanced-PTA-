//N<=10^5个记录,C是排列的列
//N行student记录,ID(6位),name<=8的char[],和成绩[0,100];
//输出排好的N行
//c==1Id增序,c==2,名字非递减,c==3,成绩非递减
//成绩或者名字一样,按id升序排列

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <vector>
#include <string>
typedef struct student{
    int ID;
    std::string name;
    int grade;
}student;
bool cmp1(student a,student b){
    return a.ID<b.ID;
}
bool cmp2(student a, student b)
{
    return a.name == b.name ? a.ID < b.ID : a.name.compare(b.name)<0;
}
bool cmp3(student a, student b)
{
    return a.grade == b.grade ? a.ID < b.ID : a.grade < b.grade;
}
int main(int argc, char const *argv[])
{
    int N,C;
    scanf("%d %d", &N, &C);
    std::vector<student> students(N);
    for (int i = 0; i < N; i++)
    {
        std::cin>>students[i].ID>>students[i].name>>students[i].grade;
    }
    if (C==1)
    {
        std::sort(students.begin(),students.end(),cmp1);
    }else if (C==2) {
        std::sort(students.begin(), students.end(), cmp2);
    }else
    {
        std::sort(students.begin(), students.end(), cmp3);
    }
    for (int i = 0; i < N; i++)
    {
        printf("%06d %s %d\n",students[i].ID,students[i].name.c_str(),students[i].grade);
    }
    
    
    return 0;
}
