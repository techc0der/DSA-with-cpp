#include<iostream>
#include<vector>

using namespace std;
class rough
{
private:
    int *ptr;
    int capacity;
    int lastindex;
public:
    rough(){

    };
    void insert(){

    }
    void arraydeclare(int index){
        int *ptr=new int(index);
    }
    void append(int data){
        lastindex++;
        if (lastindex==capacity-1)
        {
        ptr[lastindex]=data;
            /* code */
        }
    }

    
};

rough::rough(/* args */)
{
}

rough::~rough()
{
}

int main(){
    rough r1;
    int a;
    cin>>a;
    r1.arraydeclare(a);

    
  
return 0;
}