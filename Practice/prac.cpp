struct ListNode{
    int val;
    ListNode *next;
    
};
class Solution {
public:

    Solution(){
        
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode *l;
        ListNode *temp1=l1,*temp2=l2;
        while(temp1!=NULL && temp2!=NULL){
            l->val=temp1->val+temp2->val;
            if(temp1->val+temp2->val>=10){
                int i;
                i=temp1->val+temp2->val-10;
                temp1->next->val+=1
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return l;
    }
};