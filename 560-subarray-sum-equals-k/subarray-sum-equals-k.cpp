class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       int psum=0;
       int ans=0;

       unordered_map<int, int >m;
       m[0]=1;//initial prefix

       for(int i=0; i<nums.size(); i++){
        psum=psum+nums[i];

        if(m.count(psum-k)){ //checking the existence of counter prefix (prefix-k), for getting that prefix-k to prefix (i to j) subarray
             ans+=m[psum-k];
        }

        m[psum]++;
       }

       return ans;


    }
};