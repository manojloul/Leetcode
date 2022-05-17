class Solution {
public:
    int minStartValue(vector<int>& nums) {
     
        int mn=INT_MAX;
        int sum=0;
        for(int i=0;i<nums.size();++i)
        {
            sum+=nums[i];
            mn=min(mn,sum);
        }
        if(mn>=0)
            return 1;
        return abs(mn)+1;
    }
};