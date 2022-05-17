class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mx=0;
        unordered_map<char,int> mp;
        int count=0;
        int i=0,j=0;
        while(j<s.size())
        {
            mp[s[j]]++;
            count++;
            
            while(mp.size()<count && i<=j)
            {
                mp[s[i]]--;
                count--;
                if(mp[s[i]]==0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
            mx=max(mx,count);
            j++;
        }
        return mx;
    }
};