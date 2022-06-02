class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        vector<pair<int,int>> v;
        int mn=INT_MAX;
        int pos=-1;
        for(int i=0;i<points.size();++i)
        {
            if(points[i][0]==x || points[i][1]==y)
            {
                int d=abs(points[i][0]-x)+abs(points[i][1]-y);
                if(d<mn)
                {
                    mn=d;
                    pos=i;
                }
            }
                
        }
        return pos;
        
        
    }
};