class Solution {
    bool dfs(int start,int parent,vector<vector<int>>& adj, vector<bool>& visited){
        visited[start]=true;
        for(int neighbor: adj[start]){
            if(!visited[neighbor]){
                if(dfs(neighbor,start,adj,visited))return true;
            }
            else if(neighbor!=parent)return true;
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool> visited(V);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i,-1,adj,visited))return true;
            }
        }
        return false;
    }
};