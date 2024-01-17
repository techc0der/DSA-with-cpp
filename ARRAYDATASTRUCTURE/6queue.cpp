#include<iostream>
#include<vector>

using namespace std;

class queue
{
private:
    int capacity;
    int front=-1;
    int rear=-1;
    int *ptr;
public:
    queue(int);//initializing dynamic array
    bool isfull();
    bool isempty();
    void insert(int);
    void deletefront();
    int count();
    ~queue();
};

queue::queue(int cap)
{
    capacity=cap;
    ptr=new int[cap];
}

void queue::insert(int data)
{
    if (isfull()||rear+1==front)
    {
        cout<<"\nit is overflow";
    }
    else if (isempty())
    {
        front++;
        rear++;
        ptr[rear]=data;
    }
    else if (rear>-1)
    {
        rear++;
        ptr[rear]=data;
    }
    else if (rear==capacity-1&&front>0)
    {
        rear=0;
        ptr[rear]=data;
    }
}

void queue::deletefront()
{
    if (isempty())
    {
        cout<<"\nit is underflow";
    }
    else if (front==rear)
    {
        ptr[front]=NULL;
        front=-1;
        rear=-1;
    }
    

    else if (front==capacity-1)
    {
        front=-1;
        rear=-1;
    }
    else{
        ptr[front]=NULL;
        front++;
    }
}

int queue::count()
{
    if (isempty)
    {
        return 0;
    }
    else if (front>rear)
    {
        return (rear+1)+(capacity-front);
    }
    else if (front<=rear)
    {
        return rear-front+1;
    }
}

queue::~queue()
{
    delete []ptr;
}

  