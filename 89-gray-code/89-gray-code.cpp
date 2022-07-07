class Solution {
public:

    int bt(string s)
    {
        int t=0;
        int i=s.size()-1;
        int k=0;
        while(i>=0)
        {
            t+=(s[i]-48)*pow(2,k++);
            i--;
        }
        return t;
    }
    vector<string> solve(int n)
    {
        if(n==1)
        {
            vector<string> v={"0","1"};
            return v;
        }

        vector<string> v=solve(n-1);
        vector<string> t;

        for(int i=0;i<v.size();++i)
        {
            t.push_back("0"+v[i]);
        }
        for(int i=v.size()-1;i>=0;--i)
        {
            t.push_back("1"+v[i]);
        }
        return t;
    }
    vector<int> grayCode(int A) {
         vector<string> v=solve(A);
        vector<int> ans;
        for(auto it:v)
         ans.push_back(bt(it));
        return ans;
    }
};