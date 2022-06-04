class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<int,int> mp;
        for(int i=0;i<p.size();++i)
            mp[p[i]]++;
        int count=mp.size();
        
        int i=0,j=0;
        vector<int> ans;
        while(j<s.size())
        {
            if(mp.find(s[j])!=mp.end())
            {
                mp[s[j]]--;
                if(mp[s[j]]==0)
                    count--;
                
                while(j-i+1>p.size())
                {
                    if(mp[s[i]]==0) count++;
                    mp[s[i]]++;
                    i++;
                }
                
                if(count==0 && j-i+1==p.size())
                    ans.push_back(i);
            }
            else
            {
                while(i<j)
                {
                    mp[s[i++]]++;
                }
                count=mp.size();
                i++;
            }
            j++;
        }
        return ans;
    }
};