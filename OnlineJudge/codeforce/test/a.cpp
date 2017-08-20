#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[3];
int mid;
int num;
int i,j;
int main()
{
    i = 1;j = 1000000;
    while(i != j)
    {
        mid= (i+j+1)/2;
        printf("%d\n",mid);
        fflush(stdout);
        scanf("%s",a);
        if(strcmp(a,"<")==0)
            j = mid-1;
        else if(strcmp(a,">=") == 0)
          i = mid;
    }
    printf("! %d\n",i);
    fflush(stdout);
}
