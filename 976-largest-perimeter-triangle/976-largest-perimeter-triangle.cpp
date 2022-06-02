class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mx=0;
        for(int i=nums.size()-1;i>1;--i)
        {
            int a=nums[i];
            int b=nums[i-1];
            int c=nums[i-2];
            if(b+c>a) mx=max(mx,a+b+c);
        }
        return mx;
    }
};