//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int rm, int cm) 
    {
        vector<int> ans;
        int l=0,r=cm-1;
        int u=0,d=rm-1;
        int dir=1;
        while(l<=r && u<=d)
        {
            if(dir==1)
            {
                int i = l;
                while(i<=r)
                    ans.push_back(matrix[u][i++]);
                u++;
                dir++;
            }
            else if(dir==2)
            {
                int i=u;
                while(i<=d)
                    ans.push_back(matrix[i++][r]);
                r--;
                dir++;
            }
            else if(dir==3)
            {
                int i=r;
                while(i>=l)
                    ans.push_back(matrix[d][i--]);
                d--;
                dir++;
            }
            else if(dir==4)
            {
                int i=d;
                while(i>=u)
                    ans.push_back(matrix[i--][l]);
                l++;
                dir++;
            }
            else dir%=4;
            
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends