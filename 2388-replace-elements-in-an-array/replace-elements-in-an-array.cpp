class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        //hashing phase, link number and index together
        unordered_map<int, int >m;
        for(int i=0; i<nums.size(); i++){
         m[nums[i]]=i;
        }

        for(int i=0; i<operations.size(); i++){
            if(m.find(operations[i][0]) != m.end()){
                nums[m[operations[i][0]]]=operations[i][1];
                m[operations[i][1]]=m[operations[i][0]];
                m.erase(operations[i][0]);
            }
        }
        return nums;
    }
};