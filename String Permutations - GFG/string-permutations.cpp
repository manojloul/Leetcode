//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    vector<string> ans;
    void solve(string &s, int pos)
    {
        if(pos==s.size())
        {
            ans.push_back(s);
            return;
        }
        
        for(int i=pos;i<s.size();++i)
        {
            swap(s[i],s[pos]);
            solve(s,pos+1);
            swap(s[i],s[pos]);
        }
    }
    vector<string> permutation(string S)
    {
        //Your code here
        solve(S,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends