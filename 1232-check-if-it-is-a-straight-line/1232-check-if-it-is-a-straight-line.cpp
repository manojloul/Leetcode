class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& co) {
        
        if(co.size()==2) return true;
        
        double ym=co[1][1]-co[0][1];
        double xm=co[1][0]-co[0][0];
        if(xm==0)
        {
           for(int i=2;i<co.size();++i)
           {
               if(co[i][0]!=co[i-1][0]) return false;
           } 
        }
        else
        {
            double m=ym/xm;
            cout<<m<<endl;
            for(int i=2;i<co.size();++i)
            {
                double d=(co[i][1]-co[i-1][1])/(double)(co[i][0]-co[i-1][0]);
                cout<<d<<endl;
                if(d!=m) return false;
            }
        }
        return true;
    }
};