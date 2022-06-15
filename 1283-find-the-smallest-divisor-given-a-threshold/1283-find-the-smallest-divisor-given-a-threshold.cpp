class Solution {
public:
    int check(vector<int> &nums,int k)
    {
        int ans=0;
        
        for(int i=0;i<nums.size();++i)
            ans+=(nums[i]+k-1)/k;
        
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans=threshold;
        int i=1,j=0;
        sort(nums.begin(),nums.end());
        j=nums[nums.size()-1];
        
        
        while(i<=j)
        {
            int mid=i+(j-i)/2;
            
            int t=check(nums,mid);
            if(t<=threshold)
            {
                ans=mid;
                j=mid-1;
            }
            else
                i=mid+1;
        }
        return ans;
    }
};