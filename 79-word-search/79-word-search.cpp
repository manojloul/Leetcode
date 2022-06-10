class Solution {
public:bool f=false;
    void solve(vector<vector<char>>& board,int i,int j,string word,int pos)
    {
        int n=board.size();
        int m=board[0].size();
        if(pos==word.size())
        {
            f=true;
            return;
        }
        int row[4]={1,-1,0,0};
        int col[4]={0,0,-1,1};
        
        for(int r=0;r<4;++r)
        {
            if(row[r]+i>=0 && row[r]+i<n && col[r]+j>=0 && col[r]+j<m)
            {
                if(board[row[r]+i][col[r]+j]==word[pos])
                {
                    char ch=board[row[r]+i][col[r]+j];
                    board[row[r]+i][col[r]+j]='.';
                    solve(board,row[r]+i,col[r]+j,word,pos+1);
                    board[row[r]+i][col[r]+j]=ch;
                }
            }
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0;i<board.size();++i)
        {
            for(int j=0;j<board[0].size();++j)
            {
                if(board[i][j]==word[0])
                {
                    char ch=board[i][j];
                    board[i][j]='.';
                    solve(board,i,j,word,1);
                    board[i][j]=ch;
                    if(f) return f;
                }
            }
        }
        
        return f;
    }
};