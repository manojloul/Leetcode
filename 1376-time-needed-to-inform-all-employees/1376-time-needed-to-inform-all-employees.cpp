class Solution {
public:
 int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>> mp;
        for(int i=0; i<n;i++)
            if(manager[i]!=-1)
                mp[manager[i]].push_back(i);
        int res= numOfMinutes1(headID,mp,informTime);
        return res;
    }
    int numOfMinutes1(int headID, unordered_map<int,vector<int>>& map, vector<int>& informTime)
    {
        if (informTime[headID]==0) return 0;
        int res=-1;
        for(auto it:map[headID])
            res = max(res,numOfMinutes1(it,map,informTime));
        return res +informTime[headID];
    }
};