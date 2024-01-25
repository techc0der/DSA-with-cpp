struct ListNode{
    int val;
    ListNode *next;
    
};
class Solution {
public:

    int searchInsert(vector<int>& nums, int target) {
        int start=0,last=1;

        for(int i=0;i<=nums.size()-1;i++){
            if(i==nums.size()-1){
                return target-nums[start]+start;
            }
            else if(nums[start]==target){
                return start;
            }
            else if(nums[last]==target){
                return last;
            }
            else         if(nums[start]<target<nums[last]){
                return start+1;
            }
            else{
                start++;
                last++;
            }
            

        }

     return -1;   
    }
};
