// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	    vector<string> ans;
	    void solve(string &s,string res,int ind)
	    {
	        if(ind == s.size())
	        {
	            if(res!="")
	            ans.push_back(res);
	            return;
	        }
	        res.push_back(s[ind]);
	        solve(s,res,ind+1);
	        res.pop_back();
	        solve(s,res,ind+1);
	    }
		vector<string> AllPossibleStrings(string s){
		    solve(s,"",0);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends