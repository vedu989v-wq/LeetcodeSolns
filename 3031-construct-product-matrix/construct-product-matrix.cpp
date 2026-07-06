class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& nums) {

        //initialising 2d vector array answer 
         vector<vector<int>>ans(nums.size(), vector<int>(nums[0].size(), 1));

        long long left=1; //products of the left OR left pass

        for(int i=0; i<nums.size()*nums[0].size(); i++){

            int row=i/nums[0].size();
            int col=i%nums[0].size();

            ans[row][col]=left;
            left=(left*nums[row][col])%12345;
        }
        
        long long right=1; //products of the right OR right pass
        for(int i=nums.size()*nums[0].size()-1; i>=0; i--){

            int row=i/nums[0].size();
            int col=i%nums[0].size();

            ans[row][col]=(ans[row][col]*right)%12345;
            right=(right*nums[row][col])%12345;
        }

        return ans;
    }
};