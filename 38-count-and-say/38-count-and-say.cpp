class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        if(n==2)
            return "11";
        vector<string> v;
        v.push_back("1");
        v.push_back("11");
        
        for(int i=2;i<n;++i)
        {
            string temp="";
            string s=v[i-1];
            //cout<<s<<endl;
            int count=1;
            for(int j=1;j<s.size();++j)
            {
                if(s[j]!=s[j-1])
                {
                    temp+=to_string(count);
                    count=1;
                    temp+=s[j-1];
                }
                else
                    count++;
            }
            
            int l=s.size();
            temp+=to_string(count);
            temp+=s[l-1];
            v.push_back(temp);
        }
        
        return v[n-1];
    }
};