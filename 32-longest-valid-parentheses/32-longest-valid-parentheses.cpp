class Solution {
public:
    int longestValidParentheses(string s) {
        
        stack<int> st;
        int mx=0;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='(')
                st.push(i);
            else
            {
                if(st.empty())
                {
                    st.push(i);
                    continue;
                }
                if(s[st.top()]=='(')
                {
                    int p;
                    st.pop();
                    if(st.empty())
                        p=-1;
                    else
                        p=st.top();
                    //cout<<p<<" "<<i<<endl;
                    mx=max(mx,i-p);
                }
                else
                    st.push(i);
            }
        }
        return mx;
    }
};