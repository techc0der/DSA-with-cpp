#include<iostream>
using namespace std;

struct node{
    node *previos;
    int item;
    node *next;
};

class cll{
    private:
    node *last;
    node *start;
    public:

    cll();
    void insertATend(int);
    void insertATbegin(int);
    void insertATspecific(int,int);
    ~cll();
};
cll::cll(){
    last=NULL;
    start= NULL;
}

void cll::insertATend(int data){
    if (start==NULL)
    {
        start= new node;
        start->item=data;
    }
    
    if (last==NULL)
    {
        last = new node;
        last->item=data;
        last->next=start;
        last->previos=start;
        start->next=last;
    }
    else{
        node *n=new node();
        n->item= data;
        last->next=n;
        n->previos=last;
        last->next=n;
        n->next=start;
        last=n;
    }
}

void cll::insertATbegin(int data)
{
    if (start!=NULL)
    {
        node *n =new node;
        start->previos=n;
        n->item = data;
        n->next=start;
        start = n;
    }
}

void cll::insertATspecific(int specific_node,int data)
{
    if ((last || start == NULL))
    {
        insertATend(data);
    }
    else if(specific_node>=1){
        int count= 1;
        node *s = start; 
        while(count!=specific_node)
        {
            count++;
            s=s->next;
        }
        node *n =new node;
        n->next=s;
        n->previos=s->previos;
        n->item=data;
        s->previos->next=n;

    }
    
}



