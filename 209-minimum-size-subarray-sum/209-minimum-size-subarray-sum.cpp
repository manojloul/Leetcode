class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int mn=INT_MAX;
        int i=0,j=0;
        int sum=0;
        
        while(j<nums.size())
        {
            sum+=nums[j];
            while(sum>=target)
            {
                mn=min(mn,j-i+1);
                sum-=nums[i++];
            }
            j++;
        }
        if(mn==INT_MAX)
            return 0;
        return mn;
    }
};