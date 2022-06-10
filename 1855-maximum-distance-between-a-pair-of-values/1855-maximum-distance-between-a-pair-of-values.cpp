class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int mx=0;
        int i=0,j=0;
        
        while(i<nums1.size() && j<nums2.size() && i<=j )
        {
            if(nums2[j]>=nums1[i])
                mx=max(mx,j-i);
            else i++;
            j++;
        }
        return mx;
    }
};