class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int t=arr[n-1];
        if(t-n==0) return t+k;
        
        if(t-n<k) return k+n;
        int i=0,j=n;
        
        while(i<=j)
        {
            int mid=(i+j)/2;
            t=arr[mid];
            int l=t-mid-1;
            if(l<k) i=mid+1;
            else
                j=mid-1;
            
        }
        return k+j+1;
    }
};