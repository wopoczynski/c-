#include<stdio.h>
#include<time.h>
#include<stdlib.h>

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

int main(void)
{

    int *A, m=0, n, i, j;
    FILE * file;
    FILE * file2;
    srand(time(NULL));

    n=rand()%200+100;
    //n=10;
    A=(int*)malloc(n*sizeof(int));
    wypelniacz(A,n);
    file=fopen("tablica.txt","w");
    for(i=0;i<n;i++)
    {
        fprintf(file,"%d\t%d\n",i,*A);
        A++;
    }
    A-=n;

    file2=fopen("tablica2.txt","w");
        for (j=0;j<5;j++)
        {

            m+=n;
            n=rand()%200+100;
            //n=10;
            A=(int*)realloc(A,(n+m)*sizeof(int));

            A+=m;
            wypelniacz(A,n);
            A-=m;

        }

        for(i=0;i<m+n;i++)
        {
            fprintf(file2,"%d\t%d\n",i,*A);
            A++;
        }
printf("\n\n%d\n\n",m+n);
    fclose(file2);
    fclose(file);
    free(A);
    return 0;
}
