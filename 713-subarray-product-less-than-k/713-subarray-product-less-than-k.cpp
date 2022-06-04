class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0;
        int i=0,j=0;
        int pro=1;
        while(j<nums.size())
        {
            pro*=nums[j];
            while(pro>=k && i<=j)
                pro/=nums[i++];
            ans+=j-i+1;
            //cout<<ans<<" "<<i<<" "<<j<<endl;
            j++;
        }
        return ans;
    }
};