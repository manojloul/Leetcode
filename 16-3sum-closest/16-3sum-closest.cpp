class Solution {
public:
    int threeSumClosest(vector<int>& arr, int s) {
        sort(arr.begin(),arr.end());
    int mn=INT_MAX,ans=0;
    for(int i=0;i<arr.size();++i)
    {
        int l=i+1,r=arr.size()-1;
        
        while(l<r)
        {
            int sum=arr[i]+arr[l]+arr[r];
            int d=abs(s-sum);
            if(d<mn)
            {
                mn=d;
                ans=sum;
            }
            
            if(sum>s) r--;
            else
            l++;
        }
    }
    
        return ans;
    }
};