#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include "cell.h"
#include "funkcje.h"

int main (void)
{
    using namespace std;
    cell *first, *last, **W, *P;
    int p;

    char a[20];
    cout<<"podaj nazwe pliku"<<endl;
    cin>>a;
    fstream plik;
        plik.open(a,ios::in);
        if(plik.good()==false)
        {
            srand(time(NULL));
            int *A, i;
            A=(int*)calloc(100, sizeof(int));
            wypelniacz(A,100);
            plik.open(a,ios::out);
            for(i=0; i<100; i++)
            {
                plik<<*A<<endl;
                A++;
            }
            plik.close();
            plik.clear();
        }else{
                W=dodaj(a);
                first=*W;
             }


    print_list(first);
    p=10;
    P=search_in_list(first,p);
    remove_from_list(first, p);
    print_list(first);
    return 0;
}
