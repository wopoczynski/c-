#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <cmath>
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

using namespace std;

int main(void)
{
    clock_t start, stop;
    double czas;
    char name[20];
    int n, m, i, j, k=0;
    printf("Podaj nazwe pliku: ");
    scanf("%s",name);

if (exist(name)==1)
    {
        printf("plik istnieje!\n");
        double Gamma;
        double *Aout, *gamma;
        printf("podaj liczbê wierszy: ");
        scanf("%d",&n);
        printf("podaj liczbê kolumn: ");
        scanf("%d",&m);
        printf("podaj wspolczynnik Gamma: ");
        scanf("%lf",&Gamma);
            while (Gamma>4 || Gamma<0)
            {
            printf("Wspolczynnik Gamma jest z zakresu 0-4, podaj ponownie: \n");
            scanf("%lf",&Gamma);
            }
        Aout=(double *) (calloc(n*m,sizeof(double)));
        FILE * fr;
        FILE * fw;
            gamma=&Gamma;
            fr=fopen(name,"r");
            fw=fopen("outfile.txt","w");
            start=clock();

                 for (i=0;i<n;i++)
                {
                    for (j=0;j<m;j++)
                    {
                        fscanf(fr,"%lf",Aout);
                        fprintf(fw, "%lf\t",pow(*Aout,*gamma));
                        Aout++;
                    }
                fprintf(fw,"\n");
                }


            stop=clock();
            czas= (double)(stop-start)/CLOCKS_PER_SEC;
            printf("\n\nTworzenie pliku zajelo: %f",czas);


        fclose(fw);
        fclose(fr);
        free(Aout);

    }else
    {
        printf("podaj liczbe wierszy: ");
        scanf("%d",&n);
        printf("podaj liczbê kolumn: ");
        scanf("%d",&m);

            double *Ain;
            FILE * fw;
            fw=fopen(name,"w");

            Ain=(double *) calloc(n*m,sizeof(double));

            start=clock();
                for (i=0;i<n;i++)
                {
                    for (j=0;j<m;j++)
                    {
                        *Ain=k;
                        fprintf(fw, "%lf\t",*Ain);
                        Ain++;
                        k++;
                        k=k%256;
                    }
                    fprintf(fw, "\n");
                }
            stop=clock();
            czas= (double)(stop-start)/CLOCKS_PER_SEC;
            printf("\n\nTworzenie pliku zajelo: %f",czas);
            free(Ain);
            fclose(fw);
    }

return 0;
}
