class Solution {
public:
unordered_map<long long, vector<int>>m;
    Solution(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            m[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
     
     vector<int> i=m[target];

     random_device rd; 
     mt19937 gen(rd()); 
     uniform_int_distribution<size_t> distr(0, i.size() - 1); 
     size_t randomIndex = distr(gen);

     return i[randomIndex];


    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */