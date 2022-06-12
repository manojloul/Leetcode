class Solution {
public:
    int findMin(vector<int>& nums) {
        int mn=INT_MAX;
        int n=nums.size();
        int i=0,j=nums.size()-1;
        
        while(i<=j)
        {
            while(i<j && nums[i]==nums[i+1]) i++;
            while(j>i && nums[j]==nums[j-1]) j--;
            
            int mid=i+(j-i)/2;
            
            int r=(n+mid+1)%n;
            int l=(n+mid-1)%n;
            
            if(nums[mid]<=nums[r] && nums[mid]<=nums[l])
                mn=min(nums[mid],mn);
           
            if(nums[j]>=nums[mid])
            {
                j=mid-1;
            }
            else
            {
                i=mid+1;
            }
                
            
        }
        return mn;
    }
};