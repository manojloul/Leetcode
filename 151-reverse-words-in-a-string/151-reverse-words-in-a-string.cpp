class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string st,t;
        while(ss>>t)
            st=t+" "+st;
        st.pop_back();
        return st;
    }
};