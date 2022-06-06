class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n=box.size();
        int  m=box[0].size();
        for(int i=0;i<n;++i)
        {
            int p=m-1;
            for(int j=m-1;j>=0;--j)
            {
                if(box[i][j]=='*')
                    p=j-1;
                else if(box[i][j]=='#')
                    swap(box[i][j],box[i][p--]);
            }
        }
        vector<vector<char>> ans;
        
        for(int j=0;j<m;++j)
        {
            vector<char> temp;
            for(int i=n-1;i>=0;--i)
            {
                temp.push_back(box[i][j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};