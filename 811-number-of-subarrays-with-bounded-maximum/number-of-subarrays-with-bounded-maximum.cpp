class Solution {
public:
    int countinbound(vector<int>& nums, int bound){
        int start=0;
        int count=0;

        for(int end=0; end<nums.size(); end++){
            if(nums[end]>bound)
            start=end+1;

            count+=end-start+1;
        }
        return count;
    }
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
      return countinbound(nums, right)-countinbound(nums, left-1);
    }
};