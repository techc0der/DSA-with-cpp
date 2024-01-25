#include<iostream>
#include<vector>

using namespace std;

struct node
{
    int pno;
    int item;
    node *next;
};

class priority
{
private:
    node *start;   
public:
    priority(/* args */);
    void insert(int,int);
    bool empty();
    void delte();
    ~priority();
};

priority::priority(/* args */)
{
    start = NULL;
}

bool priority::empty()
{
    return start == NULL;
}

void priority::insert(int data,int pno)
{
    node *n=new node;
    n->item=data;
    n->next=NULL;
    n->pno=pno;
    if(empty())
    {
        start=n;
        
    }
    else
    {
        
        if (start->next==NULL)
        {
            if(n->pno>start->pno) start->next=n;
            else
            {
                n->next=start;
                start=n;
            }
        }
        else
        {
            node *t1=start;
            node *t2;
            while (n->pno>t1->pno)
            {
                t2=t1;
                t1=t1->next;
            }
            if (t1==NULL)
            {
                t2->next=n;
            }
            else
            {
                n->next=t1;
                t2->next=n;
            }
        }
    }
}

void priority::delte()
{
    if (empty())
    {
        cout<<"it is empty";
    }
    else
    {
        
        if (start->next==NULL)
        {
            delete start;
        }
        else
        {
            delete start;
            start=start->next;    
        }
            
    }
}

priority::~priority()
{
}

