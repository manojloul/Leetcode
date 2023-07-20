//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseWords (string s)
    {
        int i=0,j=0;
        string ans;
        while(j<s.size())
        {
            if(s[j]=='.')
            {
                string tm= s.substr(i,j-i);
                reverse(tm.begin(),tm.end());
                ans+=tm+'.';
                i=j+1;
            }
             j++;
        }
        if(i<j)
        {
            string tm= s.substr(i,j-i);
            reverse(tm.begin(),tm.end());
            ans+=tm;
        }
        else ans.pop_back();
        
        if(s[s.size()-1]=='.') ans.push_back('.');
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends