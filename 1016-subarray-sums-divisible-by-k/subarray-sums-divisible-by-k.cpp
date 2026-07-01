class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int psum=0;
        int ans=0;

        unordered_map<int, int>m;
        m[0]=1;

        for(int i=0; i<nums.size(); i++){
            psum=psum+nums[i];
            
            int rem=psum%k;
            if(rem<0){
              rem=rem+k;
            }
            if(m.count(rem))
            ans+=m[rem];

            m[rem]++;
        }

        return ans;
    }
};