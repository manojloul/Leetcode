class Solution {
public:
    int findMin(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        int n=nums.size();
        while(i<=j)
        {
            int mid=i+(j-i)/2;
            int l=(n+mid-1)%n;
            int r=(n+mid+1)%n;
            if(nums[l]>=nums[mid] && nums[r]>=nums[mid])
                return nums[mid];
            else
            {
                if(nums[mid]>nums[j])
                    i=mid+1;
                else
                    j=mid-1;
            }
        }
        return 0;
    }
};