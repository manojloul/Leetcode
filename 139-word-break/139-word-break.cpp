class Solution {
public:unordered_map<string,int> mp;
    map<pair<string,int>,bool> dp;
    bool solve(string &s,string st,int pos)
    {
      if(pos==s.size()){
        if(mp.find(st)!=mp.end()) return true;
          return false;
      } 
     
    if(dp.find({st,pos})!=dp.end()) return dp[{st,pos}];
      
        st+=s[pos];
      if(mp.find(st)==mp.end())
          return dp[{st,pos}]=solve(s,st,pos+1);
        else
        {
            return dp[{st,pos}]=solve(s,st,pos+1) || solve(s,"",pos+1);
        }
    }
    bool wordBreak(string s, vector<string>& dic) {
        for(int i=0;i<dic.size();++i)
            mp[dic[i]]++;
        string st="";
        int pos=0;
        return solve(s,st,pos);
    }
};