class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int maxans=0;
        for(int i=0;i<points.size();i++){
            int x=points[i][0];
            int y=points[i][1];
            map<double,int> mp;
            for(int j=0;j<points.size();j++){
                if(x==points[j][0] && y==points[j][1]) continue;
                double slope=(double)(points[j][1]-y)/(points[j][0]-x);
                mp[slope]++;
            }
            for(auto el:mp) maxans=max(maxans,el.second);
        }
        return maxans+1;
    }
};