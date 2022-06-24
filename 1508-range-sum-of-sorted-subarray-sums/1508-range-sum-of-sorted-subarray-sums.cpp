class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int l, int r) {
        vector<int> v;
        int sum=0;
        for(int i=0;i<n;++i)
        {
            sum+=nums[i];
            int t=sum;
            v.push_back(t);
            for(int j=0;j<i;++j)
            {
                t-=nums[j];
                v.push_back(t);
            }
        }
        sort(v.begin(),v.end());
        
        int mod=1e9+7;
        long int ans=0;
        for(int i=l-1;i<r;++i)
        {
            ans+=v[i];
        }
        
        return ans%mod;
    }
};