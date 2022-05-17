class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int mn=INT_MAX;
        int i=0,j=0;
        unordered_map<int,int> mp;
        while(j<cards.size())
        {
            
            
            if(mp.find(cards[j])!=mp.end())
            {
                //cout<<j<<" "<<mp[cards[j]]<<endl;
                mn=min(mn,j-mp[cards[j]]+1);
            }
            mp[cards[j]]=j;
            j++;
        }
        if(mn==INT_MAX)
            return -1;
        return mn;
    }
};