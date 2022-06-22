class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> mp,m;
        
        for(int i=0;i<p.size();++i)
            mp[p[i]]++;
        
        m=mp;
        int count=mp.size();
        int i=0,j=0;
        vector<int> ans;
        while(j<s.size())
        {
            if(mp.find(s[j])!=mp.end())
            {
                mp[s[j]]--;
                if(mp[s[j]]==0) count--;
                
                while(j-i+1>p.size())
                {
                    mp[s[i]]++;
                    if(mp[s[i]]==1) count++;
                    i++;
                }
                if(count==0)
                    ans.push_back(i);
            }
            else
            {
                i=j+1;
                mp=m;
                count=mp.size();
            }
            j++;
        }
        return ans;
    }
};