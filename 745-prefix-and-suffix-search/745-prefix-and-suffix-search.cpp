class WordFilter {
public:
    unordered_map<string,int> mp;
    WordFilter(vector<string>& words) {
        
        for(int i=0;i<words.size();++i)
        {
            string s=words[i];
            for(int j=0;j<=s.size();++j)
            {
                string sf=s.substr(0,j);
                for(int k=0;k<s.size();++k)
                {
                    string p=s.substr(k,s.size());
                    mp[sf+'*'+p]=i+1;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        return mp[prefix+'*'+suffix]-1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */