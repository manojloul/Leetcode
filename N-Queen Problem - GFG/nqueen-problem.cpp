//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isvalid(int row,int col,int n,vector<vector<int>> &mat)
    {
        int i=row,j=col-1;
        while(j>0)
        {
            if(mat[i][j]==1)
            return false;
            j--;
        }
        
        j=col;
        i=row-1;
        while(i>0)
        {
            if(mat[i][j]==1)
            return false;
            i--;
        }
        
        i=row-1;
        j=col-1;
        while(i>0 && j>0)
        {
            if(mat[i][j]==1)
            return false;
            i--;
            j--;
        }
        
        i=row+1;
        j=col-1;
        
        while(i<=n && j>0)
        {
            if(mat[i][j]==1)
            return false;
            
            i++;
            j--;
        }
        
        return true;
    }
    void solve(int n,int col,vector<vector<int>> &v,vector<int> &curr_path,vector<vector<int>> &mat)
    {
        if(col==n+1)
        {
            v.push_back(curr_path);
            return;
        }
        
        for(int row=1;row<=n;++row)
        {
                if(isvalid(row,col,n,mat))
                {
                    mat[row][col]=1;
                    curr_path.push_back(row);
                    solve(n,col+1,v,curr_path,mat);
                    
                    mat[row][col]=0;
                    curr_path.pop_back();
                }
        }
        
    }
    vector<vector<int>> nQueen(int n) {
        if(n==1)
        return {{1}};
        vector<vector<int>> mat;
        for(int i=0;i<=n;++i)
        {
            vector<int> v;
            for(int j=0;j<=n;++j)
            {
                v.push_back(0);
            }
            mat.push_back(v);
        }
        vector<vector<int>> v;
        vector<int> curr_path;
        solve(n,1,v,curr_path,mat);
        return v;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends