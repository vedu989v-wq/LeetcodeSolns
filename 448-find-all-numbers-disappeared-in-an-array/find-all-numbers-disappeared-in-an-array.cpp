class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //Marking phase (Making elements of nums negative)
       for(int i=0; i<nums.size(); i++){
        int x=abs(nums[i]);
        if(nums[x-1]>0){
           nums[x-1]=-1*nums[x-1];
        }
       }

       //finding the index, whose elements are left to become negative
       vector<int>ans;
       for(int i=0; i<nums.size(); i++){
         if(nums[i]>0)
         ans.push_back(i+1);
       }
        return ans;

    }
};