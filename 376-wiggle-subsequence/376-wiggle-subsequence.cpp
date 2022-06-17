class Solution {
public:
    int solve(vector<int> &nums,int r)
    {
        vector<int> ans;
        ans.push_back(nums[0]);
        int l=1;
        for(int i=1;i<nums.size();++i)
        {
            if(r%2!=0)
            {
                if(nums[i]>ans[l-1])
                {
                    ans.push_back(nums[i]);
                    r++;
                    l++;
                }
                else
                {
                    ans[l-1]=min(ans[l-1],nums[i]);
                }
            }
            else
            {
                if(nums[i]<ans[l-1])
                {
                    ans.push_back(nums[i]);
                    r++;
                    l++;
                }
                else
                    ans[l-1]=max(ans[l-1],nums[i]);
            }
        }
        return l;
    }
    int wiggleMaxLength(vector<int>& nums) {
        return max(solve(nums,0) ,solve(nums,1));
    }
};