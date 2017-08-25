#include <iostream>

using namespace std;

struct slistEl
{
    slistEl * next;
    int data;
};
int main()
{
    slistEl * L;
    slistEl * e, * p;
    int n;
    int v;
    L = new slistEl;
    L->next = new slistEl;
    L->next->next = NULL;
    L->next->data = 2147483647; // wartosc ostatniego elementu listy ktorego nie mozemy przekroczyc
    cout<< "dlugosc listy: ";
    cin >> n;
    //dodanie elementow do listy o dlugosci n wraz z sortowaniem przy wstawianiu
    for(int i = 0; i < n; i++)
    {
        cout<<"podaj element: ";
        cin >> v;
        for(p = L; v > p->next->data; p = p->next);
            e = new slistEl;
            e->data = v;
            e->next = p->next;
            p->next = e;
     }
    for(p = L->next; p->next; p = p->next)
        cout << p->data << " ";
        cout << endl;
    while(L)
    {
        e = L;
        L = L->next;
        delete e;
    }
    return 0;
}
