class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>>ans;
        
for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
        vector<int> v;
        v.push_back(i);
        v.push_back(j);
        v.push_back(abs(i-rCenter) + abs(j-cCenter));
        ans.push_back(v);
    }
}
        for (const auto& row : ans) {       // Outer loop for rows
        for (int element : row) {          // Inner loop for elements
            cout << element << " ";
        }
        cout << endl;
    }
    int columnToIndex=2;
    sort(ans.begin(), ans.end(), [columnToIndex](const vector<int>& v1, const vector<int>& v2) {
        return v1[columnToIndex] < v2[columnToIndex];
    });
    for(int i=0; i<ans.size(); i++){
        ans[i].pop_back();
    }
    return ans;
    }
};