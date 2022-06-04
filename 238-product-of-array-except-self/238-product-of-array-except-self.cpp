class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long pro=1;
        int z=0;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]!=0)
            {
               pro=pro*nums[i];
            }
            else
                z++;
        }
        vector<int> ans;
        if(z>1) pro=0;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]==0)
                ans.push_back(pro);
            else
            {
                if(z) ans.push_back(0);
                else
                    ans.push_back(pro/nums[i]);
            }
        }
        return ans;
    }
};