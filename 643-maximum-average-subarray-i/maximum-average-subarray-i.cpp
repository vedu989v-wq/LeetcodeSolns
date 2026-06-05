class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxi=-1e9;
        double sumi=0;
        for(int i=0; i<k; i++){
            sumi=sumi+nums[i];
        }
        maxi=sumi;
        for(int i=0; i<nums.size()-k; i++){
            sumi=sumi-nums[i]+nums[i+k];
            maxi=max(maxi, sumi);
        }

        return maxi/k;
    }
};