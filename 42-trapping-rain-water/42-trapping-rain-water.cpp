class Solution {
public:
    int trap(vector<int>& height) {
        int i=0,j=height.size()-1;
        int lm=height[i];
        int rm=height[j];
        int ans=0;
        while(i<j)
        {
            if(lm<rm)
            {
                if(height[i+1]<lm)
                    ans+=lm-height[i+1];
                else
                   lm=height[i+1];
                i++;
            }
            else
            {
                 if(rm>height[j-1])
                    ans+=rm-height[j-1];
                else
                    rm=height[j-1];
                j--;
            }
        }
        return ans;
    }
};