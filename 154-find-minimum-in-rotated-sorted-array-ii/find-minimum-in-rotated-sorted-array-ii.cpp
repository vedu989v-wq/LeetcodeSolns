//key area where the solution to 153 problem may not work here 

//eg: [10, 1, 10, 10, 10] 
//error: we may find the min element at right, not on left, but condition says something else
//for this we will seperate the conditon of equality in the searching code
//in case of duplicacy, we will check if nums[0]>nums[end], which will indicate the min element would be on right, else we will decrease the size of end...


class Solution {
public:
    int findMin(vector<int>& nums) {
        

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