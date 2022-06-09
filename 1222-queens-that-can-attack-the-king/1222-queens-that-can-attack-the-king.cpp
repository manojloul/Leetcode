class Solution {
public:vector<vector<int>> ans;
    void solve(vector<vector<int>>& q,int x,int y)
    {
        for(int i=x-1;i>=0;--i) 
        {  
            if(q[i][y]==1)
            {  ans.push_back({i,y});
                break;
            }
        }
        for(int i=x+1;i<8;++i) 
        {  
            if(q[i][y]==1)
            {  ans.push_back({i,y});
                break;
            }
        }
        
        for(int i=y-1;i>=0;--i) 
        {  
            if(q[x][i]==1)
            {  ans.push_back({x,i});
                break;
            }
        }
        for(int i=y+1;i<8;++i) 
        {  
            if(q[x][i]==1)
            {  ans.push_back({x,i});
                break;
            }
        }
        
        int i=x-1,j=y-1;
        while(i>=0 && j>=0)
        {
            if(q[i][j]==1)
            {ans.push_back({i,j});
                break;
            }
            i--;
            j--;
        }
        i=x+1,j=y+1;
        while(i<8 && j<8)
        {
            if(q[i][j]==1)
            {ans.push_back({i,j});
                break;
            }
            i++;
            j++;
        }
        
        i=x-1,j=y+1;
        while(i>=0 && j<8)
        {
            if(q[i][j]==1)
            {ans.push_back({i,j});
                break;
            }
            i--;
            j++;
        }
        i=x+1,j=y-1;
        while(i<8 && j>=0)
        {
            if(q[i][j]==1)
            {ans.push_back({i,j});
                break;
            }
            i++;
            j--;
        }
    }
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& q, vector<int>& king) {
       vector<vector<int>> t(8,vector<int>(8,0));
        for(int i=0;i<q.size();++i)
            t[q[i][0]][q[i][1]]=1;
        solve(t,king[0],king[1]);
        return ans;
    }
    
};