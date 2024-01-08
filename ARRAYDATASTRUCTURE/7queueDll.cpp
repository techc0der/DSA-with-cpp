#include<iostream>
#include<vector>

using namespace std;

struct queue
{
    int item;
    queue *next;
};

class queues
{
private:
    queue *front;
    queue *rear;
public:
    queues();
    void insert(int);
    bool isempty();
    void deletefront();
    int count();
    ~queues();
};

queues::queues()
{
    front=NULL;
    rear=NULL;
}

bool queues::isempty()
{
    return (front==NULL&&rear==NULL);
}

void queues::insert(int data)
{
    queue *n=new queue;
    n->item=data;
    if (isempty)
    { 
        front=n;
        rear=n; 
    }
    else
    {
        rear->next=n;
        rear=n;
    }
}

void queues::deletefront()
{
    if (isempty)
    {
        cout<<"\nis empty";
    }

    if (rear==front)
    {
        front->item=NULL;
        front->next=NULL;
        front=NULL;
        rear=NULL;
    }
    
    else
    {
    queue *n=new queue;
    n=front;
    front=front->next;
    delete n;
    }
}

int queues::count()
{
    int count=0;
    if (isempty)
    {
        return count;
    }
    else
    {
        queue *n=front;
        count++;
        while (!(n==rear))
        {
            count++;
            n=n->next;
        }
    }
    
    return count;
}

queues::~queues()
{
    while (rear&&front)
    {
        if (rear==front)
        {
            front->item=NULL;
            front->next=NULL;
            front=NULL;
            rear=NULL;
        }
    else{
        queue *n=new queue;
        n=front;
        front=front->next;
        n->item=NULL;
        n->next=NULL;
        delete n;
    }   
    }
    
}
