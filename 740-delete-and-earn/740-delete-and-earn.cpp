class Solution {
public:
    
    int deleteAndEarn(vector<int>& nums) {
        vector<int> v;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();++i)
        {
            mp[nums[i]]++;
        }
       
        int dp[10005];
        dp[0]=0;
        dp[1]=mp[1];
        for(int i=2;i<=10004;++i)
            dp[i]=max(dp[i-1],dp[i-2]+i*mp[i]);
        return dp[10004];
    }
};