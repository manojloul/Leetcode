class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> mp;
        int i=0,j=0;
        int mx=0;
        int ans=0;
        while(j<nums.size())
        {
            mp[nums[j]]++;
            ans+=nums[j];
            while(j-i+1>mp.size())
            {
                ans-=nums[i];
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
            if(mp.size()==j-i+1)
                mx=max(mx,ans);
            j++;
        }
        return mx;
    }
};