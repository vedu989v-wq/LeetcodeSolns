class Solution {
public:
    int r,c;
    bool valid(int i, int j){
        return i>=0 && i<r && j>=0 && j<c;
    }

    int numIslands(vector<vector<char>>& grid) {
        r=grid.size();
        c=grid[0].size();

        vector<int>row={-1,1,0,0};
        vector<int>col={0,0,-1,1};

        queue<pair<int, int>>q;
        int count=0;

        //checking the character 1 in the grid
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]=='1'){
                count++;

                //make all 1 convert to zero
                q.push(make_pair(i, j));
                grid[i][j]='0';

                while(!q.empty()){
                    int new_i=q.front().first;
                    int new_j=q.front().second;
                    q.pop();
                

                //4 directional check
                for(int k=0; k<4; k++){
                    if(valid(new_i+row[k], new_j+col[k]) && grid[new_i+row[k]][new_j+col[k]]=='1'){
                        grid[new_i+row[k]][new_j+col[k]]='0';
                        q.push(make_pair(new_i+row[k], new_j+col[k]));
                    }
                }

              }
            } 
          }
        }

        return count;
    }
};