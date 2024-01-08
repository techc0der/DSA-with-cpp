#include<iostream>
#include<vector>

using namespace std;

class stackwitharray
{
private:
    int capacity;
    int top;
    int *ptr;
public:
    stackwitharray(int);
    ~stackwitharray();
    void push(int);
    int peek();
    int pop();
    bool isfull();
    bool isempty();
    int getsize();
    stackwitharray& operator=(stackwitharray &);

};

stackwitharray::stackwitharray(int element)
{
    top =-1;
    capacity=element;
    ptr = new int(element);
}

void stackwitharray::push(int data)
{
    if (isfull())
    {
        cout<<"\nthe capacity is full";
    }
    else{
    top++;
    ptr[top]=data;
    }
    
}

bool stackwitharray::isfull()
{
    return (capacity == top + 1);
}

bool stackwitharray::isempty()
{
    return (top == -1);
}

int stackwitharray::peek()
{
    try
    {
        if (top==-1)
        {
            throw -1;
        }
        return ptr[top];
        
    }
    catch(int e)
    {
        cout<<"\nEmpty Stack";
    }
    
}

int stackwitharray::pop()
{
     try
    {
        if (top==-1)
        {
            throw -1;
        }
        top--;
        return ptr[top];
        
    }
    catch(int e)
    {
        cout<<"\nEmpty Stack";
    }  
}

int stackwitharray::getsize()
{
    return top+1;
}
 
void reverse(stackwitharray &s)
{
    stackwitharray *temp = new stackwitharray(s.getsize());
    while(!s.isempty())
    {
        temp->push(s.pop());
    }
    s=*temp;
}

stackwitharray& stackwitharray::operator=(stackwitharray &s)
{
    capacity =s.capacity;
    top=s.top;
    if (ptr!=NULL)
    {
        delete []ptr;
    }
    ptr=new int(capacity);
    for (int i = 0; i <=top; i++)
    {
        ptr[i]=s.ptr[i];
    }
}
stackwitharray::~stackwitharray()
{
    delete []ptr;
}
