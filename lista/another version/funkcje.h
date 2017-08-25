#ifndef FUNKCJE_H_INCLUDED
#define FUNKCJE_H_INCLUDED
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
using namespace std;
int exist(const char *fname)
{
    FILE * file;
    if(file=fopen(fname,"r"))
    {
        return 1;
    }
    else
    {
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
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-1; j++)
        {
            if(*A<*(A+1))
            {
                z=*A;
                *A=*(A+1);
                *(A+1)=z;
            }
            A++;
        }
        A-=(n-1);
    }
}
// obsluga listy
void print_list(cell* first)
{
    cell* x=first;
    std::cout<< x->getX()<<std::endl;
    while(x=x->getNEXT())
    {
        std::cout<< x->getX()<<std::endl;

    }
}

void add_at_end(cell** last, int value)
{
    cell* x;
    x= *last;
    *last=new cell(value, NULL, x);
    x->changeNEXT(*last);
}

void add_at_start(cell** first, int value)
{
    cell* x;
    x= *first;
    *first=new cell(value, x, NULL);
    x->changePREV(*first);
}
int count_list_elements(cell* first)
{
    int liczba_elementow=1;
    while(first=first->getNEXT())
    {
        liczba_elementow++;

    }
    return liczba_elementow;
}
void remove_first(cell** first)
{
    cell* x=*first;
    *first=x->getNEXT();
    delete(x);
    x=*first;
    x->changePREV(NULL);
}
void remove_last(cell** last)
{
    cell* x=*last;
    *last=x->getPREV();
    delete(x);
    x=*last;
    x->changeNEXT(NULL);
}
void add_in_order_rise(cell** first,int value)
{
    cell* x=*first;
    if(value==x->getX())
    {
        add_at_start(first,value);
        return;
    }
    while(x->getX()<value)
    {
        x=x->getNEXT();
    }
    cell *new_one=new cell(value,x,x->getPREV());
    x->changePREV(new_one);
    x=new_one->getPREV();
    x->changeNEXT(new_one);
}
cell* search_in_list(cell* first, int value)
{
    cell* x=first;
    while(x->getX()<value)
    {
        x=x->getNEXT();
    }

    return x;
}
void remove_from_list(cell* first,int value)
{
    cell* x=search_in_list(first,value),*y;
    y=x->getNEXT();
    x=x->getPREV();
    x->changeNEXT(y);
    y->changePREV(x);


}
cell** dodaj(char a[20])
{
cell** W[2];

    fstream plik;
    plik.open(a,ios::in);

        string linia;
        int nr_linii=1;
        int minimum, maximum;
        while(getline(plik,linia))
        {
            if(nr_linii==1)
            {
                minimum=atoi(linia.c_str());
                maximum=atoi(linia.c_str());
            }
            else
            {
                if(atoi(linia.c_str())<minimum) minimum=atoi(linia.c_str());
                if(atoi(linia.c_str())>maximum) maximum=atoi(linia.c_str());
            }
            nr_linii++;
        }
        plik.close();
        plik.clear();
        plik.open(a,ios::in);
        cell *first=new cell(minimum, NULL, NULL);
        W[0]=&first;
        cell *last=first;
        W[1]=&last;
        add_at_end(W[1],maximum);
        while(getline(plik,linia))
        {
            add_in_order_rise(W[0],atoi(linia.c_str()));
        }

        remove_first(W[0]);
        remove_last(W[1]);
        plik.close();
        plik.clear();
    return W[0];
}
#endif // FUNKCJE_H_INCLUDED
