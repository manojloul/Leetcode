class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int count=1;
        int s=-1,e=-1;
        sort(points.begin(),points.end());
        for(int i=0;i<points.size();++i)
        {
            if(s==-1)
            {
                s=points[i][0];
                e=points[i][1];
            }
            else
            {
                if(points[i][0]>e)
                {
                    count++;
                    s=points[i][0];
                    e=points[i][1];
                }
                else
                {
                    s=points[i][0];
                    e=min(points[i][1],e);
                }
            }
        }
        
        return count;
    }
};