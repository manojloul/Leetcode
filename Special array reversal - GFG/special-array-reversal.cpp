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
        int i=0,j=str.size()-1;
        while(i<j)
        {
            if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z'))
            {
               if((str[j]>='a' && str[j]<='z') || (str[j]>='A' && str[j]<='Z'))
               {
                   swap(str[i],str[j]);
                   i++;
                   j--;
               }
               else
               {
                   j--;
               }
            }
            else i++;
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