class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1,j=0;
        while(i<nums.size())
        {
            if(nums[i]!=nums[j])
            {
                swap(nums[j+1],nums[i]);
                j++;
            }
            i++;
        }
        return j+1;
    }
};