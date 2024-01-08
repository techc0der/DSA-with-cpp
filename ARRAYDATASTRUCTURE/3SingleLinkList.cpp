#include<iostream>
using namespace std;

struct node
{
    int item;
    node *next;
    int link;
};
class linked
{
    private:
    node *start;
    public:

    linked();
    void InsertAtstart(int);
    void InsertatEnd(int);
    void count();
    int Find(int);
    int insert(int,int);
    void deleteFirstNode();
    void DeleteLastNode();
    void DeleteAnyNode(int);
    ~linked();
};

linked::linked(){
    start = NULL;
}

void linked::InsertAtstart(int data){
    node *n;
    n = new node;
    n->item=data;
    n->next=start;
    start=n;
}

void linked::InsertatEnd(int data){
    node *n;
    n = new node;
    n->item = data;
    if (start == NULL)
    {
        start = n;
    }
    else{
    node *s=start;
        while (s->next!=NULL)
        {
            s=s->next;
        }
        s->next=n;
    }
}

int linked::Find(int data)
{   
    node *f=start;
    int count=0;
    while(f->item!=data)
    {
        count++;
        f=f->next;
    }
    cout<<"\nNode is finded and node is "<<++count;
}

int linked::insert(int specific_node,int data)
{   
    int count=1;
    node *n,*s=start,*t;
    n = new node;
    n->item=data;
    while (count!=specific_node-1)
    {
        s=s->next;
        count++;
    }
    t=s->next;
    n->next=t;
    s=n;
}

void linked::deleteFirstNode()
{
    node *n = start;
    start = n->next;
    delete []n;    
}

void linked::DeleteLastNode()

{
    node *n=start;
    while (n->next!=NULL)
    {
        n=n->next;
    }
    delete []n;
}

void linked::DeleteAnyNode(int specific_node)
{
    int count=1;
    node *t,*n=start;
    while (specific_node!=count)
    {
        t=n;
        n=n->next;
        count++;
    }
    t->next=n->next;
    delete []n;
}

linked::~linked()
{
    node *t,*n=start;
    while (n->next!=NULL)
    {
        t=n;
        n=n->next;
        t->next=NULL;
    }
}