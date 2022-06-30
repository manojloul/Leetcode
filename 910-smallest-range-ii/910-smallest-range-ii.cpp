class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        if(nums.size()==1) return 0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=nums[n-1]-nums[0];
        
        for(int i=0;i<n-1;++i)
        {
            int a=nums[i],b=nums[i+1];
            
            int l=min(nums[0]+k,b-k);
            int r=max(nums[n-1]-k,a+k);
            
            ans=min(ans,r-l);
        }
        return ans;
        
    }
};