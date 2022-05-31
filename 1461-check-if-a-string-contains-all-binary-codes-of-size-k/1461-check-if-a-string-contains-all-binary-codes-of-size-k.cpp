class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size()<k) return false;
        unordered_set<string> st;
        int i=0,j=0;
        while(j<s.size())
        {
            if(j-i+1==k)
            {
                st.insert(s.substr(i,k));
                i++;
            }
            j++;
        }
        if(st.size()==pow(2,k)) return true;
        return false;
    }
};