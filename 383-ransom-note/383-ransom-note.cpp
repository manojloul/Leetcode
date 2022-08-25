class Solution {
public:
    bool canConstruct(string p, string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();++i)
        {
            mp[s[i]]++;
        }
        
        for(int j=0;j<p.size();++j)
        {
            if(mp.find(p[j])!=mp.end())
            {
                mp[p[j]]--;
                if(mp[p[j]]==0)
                    mp.erase(p[j]);
            }
            else
                return false;
        }
        return true;
    }
};