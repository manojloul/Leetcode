class Solution {
public:
    vector<int> partitionLabels(string s) {
         unordered_map<char,int> mp,m;
        
        for(int i=0;i<s.size();++i)
            mp[s[i]]++;
        
        int i=0,j=0;
        vector<int> ans;
        
        while(j<s.size())
        {
            mp[s[j]]--;
            if(mp[s[j]]==0)
            {
                if(m.find(s[j])!=m.end())
                    m.erase(s[j]);
            }
            else
                m[s[j]]++;
            
            if(m.size()==0)
            {
                ans.push_back(j-i+1);
                i=j+1;
            }
            
            j++;
        }
        
        return ans;
    }
}; 