class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        if(nums[0]>x && nums[n-1]>x) return -1;
        if(nums[0]==x ||nums[n-1]==x) return 1;
        
        int mn=INT_MAX;
        
        int i=0,j=n-1;
        int sum=0;
        while(sum<x && i<n) sum+=nums[i++];
        
        if(sum==x) mn=min(mn,i);
        while(i<=j && i>0)
        {
            if(sum>=x)
                sum-=nums[--i];
            else
                sum+=nums[j--];
            //cout<<sum<<" "<<i<<" "<<j<<endl;
            if(sum==x) mn=min(mn,i+n-j-1);
        }
        
        while(j>=i && sum<x) sum+=nums[j--];
        if(sum==x) mn=min(mn,i+n-j-1);
        if(mn==INT_MAX) return -1;
        return mn;
    }
};