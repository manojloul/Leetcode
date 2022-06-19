class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& p, string word) {
        sort(p.begin(),p.end());
        map<string,vector<string>> mp;
        
        for(int i=0;i<p.size();++i)
        {
            string s=p[i];
            for(int j=0;j<=s.size();++j)
            {
                string pr=s.substr(0,j);
                mp[pr].push_back(s);
            }
        }
        vector<vector<string>> ans;
        
        for(int i=1;i<=word.size();++i)
        {
            vector<string> temp=mp[word.substr(0,i)];
            if(temp.size()>3) temp.resize(3);
            ans.push_back(temp);
        }
        return ans;
    }
};