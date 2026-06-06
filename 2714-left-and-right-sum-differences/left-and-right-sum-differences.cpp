class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int>ans(nums.size(), 0);

        //right and left sum from index i=0;
        int rsum=0;
        int lsum=0;

        for(int i=1; i<nums.size(); i++){
            rsum=rsum+nums[i];
        }

        for(int i=0; i<nums.size()-1; i++){
            int curr=abs(lsum-rsum);
            ans[i]=curr;
            lsum=lsum+nums[i];
            rsum=rsum-nums[i+1];

        }

        ans[nums.size()-1]=abs(lsum-rsum);
        
        return ans;
        
    }
};