class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ans;
        unordered_map<string,int> mp,m;
        
        for(int i=0;i<list1.size();++i)
            mp[list1[i]]=i;
        
        int mn=INT_MAX;
        for(int i=0;i<list2.size();++i)
        {
            if(mp.find(list2[i])!=mp.end())
            {
                m[list2[i]]=i+mp[list2[i]];
                mn=min(mn,i+mp[list2[i]]);
            }
        }
        
        for(auto it:m)
        {
            if(it.second==mn)
                ans.push_back(it.first);
        }
        return ans;        
    }
};