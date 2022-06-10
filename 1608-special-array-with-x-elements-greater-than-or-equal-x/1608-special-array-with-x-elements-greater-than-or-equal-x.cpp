class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=1;i<=n;++i)
        {
            int c=0;
            for(int j=0;j<n;++j)
            {
                if(nums[j]>=i)
                {
                    c+=n-j;
                    break;
                }    
            }
            if(c==i) return c;
        }
        return -1;
    }
};