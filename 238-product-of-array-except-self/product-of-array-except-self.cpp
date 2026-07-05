/*
Don't compute "total product - current element".

Instead, think locally:

answer[i] =
(product of everything on the left)
×
(product of everything on the right)

Two passes are enough:
1. Prefix products.
2. Suffix products.

This automatically skips nums[i] without using division.
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans(nums.size(), 1);

        int left=1; //products of the left OR left pass
        for(int i=0; i<nums.size(); i++){
            ans[i]=left;
            left*=nums[i];
        }
        
        int right=1; //products of the right OR right pass
        for(int i=nums.size()-1; i>=0; i--){
            ans[i]*=right;
            right*=nums[i];
        }

        return ans;
    }
};