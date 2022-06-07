// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    //Function to insert heap.
    double med=0;
    priority_queue<int> s;
    priority_queue<int,vector<int>,greater<int>> g;
    void insertHeap(int &x)
    {
          if(s.size()==0 && g.size()==0)
          {
              med=x;
              s.push(x);
          }
          else if(s.size()>g.size())
          {
              if(x<med)
              {
                  g.push(s.top());
                  s.pop();
                  s.push(x);
              }
              else
              {
                  g.push(x);
              }
              med=(s.top()+g.top())/2.0;
          }
          else if(s.size()==g.size())
          {
              if(x<med)
              {
                  s.push(x);
                  med=s.top();
              }
              else
              {
                  g.push(x);
                  med=g.top();
              }
          }
          else
          {
              if(x<med)
              {
                  s.push(x);
              }
              else
              {
                  s.push(g.top());
                  g.pop();
                  g.push(x);
              }
              med=(s.top()+g.top())/2.0;
          }
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        return med;
    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends