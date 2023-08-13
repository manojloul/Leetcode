//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n){
        // code here
        vector<int> v;
        v.push_back(1);
        v.push_back(1);
        for(int i=2;i<n;++i)
        {
            v.push_back((v[i-1]%1000000007+v[i-2]%1000000007)%1000000007);
        }
        return v[n-1]%1000000007;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends