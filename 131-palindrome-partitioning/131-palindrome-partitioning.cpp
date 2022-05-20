class Solution {
public:vector<vector<string>> ans;
    bool ispal(string &s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(string &s,int pos,vector<string> &v)
    {
        if(pos==s.size())
        {
                ans.push_back(v);
            return;
        }
       for(int i=pos;i<s.size();++i)
       {
           if(ispal(s,pos,i))
           {
               v.push_back(s.substr(pos,i-pos+1));
               solve(s,i+1,v);
               v.pop_back();
           }
       }
    }
    vector<vector<string>> partition(string s) {
        vector<string> v;
        int pos=0;
        solve(s,pos,v);
        return ans;
    }
};