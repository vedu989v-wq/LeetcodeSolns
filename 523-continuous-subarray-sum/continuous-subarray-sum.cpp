class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int psum=0;
        

        unordered_map<int, int>m;

        m[0]=-1;

        for(int i=0; i<nums.size(); i++){
            psum=psum+nums[i];
            int rem=psum%k;
        
        //checking with the help of one occurence (intial one) is enough to prove that, good subarray exists..., and hence the logic
            if(m.count(rem)){
                if(i-m[rem]>=2)
            return true;
            }
            else
            m[rem]=i;
        }

        return false;

    }
};