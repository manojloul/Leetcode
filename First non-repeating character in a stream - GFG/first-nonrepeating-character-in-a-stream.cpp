//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string s){
		    string ans = "";
		    queue<char> q;
		    unordered_map<char,int> mp;
		    for(int i=0;i<s.size();++i)
		    {
		       mp[s[i]]++;
		        if(q.size()==0)
		        {
		           if(mp[s[i]]<=1)
		           {
		               q.push(s[i]);
		               ans+=s[i];
		           }
		           else ans+='#';
		        }
		        else
		        {
		            while(!q.empty() && mp[q.front()]>1)
		             q.pop();
		            
		            if(!q.empty())
		              {
		                   ans+=q.front();
		                   q.push(s[i]);
		              }
		            else
		              {
		                 ans+='#';
		               }
		            
		        }
		      
		     }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends