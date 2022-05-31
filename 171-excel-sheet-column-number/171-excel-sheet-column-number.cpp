class Solution {
public:
    int titleToNumber(string s) {
        reverse(s.begin(),s.end());
        int ans=0;
        
        for(int i=0;i<s.size();++i)
        {
            ans+=pow(26,i)*(s[i]-'A'+1);
        }
        return ans;
    }
};