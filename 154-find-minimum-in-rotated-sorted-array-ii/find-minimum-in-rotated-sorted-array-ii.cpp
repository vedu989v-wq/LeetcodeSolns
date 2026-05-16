class Solution {
public:
    int findMin(vector<int>& nums) {
        //if array contains same elements throughout
        // if(nums[0]==nums[nums.size()-1])
        // return nums[0];

        int ans=nums[0];
        int start=0, end=nums.size()-1;
        
        //left side sorted
        while(start<=end){
        int mid=start+(end-start)/2;

        if(nums[mid]>nums[0]){
            start=mid+1;
        }
        //right side sorted
        else if(nums[mid]<nums[0]){
            ans=nums[mid];
            end=mid-1;
        }
        else{
            //if end element is smaller than nums[0], pivot definitely may exist on the right side
            if(nums[end]<nums[0]){
                start=mid+1;
            }

            else
            end--;
        }

    }
    return ans;
    }
};