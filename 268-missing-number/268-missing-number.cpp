class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        
        long sum=0;
        for(int i=0;i<nums.size();++i)
            sum+=nums[i];
        long s=n*(n+1)/2;
        return s-sum;
    }
};