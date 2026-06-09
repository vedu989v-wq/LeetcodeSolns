class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int mini = INT_MAX;

        int fsum = 0;
        int p_idx = 0;

        for (int f_idx = 0; f_idx < nums.size(); f_idx++) {

            fsum += nums[f_idx];

            while (fsum >= target) {
                mini = min(mini, f_idx - p_idx + 1);

                fsum -= nums[p_idx];
                p_idx++;
            }
        }

        return (mini == INT_MAX) ? 0 : mini;
    }
};