//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[201][201][2];
    int solve(string s,int i,int j,bool istrue)
    {
        if(i>j) return 0;
        if(i==j)
        {
            if(istrue)
            {
                return s[i]=='T'?1:0;
            }
            else
            {
                return s[i]=='F'?1:0;
            }
        }
        if(dp[i][j][istrue]!=-1) return dp[i][j][istrue];
        
        int ans=0;
        for(int k=i+1;k<j;++k)
        {
            int lt=0;
            if(dp[i][k-1][true]!=-1)
            {
                lt=dp[i][k-1][true];
            }
            else
            {
                lt=solve(s,i,k-1,true);
                dp[i][k-1][true]=lt;
            }
            
            int lf=0;
            if(dp[i][k-1][false]!=-1)
            lf=dp[i][k-1][false];
            else
            {
                lf=solve(s,i,k-1,false);
                dp[i][k-1][false]=lf;
            }
            
            int rt=0;
            if(dp[k+1][j][true]!=-1)
            rt=dp[k+1][j][true];
            else
            {
                rt=solve(s,k+1,j,true);
                dp[k+1][j][true]=rt;
            }
            
            int rf=0;
            if(dp[k+1][j][false]!=-1)
            rf=dp[k+1][j][false];
            else
            {
                rf=solve(s,k+1,j,false);
                dp[k+1][j][false]=rf;
            }
            
            if(s[k]=='^')
            {
                if(istrue)
                {
                    ans+=lt*rf+rt*lf;
                }
                else
                {
                    ans+=lt*rt+lf*rf;
                }
            }
            else if(s[k]=='&')
            {
                if(istrue)
                {
                    ans+=lt*rt;
                }
                else
                {
                    ans+=lt*rf+rt*lf+lf*rf;
                }
            }
            else
            {
                if(istrue)
                {
                    ans+=lt*rt+lf*rt+lt*rf;
                }
                else
                {
                    ans+=lf*rf;
                }
            }
        }
        return dp[i][j][istrue]=ans%1003;
    }
    int countWays(int N, string S){
        memset(dp,-1,sizeof(dp));
        return solve(S,0,S.size()-1,true);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends