//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
   public:
   vector<int> ans;
   set<int> vis;
    void solve(vector<int> adj[],int curr)
    {
        ans.push_back(curr);
        vis.insert(curr);
          
        for(int i=0;i<adj[curr].size();++i)
        {
            if(vis.find(adj[curr][i])==vis.end())
            solve(adj,adj[curr][i]);
        }
        
    }
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        // Code here
        solve(adj,0);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends