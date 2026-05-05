class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int>v;
        unordered_map<int, int>m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }

        for(const auto &p: m){
         if(p.second==2)
         v.push_back(p.first);
        }

        return v;
    }
};