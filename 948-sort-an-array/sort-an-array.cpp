class Solution {
public:
    void merge(vector<int>&nums, int start, int end, int mid){
        vector<int>temp(end-start+1);
        int left=start;
        int right=mid+1;
        int index=0;

        while(left<=mid && right<=end){
            if(nums[left]<=nums[right]){
                temp[index]=nums[left];
                index++, left++;
            }
            else{
                temp[index]=nums[right];
                index++, right++;
            }
        }

        //Left array me element bacha ho to
        while(left<=mid){
            temp[index]=nums[left];
            index++, left++;
        }
        //right array
        while(right<=end){
            temp[index]=nums[right];
            index++, right++;
        }

        index=0;
        while(start<=end){
            nums[start]=temp[index];
            start++, index++;
        }
    }
    void mergeSort(vector<int>&nums, int start, int end){
        //base case: elemented division done
        if(start==end)
        return;

        int mid=start+(end-start)/2;
        //recursion

       //left split
        mergeSort(nums, start, mid);
        //right split
        mergeSort(nums, mid+1, end);

        merge(nums, start, end, mid);
    }
    vector<int> sortArray(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;

        mergeSort(nums, start, end);
        return nums;
    }
};