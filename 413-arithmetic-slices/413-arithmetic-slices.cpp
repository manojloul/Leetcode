class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans=0;
        int i=0,j=0;
        
        
        while(j<nums.size()-1)
        {
            if(nums[j+1]-nums[j]==nums[i+1]-nums[i]) j++;
            else
            {
                while(j-i+1>2)
                {
                    ans+=j-i-1;
                    i++;
                }
                i=j;
                j+=1;
            }
        }
        while(j-i+1>2)
        {
            ans+=j-i-1;
           i++;
        }
        return ans;
    }
};