class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return 1;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();++i)
            mp[nums[i]]++;
        
        int ans=1;
        for(int i=0;i<nums.size();++i)
        {
            if(mp.find(nums[i]-1)!=mp.end())
                continue;
            else
            {
                int c=1;
                int t=nums[i];
                while(mp.find(t+1)!=mp.end())
                {
                    c++;
                    t=t+1;
                }
                ans=max(ans,c);
            }
        }
        return ans;
    }
};