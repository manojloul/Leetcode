class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int i=0,j=nums.size()-1;
        if(nums[0]==nums[1]) i=1;
        else return nums[0];
        if(nums[j]==nums[j-1]) j--;
        else return nums[j];
        while(i<j)
        {
            int mid=(i+j)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];
            if(mid%2==0)
            {
                if(nums[mid]==nums[mid+1]) i=mid+1;
                else j=mid-1;
            }
            else
            {
                if(nums[mid]==nums[mid-1]) i=mid+1;
                else j=mid-1;
            }
        }
        return nums[i];
    }
};