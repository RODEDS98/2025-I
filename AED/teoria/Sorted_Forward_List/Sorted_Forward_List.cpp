include <iostream>
using namespace std;

struct CNode
{
 
    CNode(int v,CNode* next=nullptr){ 
        this->v = v; 
        this->next=next; 
    }
    
    int v;
    CNode* next;
};

class CSortedList
{
public:
    CSortedList();
    ~CSortedList();
    bool find(int x, CNode**& p);
    bool ins(int x);
    bool rem(int x);
    void print();
private:
    CNode* head;
};

CSortedList::CSortedList()
{ head = nullptr; }

CSortedList::~CSortedList()
{
    CNode* t = head;
    for(CNode* t=head;head;head=head->next){
        delete t;
        t= head;
    }
    

}

bool CSortedList::find(int x, CNode**& p)
{
    for ( p = &head; *p && (*p)->v < x; p = &((*p)->next) );
    return *p && (*p)->v == x;
}

bool CSortedList::ins(int x)
{
    CNode** p;
    if ( find(x,p) ) return 0;
    *p = new CNode(x,*p);
    return 1;
}

bool CSortedList::rem(int x)
{
    CNode** p;
    if ( !find(x,p) ) return 0;
    CNode* t = *p;
    *p = (*p)->next;
    delete t;
    return 1;
}

void CSortedList::print()
{
    for( CNode* t = head; t; t = t->next )
        std::cout<<t->v<<" ";
    std::cout<<"\n";
}

int main()
{
    CSortedList l;
    l.ins(11); l.print();
    l.ins(7); l.print();
    l.ins(4); l.print();
    l.ins(13); l.print();
    l.ins(10); l.print();
    l.ins(2); l.print();
    l.ins(17); l.print();
    l.rem(10); l.print();
    l.rem(2); l.print();
    l.rem(17); l.print();
    l.rem(4); l.print();
    l.rem(11); l.print();
    l.rem(13); l.print();
    l.rem(7); l.print();
}

