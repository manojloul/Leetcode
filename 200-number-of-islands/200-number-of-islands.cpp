class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ROW = grid.size(), COL = grid[0].size();
        int numIsland = 0;
        queue<pair<int,int>> q;
        vector<pair<int,int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        for(int i=0; i<ROW; i++){
            for(int j=0; j<COL; j++){
                if(grid[i][j] == '1'){
                    numIsland++;
                    grid[i][j] = '0';
                    q.push({i,j});
                    while(!q.empty()){
                        int qSize = q.size();
                        while(qSize--){
                            auto [x, y] = q.front(); q.pop();
                            for(auto dir : dirs){
                                int _x = x + dir.first, _y = y + dir.second;
                if(_x < 0 || _y < 0 || _x >= ROW || _y >= COL || grid[_x][_y] == '0'){
                                    continue;
                                }
                                grid[_x][_y] = '0';
                                q.push({_x, _y});
                            }
                        }
                    }
                }
            }
        }
        return numIsland;
    }
};