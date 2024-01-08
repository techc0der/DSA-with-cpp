


//Priority queue using "Single linked list"

#include<iostream>
#include<vector>

using namespace std;

struct node{
    int item;
    node *next;
};

class queue{
    
private:
    node *highfront,*highrear;
    node *lowfront,*lowrear;

public:
    queue();
    
    

};

queue::queue()
{
    highfront=NULL;
    highrear=NULL;
    lowfront=NULL;
    lowrear=NULL;
}


