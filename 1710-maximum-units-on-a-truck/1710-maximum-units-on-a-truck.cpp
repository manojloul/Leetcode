class Solution {
public:
    static bool cmp(vector<int> &v1,vector<int> &v2)
    {
        return v1[1]>v2[1];
    }
    int maximumUnits(vector<vector<int>>& box, int truck) {
        sort(box.begin(),box.end(),cmp);
        int ans=0;
        
        for(int i=0;i<box.size();++i)
        {
            if(truck>=box[i][0])
            {
                ans+=box[i][0]*box[i][1];
                truck-=box[i][0];
            }
            else
            {
                if(truck>0)
                {
                    ans+=box[i][1]*truck;
                    break;
                }
                else
                    break;
            }
        }
        return ans;
    }
};