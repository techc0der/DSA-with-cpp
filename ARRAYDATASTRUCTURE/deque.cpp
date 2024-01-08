#include<iostream>
#include<vector>

using namespace std;

struct node{
    int item;
    node *next,*previos;
};

class deque
{
private:
    node *front,*rear;
public:
    deque();
    ~deque();
    void insert(int,char);
    void deletefront();
    void deleterear();
};

deque::deque(/* args */)
{
    front=NULL;
    rear=NULL;
}

void deque::insert(int data,char check)
{
    node *n=new node;
    n->item=data;
    if (!front&&!rear)
    {
        front=n;
        rear=n;
    }
    
    else if (check=='F')
    {   
        front->previos=n; 
        n->next=front;
        front=n;
    }

    else if (check=='R')
    {
        rear->next=n;
        n->previos=rear;
        rear=n;
    }
}

void deque::deletefront()
{
    node *n=new node;
    if (!front)
    {
        cout<<"\nit is empty";
    }
    
    else
    {
        if (rear==front)
        {
            rear=NULL;
        }
        
        n=front;
        front->item=NULL;
        front=front->next;
        front->previos=NULL;
        n->next=NULL;

    }
    
}

void deque::deleterear()
{
    node *n=new node;
    if (!rear)
    {
        cout<<"\nit is empty";
    }
    
    else
    {
        if (rear==front)
        {
            front=NULL;
        }
        
        n=rear;
        rear->item=NULL;
        rear=rear->previos;
        n->next=NULL;
        n->previos=NULL;
        rear->next=NULL;

    }
    
}

deque::~deque()
{
}
