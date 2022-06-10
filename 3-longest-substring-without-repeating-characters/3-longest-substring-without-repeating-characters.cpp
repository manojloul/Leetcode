class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int mx=0;
        int count=0;
        
        int i=0,j=0;
        
        while(j<s.size())
        {
            mp[s[j]]++;
            
            while(mp.size()<j-i+1)
            {
                mp[s[i]]--;
                if(mp[s[i]]==0)
                    mp.erase(s[i]);
                i++;
            }
            if(mp.size()==j-i+1)
                mx=max(mx,j-i+1);
            
            j++;
        }
        
        return mx;
    }
};