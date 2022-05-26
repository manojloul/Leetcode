class Solution {
public:
    int trap(vector<int>& arr) {
        
        int ans=0,curr=0;
        int i=0,j=arr.size()-1;
        int lm=arr[0],rm=arr[j];
        
        while(i<j)
        {
            if(lm<rm)
            {
                if(arr[i+1]<lm)
                    curr=lm-arr[i+1];
                else
                    lm=arr[i+1];
                i++;
            }
            else
            {
                if(arr[j-1]<rm)
                    curr=rm-arr[j-1];
                else
                    rm=arr[j-1];
                j--;
            }
            ans+=curr;
            curr=0;
        }
        return ans;
    }
};