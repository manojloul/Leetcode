class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        vector<int> v;
        v.push_back(nums[0]);
        for(int i=1;i<nums.size();++i)
        {
            int k=upper_bound(v.begin(),v.end(),nums[i])-v.begin();
            if(k==v.size())
                v.push_back(nums[i]);
            else
                v[k]=nums[i];
        }
        
        if(nums.size()-v.size() <2) return true;
        return false;
    }
};