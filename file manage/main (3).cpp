#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int p_istnieje(const char *nazwapliku)
{
    FILE *file;
    if (file = fopen(nazwapliku, "r"))
    {
        return 1;
    }
    return 0;
}


int main(void)
{
    int n, m, i, j, k=0;
    double start, koniec, czas;
    char nazwa[20];
    printf("podaj nazwe pliku: ");
    scanf("%s",nazwa);

    if (p_istnieje(nazwa)==1)
    {
    // plik istnieje
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
            printf("Wspolczynnik Gamma musi byæ z zakresu 0-4, podaj poprawny\n");
            scanf("%lf",&Gamma);
            }
        double Aout[100][100];
        FILE * fr;
        FILE * fw;

        fr=fopen(nazwa,"r");
        fw=fopen("plikwyjsciowy.txt","w");
            start=time(NULL);
        for (i=0;i<n;i++)
        {
            for (j=0;j<m;j++)
            {
                fscanf(fr,"%lf",&Aout[i][j]);
                fprintf(fw, "%lf\t",Aout[i][j]*Gamma);
            }
            fprintf(fw,"\n");
        }
            koniec=time(NULL);
            czas= koniec-start;
            printf("\n\nTworzenie pliku zajelo: %f",czas);

        fclose(fw);
        fclose(fr);
    }
    else
    {
        printf("podaj liczbe wierszy: ");
        scanf("%d",&n);
        printf("podaj liczbe kolumn: ");
        scanf("%d",&m);
        double Ain[100][100];
        FILE * fw;
        fw=fopen(nazwa,"w");
            start=time(NULL);
        for (i=0;i<n;i++)
        {
            for (j=0;j<m;j++)
            {
                Ain[i][j]=(i%256);
                fprintf(fw, "%lf\t",Ain[i][j]);
            }
            fprintf(fw, "\n");
        }
        koniec=time(NULL);
        czas = koniec-start;
        printf("\n\nTworzenie pliku zajelo: %f",czas);
    fclose(fw);
    }
return 0;
}
