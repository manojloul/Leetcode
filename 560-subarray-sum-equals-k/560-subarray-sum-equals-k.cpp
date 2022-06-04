class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0;
        int sum=0;
        
        int i=0,j=0;
        unordered_map<int,int> mp;
        
        while(j<nums.size())
        {
            sum+=nums[j];
            if(sum==k) ans++;
            if(mp.find(sum-k)!=mp.end())
                ans+=mp[sum-k];
            mp[sum]++;
            j++;
        }
        return ans;
    }
};