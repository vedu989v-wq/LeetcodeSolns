class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //step 1: find pivot
        int pivot=nums.size()-1;
        for(int i=nums.size()-1; i>=1; i-- ){
            if(nums[i-1]<nums[i]){
                pivot=i-1;
                break;
            }
        }
        //step 2: Swap the rightmost number, which is just larger than the element present on pivot

        if(pivot==nums.size()-1){
            reverse(nums.begin(), nums.end());
        }
        
        else{
        int j=nums.size()-1;

        while(nums[j]<=nums[pivot]){
            j--;
        }

        swap(nums[pivot], nums[j]);

        //Step3: Reversing Digits after pivot
        int start=pivot+1;
        int end=nums.size()-1;

        while(start<=end){
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
        }
        
    }
};