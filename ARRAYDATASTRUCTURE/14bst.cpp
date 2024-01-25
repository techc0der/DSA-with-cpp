#include<iostream>
#include<vector>

using namespace std;

struct node{
    node *left;
    int item;
    node *right;
};

class bst
{
private:
    node *root;
public:
    bst();
    void insert(int);
    bool empty();
    void traversing();
    void del(int);
    ~bst();
};

bst::bst()
{
    root = NULL;
}

void bst::insert(int data)
{
    node *n=new node;
    n->item=data;
    n->left=n->right=NULL;
    if(empty()){
        root=n;
    }
    else{
        node *ptr=root;
        while(ptr){
            if(data<ptr->item)
            {
                if (ptr->left==NULL)
                {
                    ptr->left=n;
                    ptr=NULL;
                }
                else ptr=ptr->left;
            }
            else
            {
                if (ptr->right==NULL)
                {
                    ptr->right=n;
                    ptr=NULL;
                }
                else ptr=ptr->right;
            }
        }
    }
}

void bst::traversing()
{
    int choose;
    cout<<"\nchoose type traversing\n1.in_order\n2.pre_order\n3.post_order";
    cin>>choose;
    switch (choose)
    {
    case 1:
    in_order(root);
        break;
    case 2:
    pre_order(root);
        break;
    case 3:
    post_order(root);
        break;
    
    default:
        break;
    }
}

bool bst::empty(){
    return root==NULL;
}

void bst::del(int data)
{
    if(empty()){
        cout<<"\ntree is empty";
    }
    else
    {
        node *ptr=root;
        node *temp = new node;
        while(temp){
            if(ptr->item==data){
                if(ptr->left==NULL && ptr->right==NULL)
                {
                    if(temp->left==ptr)temp->left=NULL;
                    else temp->right=NULL;
                    delete ptr;
                    temp=NULL;

                }
                else if(ptr->left==NULL || ptr->right==NULL)
                {
                    if (root==ptr)
                    {
                        if (ptr->left==NULL)
                        {
                            root->right=ptr->right;
                        }
                        else
                        {
                            root->left=ptr->left;
                        }
                        
                        
                    }
                    else
                    {
                        if(ptr->left==NULL)
                        {
                            if(temp->left==ptr)temp->left=ptr->right;
                            else temp->right=ptr->right;
                        }
                        else
                        {
                            if(temp->left==ptr)temp->left=ptr->left;
                            else temp->right=ptr->left; 
                        }
                    }
                    delete ptr;
                    temp = NULL;
                }
                else 
                {
                    node *post=ptr->left;
                    while(post->left!=NULL&&post->right!=NULL)
                    {
                        post=post->right;
                    }
                    ptr->item=post->item;
                    delete post;
                    temp=ptr=NULL;

                }
            }
            else
            {
                if(data<ptr->item)
                {
                    temp=ptr;
                    ptr=ptr->left;
                }
                else{
                    temp=ptr;
                    ptr=ptr->right;
                }
            }
        }
    }    
}


bst::~bst()
{
    delet(root);
}

void delet(node *ptr)
{
    if(ptr->left==NULL && ptr->right==NULL)
    {
        delete ptr;
    }
    else{
        if(ptr->left!=NULL)delet(ptr->left);
        if(ptr->right!=NULL)delet(ptr->right);
    }
}
 
void in_order(node *ptr)
{
    if(ptr->left==NULL && ptr->right==NULL)cout<<"\n"<<ptr->item;//for inorder          left/root/right
    else
    {
        if(ptr->left!=NULL)in_order(ptr->left);
        cout<<"\n"<<ptr->item;//for root print
        if(ptr->right!=NULL)in_order(ptr->right);
    }
}

void pre_order(node *ptr)
{
    if(ptr->left==NULL && ptr->right==NULL)cout<<"\n"<<ptr->item;//for preorder          root/left/right
    else
    {
        cout<<"\n"<<ptr->item;//for root print
        if(ptr->left!=NULL)pre_order(ptr->left);
        if(ptr->right!=NULL)pre_order(ptr->right);
    }
}

void post_order(node *ptr)
{
    if(ptr->left==NULL && ptr->right==NULL)cout<<"\n"<<ptr->item;//for postorder          left/right/root
    else
    {
        if(ptr->left!=NULL)post_order(ptr->left);
        if(ptr->right!=NULL)post_order(ptr->right);
        cout<<"\n"<<ptr->item;//for root print
    }

}

