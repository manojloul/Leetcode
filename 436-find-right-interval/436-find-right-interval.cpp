class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& in) {
        
        vector<int> ans;
        vector<int> v;
        unordered_map<int,int> mp;
        for(int i=0;i<in.size();++i)
        {
            v.push_back(in[i][0]);
            mp[in[i][0]]=i;
        }
        sort(v.begin(),v.end());
        for(int i=0;i<in.size();++i)
        {
            int k=lower_bound(v.begin(),v.end(),in[i][1])-v.begin();
            if(k>=0 && k<v.size())
                ans.push_back(mp[v[k]]);
            else
                ans.push_back(-1);
        }
        return ans;
    }
};