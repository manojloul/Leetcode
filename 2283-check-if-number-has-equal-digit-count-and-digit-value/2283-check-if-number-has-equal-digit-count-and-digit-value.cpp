class Solution {
public:
    bool digitCount(string num) {
        unordered_map<int,int> mp;
        for(int i=0;i<num.size();++i)
            mp[num[i]-48]++;
        
        
        for(int i=0;i<num.size();++i)
        {
            //cout<<mp[i]<<" ";
            if(mp[i]!=num[i]-48) return false;
        }
        return true;
    }
};