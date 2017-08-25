#include<stdio.h>
#include<stdlib.h>
#include<time.h>

using namespace std;

int exist(const char *fname)
{
    FILE * file;
    if(file=fopen(fname,"r"))
    {
        return 1;
    }else{
    return 0;
    }
}
void wypelniacz(int *A, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        *A=rand()%100+1;
        A++;
    }
}
void sortuj(int *A, int n)
{
    int i, j, z;
    int flag1=1,flag2;
    while(flag1==1)
    {
        flag2=1;
        for(j=0;j<n-1;j++)
        {
            if(*A<*(A+1))
            {
                z=*A;
                *A=*(A+1);
                *(A+1)=z;
                flag2=0;
            }
            A++;
        }A-=(n-1);
        n--;
        if(flag2==1)flag1=0;
    }
}

int main()
{
    srand(time(NULL));
    int * A, i, n;
    FILE * f1, * f2;
    //n=rand()%100+1;
    n=10000;
    A=(int *) (calloc(n,sizeof(int)));
    wypelniacz(A,n);

    f1=fopen("tablica1.txt","w");
    f2=fopen("tablica2.txt","w");
    for(i=0;i<n;i++)
    {
        fprintf(f1,"%d\t%d\n",i,*A);
        A++;
    }A-=n;
    sortuj(A,n);
    for(i=0;i<n;i++)
    {
        fprintf(f2,"%d\t%d\n",i,*A);
        A++;
    }A-=n;



    fclose(f2);
    fclose(f1);
    free(A);
    return 0;
}
