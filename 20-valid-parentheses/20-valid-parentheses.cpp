class Solution {
public:
    unordered_map<char,int> mp={{'(',-1},{'[',-2},{'{',-3},{')',1},{']',2},{'}',3}};
    bool isValid(string s) {
        stack<char> st;
        
        for(int i=0;i<s.size();++i)
        {
            if(mp[s[i]]<0)
                st.push(s[i]);
            else
            {
                if(st.empty()) return false;
                if(mp[s[i]]+mp[st.top()]==0)
                {
                    st.pop();
                }
                else
                    return false;
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};