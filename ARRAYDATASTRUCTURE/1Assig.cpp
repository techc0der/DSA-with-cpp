#include<iostream>
#include<vector>

using namespace std;

class abstract{

private:

    int capacity;
    int lastindex=-1;
    int *ptr;

public:

    abstract(int);
    bool ifEmpty();
    bool ifFull();
    void append(int);
    void insert(int,int);
    void edit(int,int);
    int getItem(int);
    ~abstract();
    int find(int);
    abstract(abstract &a);
    void doubleArray();
    void HalfArray();
    void print();
};
abstract::abstract(int size){
    if(size>0){
    capacity=size;
    lastindex=-1;
    ptr = new int(capacity);
    }
    else ptr=NULL;
}
bool abstract::ifEmpty(){
    return lastindex==-1;
}
bool abstract::ifFull(){
    return capacity==lastindex+1;
}
void abstract::append(int data){
    lastindex++;
    if(lastindex>=0&&lastindex<capacity){
    ptr[lastindex]=data;
    }
    else{
    cout<<"\nOverFlow";
    doubleArray();
    }
}
void abstract::insert(int specified_index,int value){
    if(specified_index<0||specified_index>lastindex){
        cout<<"\n---Wrong-index---";
        doubleArray();
        
    }
    else if(specified_index>0&&specified_index<=lastindex)
    {
    for (int i = lastindex; i >=specified_index; i--)
    {
        ptr[i]=ptr[i-1];      
    }
    ptr[specified_index]=value;
    lastindex++;
    }
    }
void abstract::edit(int index,int value){
    if(index<-1||index>=lastindex){
        cout<<"\nInValid Index";
    }
    else ptr[index]=value;
}
int abstract::getItem(int index){          //by using exceptional handling  
    if(index<0||index>lastindex){
        cout<<"InValid Index or empty array";
        throw new exception();
    }
    return  ptr[index];
}
abstract::~abstract(){

    delete []ptr;
}
int abstract::find(int data){
    int i;
    for ( i = 0; i <=lastindex; i++)
    {
        if (ptr[i]==data)
        {
            return i;
        }
    return -1;    
        
    }
    
}
abstract::abstract(abstract &a)   //check this code
{
    capacity=a.capacity;
    lastindex=a.lastindex;
    ptr= new int[capacity];
    for (int i = 0; i <=a.lastindex; i++)
    {
        ptr[i]=a.ptr[i];
    }
}
void abstract::doubleArray(){
    capacity=2*capacity;
    int *temp=new int(capacity);
    temp=ptr;
    delete []ptr;
    int *ptr=new int(capacity);
    ptr=temp;
    delete []temp;
    cout<<"\n---DoubleArray is now Activated-----";
}
void abstract::HalfArray(){
    if(lastindex<capacity/2){
        capacity = capacity/2;
        int *temp = new int(capacity);
        delete []ptr;
        int *ptr = new int(capacity);
        ptr=temp;
        delete []temp;        
        }
}
void abstract::print()
{
    for (int i = 0; i <=lastindex; i++)
    {
        cout<<"\nptr["<<i<<"] "<<ptr[i];
    }
    
}

int main(){
    abstract a1(5);
    int value;
    cout<<"\nEnter append value"<<endl;;
    for (int i = 0; i < 5; i++)
    {
        a1.append(i);
    }
    a1.print();
    cout<<"\n-----------------";
    a1.insert(2,87);
    abstract a2(a1);
    a2.print();
    a2.edit(1,56);
    cout<<"\n-----------------";
    a2.print();

    

}