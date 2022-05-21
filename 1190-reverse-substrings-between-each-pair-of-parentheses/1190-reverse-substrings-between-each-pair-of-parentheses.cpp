class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else
            {
                if(s[i]==')')
                {
                    
                    int k=st.top();
                    st.pop();
                    reverse(s.begin()+k,s.begin()+i);
                    //cout<<s<<endl;
                }
            }
        }
        string str="";
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='(' ||s[i]==')')
                continue;
            str+=s[i];
        }
        return str;
    }
};