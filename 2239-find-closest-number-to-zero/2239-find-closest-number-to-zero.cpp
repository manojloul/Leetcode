class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int n=INT_MIN,p=INT_MAX;
        
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]<0)
                n=max(n,nums[i]);
            else if(nums[i]>0)
                p=min(p,nums[i]);
            else return 0;
        }
        if(n==INT_MIN) return p;
        if(p==INT_MAX) return n;
        
        if(abs(n)==abs(p)) return p;
        else if(abs(n)<abs(p)) return n;
        return p;
    }
};