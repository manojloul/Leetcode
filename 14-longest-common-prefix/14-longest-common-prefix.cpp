class Solution {
public:
    string check(string s1,string s2)
    {
        string temp="";
        int i=0,j=0;
        while(i<s1.size() && j<s2.size())
        {
            if(s1[i]==s2[j])
                temp+=s1[i];
            else
                break;
            i++;
            j++;
        }
        return temp;
    }
    string longestCommonPrefix(vector<string>& strs) {
        string ans=strs[0];
        
        for(int i=1;i<strs.size();++i)
        {
            ans=check(ans,strs[i]);
        }
        return ans;
    }
};