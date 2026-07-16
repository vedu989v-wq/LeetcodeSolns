class Solution {
public:
    bool detectCycle(int node, int dest, vector<vector<int>>&adj, vector<bool>&visited){
        if(node==dest){
          return true;
        }

        visited[node]=true;

        for(int i=0; i<adj[node].size(); i++){
            if(!visited[adj[node][i]]){

                if(detectCycle(adj[node][i], dest, adj, visited))
                return true;

            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
       int n=edges.size();
       vector<vector<int>>adj(n+1);

       for(int i=0; i<edges.size(); i++){
        int u, v;
        v=edges[i][1];
        u=edges[i][0];

        vector<bool>visited(n+1, 0);
        //if u can reach v, adding this edges form a cycle
        if(detectCycle(u, v, adj, visited))
        return edges[i];

        //Otherwise add the edge
        adj[u].push_back(v);
        adj[v].push_back(u);
       }
     return {};
    }
};