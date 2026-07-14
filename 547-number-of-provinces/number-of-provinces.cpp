class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        //rough-trough approach : BFS traversal

        int n=isConnected.size();
        
       int provinces=0;
        vector<bool>visited(isConnected.size(), 0);
        //Iterating through Every City
        for(int i=0; i<n; i++){
            //if the city has not been visited yet, we found a new province
            if(!visited[i]){
                provinces++;

                //Start BFS to mark all the cities connected to city 'i'
                queue<int>q;
                q.push(i);
                visited[i]=1;

                while(!q.empty()){
                    int curr=q.front();
                    q.pop();

                    //Scan the row for the current city
                    for(int neighbour=0; neighbour<n; neighbour++){
                        if(isConnected[curr][neighbour]==1 && !visited[neighbour]){
                            visited[neighbour]=1;
                            q.push(neighbour);
                        }
                    }
                }
            }
        }

        return provinces;

    }
};