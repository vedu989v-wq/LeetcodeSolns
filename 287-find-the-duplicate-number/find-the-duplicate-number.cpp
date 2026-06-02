class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int prev=0, curr=1;
        
        while(curr<nums.size()){
          if(nums[curr]==nums[prev])
          return nums[curr];

          curr++;
          prev++;
        }

        return 0;
    }
};