class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //same way as the previous problem of removing duplicates was
        int i=0;
        for(int j=0; j<nums.size(); j++){
            if(nums[j]!=val){
                nums[i]=nums[j];
                i++;
            }
        }
        
        return i;
    }
};