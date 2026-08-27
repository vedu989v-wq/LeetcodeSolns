class Solution {
public:
    int r,c;

    bool valid(int i, int j){
        return i>=0 && i<r && j>=0 &&j<c;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        r=grid.size();
        c=grid[0].size();

        //bfs logic

        queue<pair<int, int>>q;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]==2){
                    q.push(make_pair(i, j));
                }
            }
        }
        int timer=0;

        //core bfs logic
        while(!q.empty()){
            timer++;
            int curr_rots=q.size();
            while(curr_rots--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();

                vector<int>row={-1,1,0,0};
                vector<int>col={0,0,-1,1};

                for(int k=0; k<4; k++){
                    if(valid(i+row[k], j+col[k]) && grid[i+row[k]][j+col[k]]==1){
                        grid[i+row[k]][j+col[k]]=2;
                        q.push(make_pair(i+row[k], j+col[k]));
                    }
                }
            }
        }
        
        int cnt_zeroes=0;

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]==1)
                return -1;
                else if(grid[i][j]==0)
                cnt_zeroes++;
            }
        }
        if(cnt_zeroes==r*c)
        return 0;

        return timer-1;
    }
};