class Solution {
public:unordered_map<char,int> mp;
    bool f=true;
    void solve(string s1,string s2)
    {
        int i=0,j=0;
        while(i<s1.size() && j<s2.size())
        {
            if(mp[s1[i]]<mp[s2[j]])
            {
                f=true;
                return;
            }
            if(mp[s1[i]]>mp[s2[j]]) 
            {
                f=false;
                return;
            }
            else
            {
                i++;
                j++;
            }   
        }
        if(s2.size()<s1.size())
            f=false;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        
        for(int i=0;i<order.size();++i)
            mp[order[i]]=i;
        
        for(int i=0;i<words.size()-1;++i)
        {
            solve(words[i],words[i+1]);
            if(f==false) return false;
        }
     return true;   
    }
};