//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    private:
    
    void dfs(int node,vector<bool> &visited,vector<int> &ans,vector<vector<int>>& adj){
        ans.push_back(node);
        for(int it: adj[node]){
            if(visited[it])continue;
            visited[it]=true;
            dfs(it,visited,ans,adj);
        }
    }
    
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        const int source=0, n=adj.size();
        vector<int> ans;
        vector<bool> visited(n,false);

        visited[source]=true;
        
        dfs(source,visited,ans,adj);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V;
        cin >> V;
        cin.ignore();
        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < V; i++) {
            string input;
            getline(cin, input);
            int num;
            vector<int> node;
            stringstream ss(input);
            while (ss >> num) {
                node.push_back(num);
            }
            adj[i] = node;
        }

        Solution obj;
        vector<int> ans = obj.dfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends