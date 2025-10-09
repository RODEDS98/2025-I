#include <iostream>

struct Node
{
    Node(int x){ v = x; next = 0; }
    int v;
    Node* next;
};

class CForwardList
{
public:
    CForwardList();
    ~CForwardList();
    void push_back(int x);
    void push_front(int x);
    void pop_back();
    void pop_front();
    int operator[](int i);
    void print();
private:
    Node* head;
    int nelem;
};

CForwardList::CForwardList()
{
    head = 0;
    nelem = 0;
}

CForwardList::~CForwardList()
{
    //
}


void CForwardList::push_back(int x)
{
    Node* n = new Node(x);
    Node** q;
    for ( q = &head; *q != 0; q = &( (*q)->next ) );
    *q = n;
}

/*void CForwardList::push_back(int x)
{
    Node* n = new Node(x);
    Node** q = &head;
    while ( *q != 0 )
        q = &( (*q)->next );
    *q = n;
}*/

/*void CForwardList::push_back(int x)
{
    Node* n = new Node(x);
    if ( head == 0 )
    {    head = n;  }
    else
    {
        Node* p = head;
        while( p )
        {
            if ( p->next == 0 )
                p->next = n;
        }
    }
}*/


void CForwardList::push_front(int x)
{
    Node* n = new Node(x);
    n->next = head;
    head = n;
    nelem++;
}

void CForwardList::pop_back()
{
}

void CForwardList::pop_front()
{
}

int CForwardList::operator[](int i)
{
    return 0;
}

void CForwardList::print()
{
}

int main()
{
    CForwardList fl;
    fl.push_back(8);
    fl.push_back(6);
    fl.push_back(3);
    fl.push_back(7);
    fl.print();
    //fl[2] = 1;
    fl.print();
}
