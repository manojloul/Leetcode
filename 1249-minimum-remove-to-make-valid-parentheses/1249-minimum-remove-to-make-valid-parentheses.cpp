class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans;
        set<int> p;
        stack<int> st;
        
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else if(s[i]==')')
            {
                if(!st.empty() && s[st.top()]=='(')
                {
                    st.pop();
                }
                else
                    p.insert(i);
            }
        }
        while(!st.empty())
        {
            p.insert(st.top());
            st.pop();
        }
       
        for(int i=0;i<s.size();++i)
        {
            if(p.find(i)==p.end())
                ans.push_back(s[i]);
        }
        return ans;
    }
};