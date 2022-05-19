// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:vector<int> ans;
void solve(vector<int> &arr,int n,int pos,int sum)
{
    if(pos==n)
    {
        ans.push_back(sum);
        return;
    }
    solve(arr,n,pos+1,sum);
    solve(arr,n,pos+1,sum+arr[pos]);
}
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        solve(arr,N,0,0);
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
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends