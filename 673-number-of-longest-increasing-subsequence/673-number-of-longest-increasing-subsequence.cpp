class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
    int mx = 1;
    vector<int>dp(n,1),cnt(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j] && dp[i]<dp[j]+1){
                dp[i] = dp[j]+1;
                cnt[i] = cnt[j];
            }else if(nums[i]>nums[j] && dp[i]==dp[j]+1){
                cnt[i]+=cnt[j];
            }
        }
        if(dp[i]>mx) mx = dp[i];
    }
    int c = 0;
    for(int i=0;i<n;i++){
        if(dp[i]==mx){
            c+=cnt[i];
        }
    }
    return c;
    }
};