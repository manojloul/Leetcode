class Solution {
public:
    bool solve(vector<int> arr,int l,int r)
    {
        vector<int> v;
        for(int i=l;i<=r;++i)
            v.push_back(arr[i]);
        sort(v.begin(),v.end());
        if(v.size()==1 || v.size()==2) return true;
        int d=v[1]-v[0];
        for(int i=2;i<v.size();++i)
            if(v[i]-v[i-1]!=d) return false;
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        
        for(int i=0;i<l.size();++i)
        {
            ans.push_back(solve(nums,l[i],r[i]));
        }
        return ans;
    }
};