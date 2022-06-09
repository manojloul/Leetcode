// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        // code here 
        string ans="";
        string temp="";
        int k=0;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='.')
            {
                if(k!=0)
                {
                    temp+='.';
                    ans=temp+ans;
                }
                else
                ans=temp+ans;
                
                k++;
                temp="";
            }
            else
            temp+=s[i];
        }
        if(k!=0)
        temp+='.';
        ans=temp+ans;
        return ans;
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends