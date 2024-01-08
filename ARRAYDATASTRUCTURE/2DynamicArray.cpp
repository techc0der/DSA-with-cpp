#include<iostream>
using namespace std;
class DynamicArray
{
private:
    int capacity;
    int lastindex;
    int *ptr;
public:
    void DoubleArray();
    DynamicArray(int);
    ~DynamicArray();
    void IsFull();
    void Insert(int,int);
    void Append(int);
    DynamicArray(DynamicArray &);
    void print();
};
void DynamicArray::IsFull()
{
    if (lastindex==capacity-1)
    {
        cout<<"\n<----Full---->";
    }
    
}
void DynamicArray::DoubleArray()
{
    capacity=capacity*2;
    int *temp=new int(capacity);
    for (int i = 0; i < lastindex; i++)
    {
        temp[i]=ptr[i];
    }
    delete []ptr;
    int *ptr=new int (capacity);
    for (int i = 0; i < lastindex; i++)
    {
        ptr[i]=temp[i];
    }
    delete []temp;
    cout<<"\n<----Double-Array-Created---->";
    
    
}
DynamicArray::DynamicArray(int index)
{
    ptr=new int(index);
    capacity=index;
    lastindex=-1;
}

void DynamicArray::Append(int Data)
{
    ++lastindex;
    ptr[lastindex]=Data;   
}

void DynamicArray::Insert(int index,int data)
{if (index>-1&&index<=lastindex)
{
    
    for (int i = lastindex; i > index; i--)
    {
        ptr[i]=ptr[i-1];
    }
    ptr[index]=data;
}

}

DynamicArray::DynamicArray(DynamicArray& D)
{
    capacity=D.capacity;
    lastindex=D.lastindex;
    ptr= new int(capacity);
    for (int i = 0; i <=lastindex; i++)
    {
        ptr[i]=D.ptr[i];
    }
}

void DynamicArray::print()
{
    for (int i = 0; i <=lastindex; i++)
    {
        cout<<"\nptr["<<i<<"] "<<ptr[i];
    }
    
}

DynamicArray::~DynamicArray()
{

}

int main(){
    DynamicArray D1(5);
    for (int i = 0; i < 5; i++)
    {
        D1.Append(i);
    }
    D1.print();
    DynamicArray D2(D1);
    cout<<"\n---------------";
    D2.print();
    D2.Insert(2,7);
    cout<<"\n---------------";
    D2.print();
    D2.DoubleArray();
    D2.Append(5);
    D2.print();
}
