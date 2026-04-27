class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>ans(nums.size());
        int start=0, end=nums.size()-1;
        int n_idx=nums.size()-1;
        
        while(start<=end){
            if(nums[start]*nums[start]>nums[end]*nums[end]){
                ans[n_idx]=nums[start]*nums[start];
                start++;
                n_idx--;
            }
            else{
                ans[n_idx]=nums[end]*nums[end];
                end--;
                n_idx--;
            }
        }
        return ans;
    }
};