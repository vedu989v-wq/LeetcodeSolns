class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        //marking & pushing phase
        for(int i=0; i<nums.size(); i++){
            int x=abs(nums[i]);
            if(nums[x-1]>0){
                nums[x-1]=-1*nums[x-1];
            }
            else if(nums[x-1]<0)
            ans.push_back(x);

        }
        return ans;
        
    }
};