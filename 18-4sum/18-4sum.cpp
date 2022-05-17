class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums,int tar) {
        set<vector<int>> ans;
        vector<vector<int>> v;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();++i)
        {
            int t=tar-nums[i];
            int s=i+1;
            int e=nums.size()-1;
            
            while(s<e)
            {
                if(nums[s]+nums[e]==t)
                {
                    ans.insert({nums[i],nums[s],nums[e]});
                    s++;
                    e--;
                }
                else if(nums[s]+nums[e]<t)
                {
                    s++;
                }
                else
                    e--;
            }
        }
        for(auto it:ans)
            v.push_back(it);
        return v;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();++i)
        {
            int t=target-nums[i];
            vector<int> v;
            copy(nums.begin()+i+1,nums.end(),back_inserter(v));
            vector<vector<int>> temp=threeSum(v,t);
            
            for(auto it:temp)
            {
                it.push_back(nums[i]);
                ans.insert(it);
            }
        }
        vector<vector<int>> sol;
        for(auto it:ans)
            sol.push_back(it);
        return sol;
    }
};