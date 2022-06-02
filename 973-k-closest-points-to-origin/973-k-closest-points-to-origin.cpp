class Solution {
public:
    static bool cmp(pair<double,pair<int,int>>& p1,pair<double,pair<int,int>>&p2)
    {
        return p1.first<p2.first;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        vector<pair<double,pair<int,int>>> p;
        
        for(int i=0;i<points.size();++i)
        {
            double d=sqrt((points[i][0]*points[i][0])+(points[i][1]*points[i][1]));
            p.push_back({d,{points[i][0],points[i][1]}});
        }
        sort(p.begin(),p.end(),cmp);
        for(int i=0;i<k;++i)
        {
            ans.push_back({p[i].second.first,p[i].second.second});
        }
        return ans;
    }
};