class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool f=true;
        for(int i=0;i<nums.size()-1;++i)
        {
            if(nums[i]>nums[i+1])  f=false;
        }
        if(f) return true;
        f=true;
        for(int i=0;i<nums.size()-1;++i)
        {
            if(nums[i]<nums[i+1]) f=false;
        }
        return f;
    }
};