class Solution {
public:vector<string> ans;
    void solve(string &s,int &o,int &c)
    {
        if(o==0 && c==0)
        {
            ans.push_back(s);
            return;
        }
        //cout<<o<<" "<<c<<endl;
        
        if(o)
        {
            s+='(';
            o--;
            solve(s,o,c);
            o++;
            s.pop_back();
        }
        if(c>o)
        {
            s+=')';
            c--;
            solve(s,o,c);
            c++;
            s.pop_back();
        }
        
        
    }
    vector<string> generateParenthesis(int n) {
        int o=n,c=n;
        string s="";
        solve(s,o,c);
        return ans;
    }
};