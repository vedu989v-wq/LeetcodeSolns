class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<bool>v(10000, 0);
        int first=0, second=0, maxsum=0, sum=0;

        while(second<nums.size()){
            while(v[nums[second]]){
                v[nums[first]]=0;
                sum=sum-nums[first];
                first++;
                
            }

            v[nums[second]]=1;
            sum=sum+nums[second];
            maxsum=max(maxsum, sum);
            second++;
        }
        return maxsum;
    }
};