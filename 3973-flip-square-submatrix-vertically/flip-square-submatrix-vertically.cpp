class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int j=y; j<k+y; j++){
            int start=x, end=x+k-1;
            while(start<end){
                swap(grid[start][j], grid[end][j]);
                start++;
                end--;
            }

        }
        return grid;
    }
};