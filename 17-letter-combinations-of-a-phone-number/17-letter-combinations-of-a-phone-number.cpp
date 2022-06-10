class Solution {
public:vector<string> ans;
    void solve(unordered_map<int,string> &mp,string dig,int &pos,string &s)
    {
        if(pos==dig.size())
        {
            ans.push_back(s);
            return;
        }
        
        string st=mp[dig[pos]-48];
        for(int i=0;i<st.size();++i)
        {
            s+=st[i];
            pos++;
            solve(mp,dig,pos,s);
            s.pop_back();
            pos--;
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        unordered_map<int,string> mp;
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        string s="";
        int i=0;
        solve(mp,digits,i,s);
        
        return ans;
    }
};