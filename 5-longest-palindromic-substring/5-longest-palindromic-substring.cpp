class Solution {
public:
    pair<int,int> ispal(string s,int i,int j)
    {
        if(s[i]!=s[j]) return {i,j-1};
        while(i>=0 && j<s.size())
        {
            if(s[i]!=s[j]) break;
            i--;
            j++;
        }
        i++;
        j--;
        return {i,j};
    }
    string longestPalindrome(string s) {
        if(s.size()==1) return s;
        string ans="";
        
        for(int i=0;i<s.size()-1;++i)
        {
            pair<int,int> p1=ispal(s,i,i);
            pair<int,int> p2=ispal(s,i,i+1);
            if(p1.second-p1.first>p2.second-p2.first)
            {
                int e=p1.second;
                int st=p1.first;
                if(e-st+1>ans.size())
                    ans=s.substr(st,e-st+1);
            }
            else
            {
                int e=p2.second;
                int st=p2.first;
                if(e-st+1>ans.size())
                    ans=s.substr(st,e-st+1);
            }
           // cout<<ans<<endl;
        }
        return ans;
    }
};