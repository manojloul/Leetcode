class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        
        int ans=0;
        
        int i=0,j=0;
        int k=0;
        while(j<nums.size())
        {
            if(nums[j]==0)
            {
                if(k%2==0)
                    ans=max(ans,j-i);
                k=0;
                i=j+1;
            }
            else if(nums[j]<0)
            {
                k++;
                if(k%2==0)
                {
                    ans=max(ans,j-i+1);
                }
            }
            else
            {
                if(k%2==0)
                {
                    ans=max(ans,j-i+1);
                }
            }
            j++;
        }
        reverse(nums.begin(),nums.end());
        i=0,j=0,k=0;
         while(j<nums.size())
        {
            if(nums[j]==0)
            {
                if(k%2==0)
                    ans=max(ans,j-i);
                i=j+1;
                k=0;
            }
            else if(nums[j]<0)
            {
                k++;
                if(k%2==0)
                {
                    ans=max(ans,j-i+1);
                }
            }
            else
            {
                if(k%2==0)
                {
                    ans=max(ans,j-i+1);
                }
            }
            j++;
        }
        return ans;
    }
};