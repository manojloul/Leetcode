class Solution {
public:
    bool wordPattern(string pat, string s) {
        unordered_map<char,string> mp;
        stringstream ss(s);
        vector<string> v;
        string t;
        while(ss>>t)
            v.push_back(t);
        if(v.size()!=pat.size()) return false;
        for(int i=0;i<pat.size();++i)
        {
            if(mp.find(pat[i])!=mp.end())
            {
                if(mp[pat[i]]!=v[i])
                    return false;
            }
            else
            {
                mp[pat[i]]=v[i];
            }
        }
        map<string,char> m;
        for(int i=0;i<pat.size();++i)
        {
            if(m.find(v[i])!=m.end())
            {
                if(m[v[i]]!=pat[i])
                    return false;
            }
            else
            {
                m[v[i]]=pat[i];
            }
        }
        return true;
    }
};