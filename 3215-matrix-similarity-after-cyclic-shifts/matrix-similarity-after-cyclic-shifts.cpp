class Solution {
public:
      vector<int> rightrotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;               // handle large k
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
        return nums;
    }
      vector<int> leftrotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;               // handle large k
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + (nums.size()-k));
        reverse(nums.begin() + (nums.size()-k), nums.end());
        return nums;
    }
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>>mat1=mat;
        for(int i=0; i<mat.size(); i++){
            if(i%2==0)
            leftrotate(mat[i], k);
            else if(i%2==1)
            rightrotate(mat[i], k);

        }
        return mat==mat1;
    }
};