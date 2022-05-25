class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(i==0 || j==0 || i==n-1 || j==m-1) 
                {
                    if(board[i][j]=='O')
                        q.push({i,j});
                }
            }
        }
       
        while(!q.empty())
        {
            pair<int,int> p=q.front();
            q.pop();
            int i=p.first;
            int j=p.second;
            
            board[i][j]='V';
                int row[4]={-1,1,0,0};
                int col[4]={0,0,-1,1};
            
                for(int k=0;k<4;++k)
                {
                    
                 if(i+row[k]>=0 && i+row[k]<n-1 && j+col[k]>=0 && j+col[k]<m-1)
                        {
                             if(board[i+row[k]][j+col[k]]=='O')
                             {
                                 q.push({i+row[k],j+col[k]});
                             }
                        }
                }
                
           }
        
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(board[i][j]=='O') board[i][j]='X';
                
                if(board[i][j]=='V') board[i][j]='O';
            }
        }
    }
};