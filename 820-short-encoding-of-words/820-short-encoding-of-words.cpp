class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string> st,s2;
        
        for(int i=0;i<words.size();++i)
        {
            st.insert(words[i]);
        }
        s2=st;
        
        for(auto it:st)
        {
            string s=it;
            for(int i=1;i<s.size();++i)
            {
                s2.erase(s.substr(i,s.size()));
            }
        }
        
        int k=0;
        for(auto it:s2) {
            k+=it.size();
        }
        return k+s2.size();
    }
};