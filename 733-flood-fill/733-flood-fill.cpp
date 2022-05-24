class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int m=image[sr][sc];
        image[sr][sc]=-1;
        while(!q.empty())
        {
            pair<int,int> p=q.front();
            q.pop();
            int i=p.first;
            int j=p.second;
            
            int row_change[4]={-1,1,0,0};
            int col_change[4]={0,0,-1,1};
            
            for(int k=0;k<4;++k)
            {
                if(i+row_change[k]>=0 && i+row_change[k]<image.size() && j+col_change[k]>=0 && j+col_change[k]<image[0].size())
                {
                    if(image[i+row_change[k]][j+col_change[k]]==m)
                    {
                        //cout<<i+row_change[k]<<" "<<j+col_change[k]<<endl;
                        q.push({i+row_change[k],j+col_change[k]});
                        image[i+row_change[k]][j+col_change[k]]=-1;
                    }
                    }
                }
            }   
        for(int i=0;i<image.size();++i)
        {
            for(int j=0;j<image[0].size();++j)
            {
                if(image[i][j]==-1)
                    image[i][j]=newColor;
            }
        }
            return image;
        }
    
};