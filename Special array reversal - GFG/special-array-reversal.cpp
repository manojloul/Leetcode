//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    string reverse(string str)
    { 
        //code here.
        string s;
        for(int i=0;i<str.size();++i)
        {
            if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z'))
             s+=str[i];
        }
        int sp=0,e=s.size()-1;
        while(sp<e)
        {
            swap(s[sp],s[e]);
            sp++;
            e--;
        }
        int j=0;
        for(int i=0;i<str.size();++i)
        {
            if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z'))
             str[i]=s[j++];
        } 
        return str;
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout <<ob.reverse(s) << endl;
    }
return 0;
}


// } Driver Code Ends