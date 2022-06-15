class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> v;
        map<string,int> mp;
        
        int i=0,j=0;
        
        while(j<s.size())
        {
            if(j-i+1==10)
            {
                string st=s.substr(i,j-i+1);
                mp[st]++;
                i++;
            }
            j++;
        }
        
        for(auto it:mp)
        {
            if(it.second>1) v.push_back(it.first);
        }
        return v;
        
    }
};