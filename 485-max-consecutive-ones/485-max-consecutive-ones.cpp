class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int mx=0;
        int len=0;
        
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]==1)
            {
                len++;
            }
            else
            {
                mx=max(mx,len);
                len=0;
            }
        }
        mx=max(mx,len);
        return mx;
    }
};