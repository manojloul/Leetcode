class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int mx=INT_MIN;
        
        while(i<j)
        {
            int k=min(height[i],height[j]);
            mx=max(mx,k*(j-i));
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return mx;
    }
};