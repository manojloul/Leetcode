class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        string s1,s2;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='#')
            {
                if(!st.empty()) st.pop();
            }
            else
                st.push(s[i]);
        }
        while(!st.empty())
        {
            s1=st.top()+s1;
            st.pop();
        }
        
        for(int i=0;i<t.size();++i)
        {
            if(t[i]=='#')
            {
                if(!st.empty()) st.pop();
            }
            else
                st.push(t[i]);
        }
        
        while(!st.empty())
        {
            s2=st.top()+s2;
            st.pop();
        }
        
        return s1==s2;
    }
};