class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_map<int,int> mp;
        mp[0]++;
        queue<int> q;
        for(int i=0;i<rooms[0].size();++i)
            q.push(rooms[0][i]);
        while(!q.empty())
        {
            int k=q.front();
            q.pop();
            mp[k]++;
            for(int i=0;i<rooms[k].size();++i)
            {
                if(mp.find(rooms[k][i])==mp.end())
                    q.push(rooms[k][i]);
            }
        }
        
        
        for(int i=0;i<rooms.size();++i)
        {
            if(mp.find(i)==mp.end()) return false;
        }
        return true;
    }
};
//room have key itself