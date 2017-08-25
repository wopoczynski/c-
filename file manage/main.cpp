#include <stdio.h>
#include <conio.h>
#include <time.h>
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

int main(void)
{

    double start, end, czas;
    char name[20];
    int n, m, i, j, k=0;
    printf("Podaj nazwê pliku: ");
    scanf("%s",name);

    if (exist(name)==1)
    {
        printf("plik istnieje\n");
        double Gamma;
        printf("podaj liczbe wierszy: ");
        scanf("%d",&n);
        printf("podaj liczbe kolumn: ");
        scanf("%d",&m);
        printf("podaj wspolczynnik Gamma: ");
        scanf("%lf",&Gamma);
            while (Gamma>4 || Gamma<0)
            {
            printf("Wspolczynnik Gamma jest z zakresu 0-4, podaj ponownie: \n");
            scanf("%lf",&Gamma);
            }
        double Aout[n][m];
        double *w;
        FILE * fr;
        FILE * fw;

            w=&Aout[0][0];
            fr=fopen(name,"r");
            fw=fopen("outfile.txt","w");
            start=time(NULL);

                 for (i=0;i<n;i++)
                {
                    for (j=0;j<m;j++)
                    {
                        fscanf(fr,"%lf",w);
                        fprintf(fw, "%lf\t",*w*Gamma);
                        w++;
                   }
                fprintf(fw,"\n");
                }


            end=time(NULL);
            czas= end-start;
            printf("\n\nTworzenie pliku zajelo: %f",czas);


        fclose(fw);
        fclose(fr);


    }else
    {
        printf("podaj liczbe wierszy: ");
        scanf("%d",&n);
        printf("podaj liczbe kolumn: ");
        scanf("%d",&m);

            double Ain[n][m];
            double *w;
            FILE * fw;
            fw=fopen(name,"w");

            w=&Ain[0][0];

            start=time(NULL);
                for (i=0;i<n;i++)
                {
                    for (j=0;j<m;j++)
                    {
                        *w=k;
                        fprintf(fw, "%lf\t",*w);
                        w++;
                        k++;
                        k=k%256;
                    }
                    fprintf(fw, "\n");
                }
            end=time(NULL);
            czas= end-start;
            printf("\n\nTworzenie pliku zajelo: %f",czas);

            fclose(fw);
    }

    return 0;
}
