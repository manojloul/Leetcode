class Solution {
public:
    static bool cmp(pair<int,string> &p1,pair<int,string> &p2)
    {
        if(p1.first==p2.first)
        {
            return p1.second<p2.second;
        }
        return p1.first>p2.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(int i=0;i<words.size();++i)
        {
            mp[words[i]]++;
        }
        vector<pair<int,string>> p;
        vector<string> ans;
        for(auto it:mp)
        {
            p.push_back({it.second,it.first});
        }
        sort(p.begin(),p.end(),cmp);
        
        for(int i=0;i<k;++i)
            ans.push_back(p[i].second);
        
        return ans;
    }
};