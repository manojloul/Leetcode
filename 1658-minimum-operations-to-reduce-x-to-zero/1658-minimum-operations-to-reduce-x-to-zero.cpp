class Solution {
public:
   
    int minOperations(vector<int>& nums, int x) {
        int mx=0;
        long int sum=0;
        for(int i=0;i<nums.size();++i)
            sum+=nums[i];
        sum-=x;
        if(sum==0) return nums.size();
        long int k=0;
        int i=0,j=0;
        while(j<nums.size())
        {
            k+=nums[j];
            
            while(i<j && k>sum)
            {
                k-=nums[i];
                i++;
            }
            if(sum==k)
                mx=max(mx,j-i+1);
            
            j++;
        }
        
        if(mx==0) return -1;
        return nums.size()-mx;
        
    }
};