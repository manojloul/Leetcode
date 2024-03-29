//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[501][501];
    bool ispal(string &s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int mcm(string &str,int i,int j)
    {
        if(i>=j) return 0;
        if(ispal(str,i,j)) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int mn=INT_MAX;
        for(int k=i;k<j;++k)
        {
            int t=0;
            int left=0,right=0;
            if(dp[i][k]!=-1)
             left = dp[i][k];
            else
            {
                left=mcm(str,i,k);
                dp[i][k]=left;
            }
            if(dp[k+1][j]!=-1)
            {
                right=dp[k+1][j];
            }
            else
            {
                right=mcm(str,k+1,j);
                dp[k+1][j]=right;
            }
            t= 1+left+right;
            mn=min(mn,t);
        }
        return dp[i][j]=mn;
    }
    int palindromicPartition(string str)
    {
        memset(dp,-1,sizeof(dp));
        return mcm(str,0,str.size()-1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends