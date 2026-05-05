class Solution {
public:

    
    vector<long long> distance(vector<int>& nums) {
        //unordered_map creation, to store indexes and solve the problem in one go
        unordered_map<int, vector<int>>m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]].push_back(i);
        }
    vector<long long>ans(nums.size());
        //left pass & right pass
    
    for(const auto &p: m){
        const auto& v=p.second;
        long long total=0;
        for(int i=0; i<v.size(); i++)
        total=total+v[i];

        long long prefixsum=0;
        for(int i=0; i<v.size(); i++){
            ans[v[i]]= total - 2*prefixsum + v[i]*(2*i - v.size()); //i * group[i] - prefixTotal (vector (jiske andar same index hai), uske left part ka sum) + (total - prefixTotal - group[i])  - (group.size() - i - 1) * group[i] (vector k right part ka sum)
            prefixsum=prefixsum+v[i];
        }

    }
        return ans;
    }
};