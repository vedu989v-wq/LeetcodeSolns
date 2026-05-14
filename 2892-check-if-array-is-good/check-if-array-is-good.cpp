class Solution {
public:
    bool isGood(vector<int>& nums) {
        int maxi=INT_MIN;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>maxi){
                maxi=nums[i];
            }
        }
        unordered_map<int, int>m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        if(maxi+1!=nums.size())
        return false;

        if(m[maxi]>2)
        return false;
        
        for (const auto& pair : m) {
        if(pair.first!=maxi && m[pair.first]!=1)
        return false;
    
        
    }
      return true;  
    }
};