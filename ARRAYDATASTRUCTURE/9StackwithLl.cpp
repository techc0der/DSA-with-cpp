#include<iostream>
#include<vector>

using namespace std;

struct element{
    int item;
    element *previos;    
};


class StackwithLl
{
private:
    element *Top;
protected:
    void insertLast(int data){
        element *t,*n;
        n->item=data;
        n->previos=NULL;
        if (Top==NULL)
        {
            n->previos=NULL;
            Top=n;
        }
        else{
            t=Top;
            while (t->previos!=NULL)
            {
                t=t->previos;
            }
            t->previos=n;
            

        }
        
        
    };
public:
    StackwithLl();
    void push(int);
    int peek();
    int pop();
    void ReverseStack();
    bool Isempty();
    StackwithLl& operator=(StackwithLl &);
    ~StackwithLl();
};

StackwithLl::StackwithLl()
{
    Top = NULL;
}

void StackwithLl::push(int data)
{
    if (Top==NULL)
    {
        Top->item=data;
    }
    else
    {
        element *n=new element;
        n->item = data;
        n->previos=Top;
        Top=n;
    }
    
}

int StackwithLl::peek()
{
    if (!(Top==NULL))
    {
        return Top->item;
    }
    
}

int StackwithLl::pop()
{
    element *n=Top;
    Top=Top->previos;
    return (n->item);
}

StackwithLl::~StackwithLl()
{
}

bool StackwithLl::Isempty()
{
    return Top==NULL;
}

void ReverseStack(StackwithLl &s)
{
    StackwithLl Last;
    while (!s.Isempty())
    {
        Last.push(s.pop());
    }
    s=Last;
};

StackwithLl& StackwithLl::operator=(StackwithLl &s)
{
        if (Top!=NULL)
        {
            while (Top)
            {
                pop();
            }
            
        }

        element *t=s.Top;
        while (t->previos!=NULL)
        {
            insertLast(t->item);
            t=t->previos;       
        }
        return *this;

        
}

bool palidrome(int a)
{
    StackwithLl s;
    int x=a,l=0;
    while (x)
    {
        x=x/10;
        l++;
    }
    x=a;
    for (int i = 0; i < l/2; i++)
    {
        s.push(a%10);
        a=a/10;
    }
    if (l%2)//is odd
    {
        a=a/10;
    }
    for (int i = 0; i < l/2; i++)
    {
        if (a%10!=s.pop())
        {
            return false;
        }
            a=a/10;
    }
    return true;
}

void postfix(int a)
{
    
}
int main(){
    StackwithLl l1;
    for (int i = 0; i < 5; i++)
    {
        l1.push(i);
    }

    void ReverseStack(StackwithLl l1);
    for (int i = 0; i < 5; i++)
    {
        cout<<l1.pop()<<endl;;
    }
    
    

}

