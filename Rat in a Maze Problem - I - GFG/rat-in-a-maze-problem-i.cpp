// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:vector<string> ans;
    bool isvalid(vector<vector<int>> &mat,int i,int j)
    {
        int n=mat.size();
        if(i<0 || i>=n || j<0 || j>=n) return false;
        if(mat[i][j]==0)
        return false;
        return true;
    }
    void solve(vector<vector<int>> &rat,int n,int i,int  j,string &s)
    {
        if(i==n-1 && j==n-1)
        {
            //cout<<s<<endl;
            ans.push_back(s);
            return;
        }
        
        if(isvalid(rat,i,j-1))
        {
            rat[i][j]=0;
            s.push_back('L');
            solve(rat,n,i,j-1,s);
            s.pop_back();
            rat[i][j]=1;
        }
       // cout<<isvalid(rat,i+1,j)<<endl;
         if(isvalid(rat,i,j+1))
        {
            rat[i][j]=0;
            s.push_back('R');
            solve(rat,n,i,j+1,s);
            s.pop_back();
            rat[i][j]=1;
        }
         if(isvalid(rat,i+1,j))
        {
            rat[i][j]=0;
            s.push_back('D');
            solve(rat,n,i+1,j,s);
            s.pop_back();
            rat[i][j]=1;
        }
         if(isvalid(rat,i-1,j))
        {
            rat[i][j]=0;
            s.push_back('U');
            solve(rat,n,i-1,j,s);
            s.pop_back();
            rat[i][j]=1;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> p;
        if(m[0][0]==0 || m[n-1][n-1]==0) return p;
        string s;
        solve(m,n,0,0,s);
        if(ans.size()==0) return p;
        return ans;
    }
};

    


// { Driver Code Starts.

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
}  // } Driver Code Ends