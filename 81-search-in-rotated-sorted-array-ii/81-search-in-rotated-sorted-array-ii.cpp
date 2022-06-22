class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int i=0,j=nums.size()-1;
        
        while(i<=j)
        {
            while(i<j && nums[i]==nums[j])
                i++;
            
            int mid=(i+j)/2;
            
            if(nums[mid]==target)
                return true;
            
            if(nums[mid]<=nums[j])
            {
                if(target>=nums[mid] && target<=nums[j])
                    i=mid+1;
                else
                    j=mid-1;
            }
            else
            {
                if(target>=nums[i] && target<=nums[mid])
                    j=mid-1;
                else
                    i=mid+1;
            }
        }
        
        return false;
    }
};