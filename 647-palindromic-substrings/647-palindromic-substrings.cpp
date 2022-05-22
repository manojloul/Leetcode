class Solution {
public:int count=0;
    void check(string s,int l,int r)
    {
        while(l>=0 && r<s.size() && s[l]==s[r])
        {
            count++;
            l--;
            r++;
        }
    }
    int countSubstrings(string s) {
        
        for(int i=0;i<s.size();++i)
        {
            check(s,i,i);
            check(s,i,i+1);
        }
        return count;
    }
};