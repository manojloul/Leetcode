class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n=arr.size();
        vector<int> sum(n,0);
        sum[0]=arr[0];
        for(int i=1;i<n;++i)
            sum[i]=sum[i-1]+arr[i];
        
        int ans=0;
        
        for(int i=0;i<n;++i)
        {
            if((i+1)%2!=0) ans+=sum[i];
            
            int k=i-3;
            while(k>=0)
            {
                ans+=sum[i]-sum[k];
                k-=2;
            }
           // cout<<ans<<endl;
        }
        ans+=sum[n-1]-sum[0];
        return ans;
    }
};