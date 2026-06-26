class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<bool>v(nums.size()+1, 0);
        for(int i=0; i<nums.size(); i++){
            v[nums[i]]=1;
        }
        for(int i=0; i<v.size(); i++){
            if(v[i]==0){
                return i;
            }
        }
        return 0;
    }
};