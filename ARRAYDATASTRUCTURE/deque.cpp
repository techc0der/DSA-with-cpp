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

deque::deque()
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
        n->previos=NULL;
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
    if (!front)
    {
        cout<<"\nit is empty";
    }
    
    else
    {
        if (rear==front)
        {
            delete front;
            front=rear=NULL;
        }
        else{
        node *n=new node;
        n=front;
        front=front->next;
        front->previos=NULL;
        delete n;
        }

    }
    
}

void deque::deleterear()
{
    if (!rear)
    {
        cout<<"\nit is empty";
    }
    
    else
    {
        if (rear==front)
        {
            delete rear;
            front=NULL;
            rear=NULL;
        }
        else{
            node *n=new node;
            n=rear;
            rear=rear->previos;
            rear->next=NULL;
            delete n;
        }

    }
    
}

deque::~deque()
{
}
