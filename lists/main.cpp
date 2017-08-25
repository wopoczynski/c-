#include <iostream>

using namespace std;

// Typ elementów listy
struct slistEl
{
  slistEl * next;
  int data;
};

unsigned l_size(slistEl * p);
void l_printl(slistEl * p);
void l_push_front(slistEl * & head, int v);
void l_push_back(slistEl * & head, int v);
void l_insert_before(slistEl * & head, slistEl * e, int v);
void l_insert_after(slistEl * e, int v);
void l_pop_front(slistEl * & head);
void l_pop_back(slistEl * & head);
void l_remove(slistEl * & head, slistEl * e);

int main()
{
  slistEl * L = NULL;
  slistEl * e;
  int i;
  for(i = 0; i <= 8; i++) l_push_back(L,i);
  l_printl(L);
  e = L;
  for(i = 1; i <= 3; i++) e = e->next;
  // Przed elementem e umieszczamy 333
  l_insert_before(L,e,333);
 // Za elementem e umieszczamy 222
  l_insert_after(e,222);
  l_printl(L);
  // Usuwamy element e oraz element pierwszy i ostatni
  l_remove(L,e);
  l_pop_front(L);
  l_pop_back(L);
  l_printl(L);

  return 0;
}


// Funkcja oblicza liczbê elementów listy
unsigned l_size(slistEl * p)
{
  unsigned c = 0; // zerujemy licznik

  while(p)
  {
    c++;
    p = p->next;
  }
  return c;
}
// wyœwietla zawartoœæ elementów listy
void l_printl(slistEl * p)
{
  unsigned i;

  cout << "Number of elements : " << l_size(p) << endl;

  for(i = 1; p; p = p->next)
  cout << "Element #" << i++ << "  data = " << p->data << endl;
  cout << endl;
}
// Procedura do³¹czania na pocz¹tek listy
void l_push_front(slistEl * & head, int v)
{
  slistEl * p;

  p = new slistEl;  // tworzymy nowy element
  p->data = v;      // inicjujemy element
  p->next = head;
  head = p;
}
// Procedura do³¹czania na koniec listy
void l_push_back(slistEl * & head, int v)
{
  slistEl * p, * e;

  e = new slistEl;  // tworzymy nowy element
  e->next = NULL;   // inicjujemy element
  e->data = v;
  p = head;
  if(p)
  {
     while(p->next) p = p->next;
     p->next = e;
  }
  else head = e;
}
// Procedura do³¹czania przed elementem e
void l_insert_before(slistEl * & head, slistEl * e, int v)
{
  slistEl * p = head;

  if(p == e) l_push_front(head,v);
  else
  {
    while(p->next != e) p = p->next;
    p->next = new slistEl;
    p->next->next = e;
    p->next->data = v;
  }
}
// Procedura do³¹czania za elementem e
void l_insert_after(slistEl * e, int v)
{
  slistEl * p = new slistEl;

  p->next = e->next;
  p->data = v;
  e->next = p;
}
// Procedura usuwa pierwszy element
void l_pop_front(slistEl * & head)
{
  slistEl * p = head; // zapamiêtujemy pocz¹tek

  if(p)
  {
    head = p->next;   // nowy pocz¹tek
    delete p;         // usuñ element z pamiêci
  }
}

// Procedura usuwa ostatni element
void l_pop_back(slistEl * & head)
{
  slistEl * p = head; // zapamiêtujemy pocz¹tek

  if(p)
  {
    if(p->next)
    {
      while(p->next->next) p = p->next;
      delete p->next;
      p->next = NULL;
    }
    else
    {
      delete p;
      head = NULL;
    }
  }
}

// Procedura usuwa wybrany element
void l_remove(slistEl * & head, slistEl * e)
{
  slistEl * p;

  if(head == e) l_pop_front(head);
  else
  {
    p = head;
    while(p->next != e) p = p->next;
    p->next = e->next;
    delete e;
  }
}
