//this statement/expression
// prefix[i][j] =
//                     matrix[i - 1][j - 1]
//                     + prefix[i - 1][j]
//                     + prefix[i][j - 1]
//                     - prefix[i - 1][j - 1];
// is heart of the problem, it helps us achieve O(1) time complexity in calculation


class NumMatrix {
public:
    vector<vector<int>>obj;
    NumMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        obj.resize(m+1, vector<int>(n+1, 0));

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                obj[i][j]=matrix[i-1][j-1]+obj[i-1][j]+obj[i][j-1]-obj[i-1][j-1];
            }
        }
     

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return obj[row2+1][col2+1]-obj[row1][col2+1]-obj[row2+1][col1]+obj[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */