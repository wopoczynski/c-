#include <iostream>
#include <stddef.h>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <cstddef>

using namespace std;

class Lista
{
    private:
        int X;
        Lista *next, *prev;

    public:
        Lista(int X, Lista *next, Lista *prev);

        int getX();
        Lista *getNEXT();
        Lista *getPREV();
        void changeNEXT(Lista* next);
        void changePREV(Lista* prev);


        virtual ~Lista();
};
void remove_first(Lista** first);
void remove_last(Lista** last);
void add_at_start(Lista** first, int value);
void add_at_end(Lista** last, int value);
void add_in_order_rise(Lista** first,int value);
Lista* search_in_list(Lista* first, int value);


int main()
{
    Lista *start;
    start=NULL;
    return 0;
}

void add_at_start(Lista** first, int value)
{
    Lista* x;
    x= *first;
    *first=new Lista(value, x, NULL);
    x->changePREV(*first);
}
void add_at_end(Lista** last, int value)
{
    Lista* x;
    x= *last;
    *last=new Lista(value, NULL, x);
    x->changeNEXT(*last);
}
void add_in_order_rise(Lista** first,int value)
{
    Lista* x=*first;
    if(value==x->getX())
    {
        add_at_start(first,value);
        return;
    }
    while(x->getX()<value)
    {
        x=x->getNEXT();
    }
    Lista *new_one=new Lista(value,x,x->getPREV());
    x->changePREV(new_one);
    x=new_one->getPREV();
    x->changeNEXT(new_one);
}
void remove_first(Lista** first)
{
    Lista* x=*first;
    *first=x->getNEXT();
    delete(x);
    x=*first;
    x->changePREV(NULL);
}
void remove_last(Lista** last)
{
    Lista* x=*last;
    *last=x->getPREV();
    delete(x);
    x=*last;
    x->changeNEXT(NULL);
}
Lista* search_in_list(Lista* first, int value)
{
    Lista* x=first;
    while(x->getX()<value)
    {
        x=x->getNEXT();
    }

    return x;
}
