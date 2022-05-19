class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string> v;
        string t;
        while(ss>>t)
            v.push_back(t);
        reverse(v.begin(),v.end());
        s="";
        for(int i=0;i<v.size();++i)
        {
            s+=v[i];
            if(i!=v.size()-1)
                s+=" ";
        }
        return s;
    }
};