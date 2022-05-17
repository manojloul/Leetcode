class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=-1;
        int count=0;
        
        for(int i=0;i<nums.size();++i)
        {
            if(count==0)
            {
                count++;
                ans=nums[i];
            }
            else if(ans==nums[i])
                count++;
            else
                count--;
        }
        return ans;
    }
};