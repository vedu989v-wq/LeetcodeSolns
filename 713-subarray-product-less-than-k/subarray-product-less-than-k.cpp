class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        if(k<=1)
        return 0;
        
        long long pd=1;
        int p_idx=0;
        int f_idx=0;
        int count=0;
        while(f_idx<nums.size()){
            pd=pd*nums[f_idx];

            while(pd>=k){//keep on shrinking the window
             pd=pd/nums[p_idx];
             p_idx++;
            }
            
            count+=f_idx-p_idx+1;
            f_idx++;
        }
        
        return count;
    }
};