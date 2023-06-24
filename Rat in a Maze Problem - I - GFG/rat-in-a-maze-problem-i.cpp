//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> ans;
    bool is_valid(vector<vector<int>> m ,int n,int i,int j)
    {
        if(i<0 || i>=n || j<0 || j>=n) return false;
        return m[i][j] == 1;
    }
    void solve(vector<vector<int>>& m ,int n, int i,int j, string st)
    {
        if( i == n-1 && j == n-1)
        {
            ans.push_back(st);
            return;
        }
        else if( i==n) return;
        
        int row_change[4]={-1,1,0,0};
        int col_change[4]={0,0,-1,1};
        char dir[4] = {'U','D','L','R'};
        
        for(int p=0;p<4;++p)
        {
            if(is_valid(m,n,i+row_change[p],j+col_change[p]))
            {
                st+=dir[p];
                m[i][j]=-1;
                solve(m,n,i+row_change[p],j+col_change[p],st);
                st.pop_back();
                m[i][j]=1;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        if(m[0][0] == 0 || m[n-1][n-1] == 0) return {"-1"};
        solve(m,n,0,0,"");
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends