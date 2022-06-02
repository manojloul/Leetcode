class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        int i=0;
        while(i<=r)
        {
            if(nums[i]==0)
            {
                swap(nums[i],nums[l]);
                if(i==l) i++;
                l++;
            }
            
            else if(nums[i]==2)
            {
                swap(nums[i],nums[r]);
                if(i==r) i++;
                r--;
            }
            else
                i++;
        }
    }
};