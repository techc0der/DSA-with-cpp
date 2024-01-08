#include<iostream>
using namespace std;

class Stack{
    
    private:
    int Capacity;
    int top=-1;
    int *ptr;

    public:

    Stack(int);
    void push(int);
    int peek();
    void pop();
    void overflow();
    void underflow();
    void Reverse();
    ~Stack();
};

Stack::Stack(int index)
{
    Capacity=index;
    ptr = new int(index);
}

void Stack::push(int data)
{   
    top++;
    ptr[top]=data;
}

int Stack::peek()
{
    return ptr[top];
}

void Stack::pop()
{
    ptr[top]=NULL;
    top--;
}

Stack::~Stack()
{
    delete []ptr;
}

void Stack::overflow()
{
    if (Capacity-1<=top)
    {
        cout<<"\nOverFlow";
    }    
}

void Stack::underflow()
{
    if (Capacity>top)
    {
        cout<<"\nUnderFLow";
    }
}

void Stack::Reverse()
{
    for (int i = 0; i < (top+1)/2; i++)
    {
        ptr[i]=ptr[top];
        top--;
    }
    
}



