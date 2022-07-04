class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2,vector<int>());
        set<int> a,b;
        
        for(auto it:nums1)
            a.insert(it);
        for(auto it:nums2)
            b.insert(it);
        
        for(auto it:a)
            if(b.find(it)==b.end())
                ans[0].push_back(it);
        
        for(auto it:b)
            if(a.find(it)==a.end())
                ans[1].push_back(it);
        
        return ans;
    }
};