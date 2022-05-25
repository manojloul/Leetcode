class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int i=0,j=nums.size()-2;
        
        while(i<=j)
        {
            int mid=(i+j)/2;
            int pos=mid^1;
            
            if(nums[mid]==nums[pos])
            {
                i=mid+1;
            }
            else
            {
                j=mid-1;
            }
            //cout<<i<<" "<<j<<endl;
        }
        return nums[i];
    }
};