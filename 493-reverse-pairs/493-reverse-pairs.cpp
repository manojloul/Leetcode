class Solution {
public:
    int merge(vector<int> &nums,int s,int mid,int e)
    {
        int ans=0;
        int j=mid;
        for(int i=s;i<mid;++i)
        {
            while(j<=e && nums[i]>(long)2*nums[j])
                j++;
            ans+=(j-(mid));
        }
        
        vector<int> v;
        int i=s;
        j=mid;
        
        while(i<mid && j<=e)
        {
            if(nums[i]<nums[j])
                v.push_back(nums[i++]);
            else
                v.push_back(nums[j++]);
        }
        
        while(i<mid)
        {
            v.push_back(nums[i++]);
        }
        
        while(j<=e)
            v.push_back(nums[j++]);
        i=0;
        for(int k=s;k<=e;++k)
            nums[k]=v[i++];
        
        return ans;
    }
    int mergesort(vector<int> & nums,int i,int j)
    {
        int ans=0;
        if(i<j)
        {
            int mid=(i+j)/2;
            ans+=mergesort(nums,i,mid);
            ans+=mergesort(nums,mid+1,j);
            ans+=merge(nums,i,mid+1,j);
        }
        return ans;
    }
    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);
    }
};