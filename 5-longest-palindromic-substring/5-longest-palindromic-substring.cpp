class Solution {
public:
    pair<int,int> solve(string s,int i,int j)
    {
        while(i>=0 && j<s.size())
        {
            if(s[i]==s[j])
            {
                i--;
                j++;
            }
            else break;
        }
        return {i+1,j-1};
    }
    string longestPalindrome(string s) {
        if(s.size()==1) return s;
        string ans="";
        
        for(int i=0;i<s.size()-1;++i)
        {
            pair<int,int> p1=solve(s,i,i);
            pair<int,int> p2=solve(s,i,i+1);
            
            if(p1.second-p1.first+1>ans.size())
                ans=s.substr(p1.first,p1.second-p1.first+1);
            
            if(p2.second-p2.first+1>ans.size())
                ans=s.substr(p2.first,p2.second-p2.first+1);
        }
        
        return ans;
    }
};