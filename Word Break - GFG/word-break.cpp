//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    unordered_map<string,bool>mp;
    bool solve(string s,string tmp,int pos)
    {
        if(pos==s.size())
        {
            if(tmp=="" || mp.find(tmp)!=mp.end()) return true;
            return false;
        }
        
        for(int i=pos;i<s.size();++i)
        {
            tmp+=s[i];
            if(mp.find(tmp)!=mp.end())
            {
                return solve(s,"",i+1) || solve(s,tmp,i+1);
            }
            else
             return solve(s,tmp,i+1);
        }
    }
    int wordBreak(string A, vector<string> &B) {
        for(int i=0;i<B.size();++i)
         mp[B[i]]=true;
        return solve(A,"",0);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends