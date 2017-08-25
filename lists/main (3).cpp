#include <iostream>
#include <cstdlib>

using namespace std;

struct slistEl
{
    slistEl * next;
    int data;
};

class slist
{
    public:
      slistEl * head;

      slist();  // konstruktor
      ~slist(); // destruktor
      void printl();
      void push_front(int v);
      void pop_front();
      slistEl * find_first(int v);
};
// Konstruktor listy
slist::slist()
{
  head = NULL;
}
// Destruktor listy
slist::~slist()
{
  while(head) pop_front();
}
// funkcja wyœwietla zawartoœæ elementów listy
void slist::printl()
{
	for(slistEl * p = head; p; p = p->next)
	cout << p->data << " ";
    cout << endl;
}
// funkcja do³¹czania na pocz¹tek listy
void slist::push_front(int v)
{
    slistEl * p;
    p = new slistEl;
    p->next = head;
    p->data = v;
    head = p;
}
// funkcja usuwa pierwszy element
void slist::pop_front()
{
    slistEl * p = head; // zapamiêtujemy pocz¹tek

    if(p)
    {
        head = p->next;   // nowy pocz¹tek
        delete p;         // usuñ element z pamiêci
    }
}
// Wyszukuje pierwszy element listy o danej zawartoœci
slistEl * slist::find_first(int v)
{
    slistEl * p = head;
    while(p && p->data != v)
		p = p->next;
    return p;
}


int main()
{
    slist L;
    slistEl * p;
    int i;

	//tworze sobie liste
     for(i = 0; i < 9; i++)
     L.push_front(65+i);
     L.printl();
    do
        {//znajduje element
        p = L.find_first(70);
        if(p)
        {
        p->data = 0;//podmieniam element
        L.printl();
        }
    } while(p);
        for (i=0;i<3;i++)
			L.pop_front();//usuwam z przodu
    L.printl();
    return 0;
 }
