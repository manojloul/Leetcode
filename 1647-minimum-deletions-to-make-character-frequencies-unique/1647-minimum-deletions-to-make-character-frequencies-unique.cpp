class Solution {
public:
    static bool cmp(pair<char,int> &p1,pair<char,int> &p2)
    {
        return p1.second>p2.second;
    }
    int minDeletions(string s) {
        unordered_map<char,int> mp;
        unordered_map<int,int> m;
        
        for(int i=0;i<s.size();++i)
            mp[s[i]]++;
        
        vector<pair<char,int>> v;
        int count=0;
        for(auto it:mp)
        {
            v.push_back({it.first,it.second});
        }
        
        sort(v.begin(),v.end(),cmp);
        for(auto it:v)
        {
            while(m.find(it.second)!=m.end())
            {
                count++;
                it.second--;
            }
            if(it.second>0)
            m[it.second]++;
        }
        return count;
    }
};