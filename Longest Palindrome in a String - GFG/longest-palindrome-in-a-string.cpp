//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  string ispal(string s,int i,int j)
  {
      while(i>=0 && j<s.size())
      {
          if(s[i]==s[j])
          {
              i--;
              j++;
          }
          else break;
      }
      i++;
      j--;
      return s.substr(i,j-i+1);
  }
    string longestPalin (string s) {
        string ans;
        for(int i=0;i<s.size();++i)
        {
            string s1= ispal(s,i,i);
            string s2= ispal(s,i,i+1);
            
            if(s2.size()>s1.size()) s1=s2;
            if(ans.size()<s1.size()) ans = s1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends