#include<iostream>
#include<vector>

using namespace std;

struct dll
{
    dll *previous;
    int item;
    dll *next;
};

class dll
{
private:
public:
    dll();
    ~dll();
};

dll::dll(/* args */)
{
}

dll::~dll()
{
}
