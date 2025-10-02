#include<stdio.h>

struct student{
    int grade;
    char name[21];
};

int main(void){
    int N;
    int i = 0;
    int t = 0;
    
    scanf("%d", &N);
    struct student information[N];
    while(i < N){
        scanf("%d %s", &information[i].grade, &information[i].name);
        if(information[i].grade > information[t].grade){
            t = i;
        }
        i++;
    }
    printf("%s", information[t].name);
    return 0;
}
