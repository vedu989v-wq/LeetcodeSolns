class Solution {
public:
  void rotateMatrix(vector<vector<int>>& mat) {
        int n=mat[0].size();
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                swap(mat[i][j], mat[j][i]);
            }
        }
        for(int i=0; i<n; i++){
            int start=0,  end=n-1;
            while(start<end){
                swap(mat[start][i], mat[end][i]);
                start++, end--;
            }
        }
  }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int k=4;
        while(k--){
        rotateMatrix(mat);
        if(mat==target)
        return true;
        }
        return false;
    }
};