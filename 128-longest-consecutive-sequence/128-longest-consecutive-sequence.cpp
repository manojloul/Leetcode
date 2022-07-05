class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return  0;
        int ans=0, count=1;
        sort(nums.begin(),nums.end());
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==nums[i-1]+1){
                count++;
            }
            if(nums[i]>nums[i-1]+1){
                ans = max(ans,count);
                count=1;
            }
        }
        ans = max(ans, count);
        return ans;
    }
};