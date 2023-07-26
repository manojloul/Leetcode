//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> computelps(string pat)
	{
	    int l = pat.size();
	    vector<int> lps(l,0);
	    int len =0;
	    int i=1;
	    while(i<l)
	    {
	        if(pat[i]==pat[len])
	        {
	            lps[i]=len+1;
	            len++;
	            i++;
	        }
	        else
	        {
	            if(len!=0) len = lps[len-1];
	            else{
	                lps[i]=0;
	                i++;
	            }
	        }
	    }
	    return lps;
	}
	int search(string text, string pat)
	{
	    vector<int> lps=computelps(pat);
	    int l1=text.size();
	    int l2=pat.size();
	    int i=0,j=0;
	    while(i<l1)
	    {
	        if(text[i]==pat[j])
	        {
	            i++;
	            j++;
	        }
	        if(j==l2) 
	        {
	            return 1;
	            j=lps[j-1];
	        }
	        else if(i<l1 && pat[j]!=text[i])
	        {
	            if(j!=0)
	            {
	                j=lps[j-1];
	            }
	            else i++;
	        }
	    }
	    return 0;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string x, y;
   		cin >> x >> y;



        Solution ob;
   		cout << ob.search(x, y) << "\n";
   	}

    return 0;
}
// } Driver Code Ends