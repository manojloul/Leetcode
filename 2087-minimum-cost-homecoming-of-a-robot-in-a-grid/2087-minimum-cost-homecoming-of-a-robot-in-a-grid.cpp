class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCost,vector<int>& colCost) {
        int n=rowCost.size();
        int m=colCost.size();
        
        int sr=startPos[0];
        int sc=startPos[1];
        int hr=homePos[0];
        int hc=homePos[1];
        
        int ans=0;
        if(hr>=sr && hc>=sc)
        {
            for(int i=sr+1;i<=hr;++i)
            {
                ans+=rowCost[i];
            }
            for(int i=sc+1;i<=hc;++i)
            {
                ans+=colCost[i];
            }
        }
        else if(hr>=sr && hc<=sc)
        {
            for(int i=sr+1;i<=hr;++i)
            {
                ans+=rowCost[i];
            }
            for(int i=sc-1;i>=hc;--i)
            {
                ans+=colCost[i];
            }
        }
        else if(hr<=sr && hc<=sc)
        {
            for(int i=sr-1;i>=hr;--i)
            {
                ans+=rowCost[i];
            }
            for(int i=sc-1;i>=hc;--i)
            {
                ans+=colCost[i];
            }
        }
        else
        {
            for(int i=sr-1;i>=hr;--i)
            {
                ans+=rowCost[i];
            }
            for(int i=sc+1;i<=hc;++i)
            {
                ans+=colCost[i];
            }
        }
        return ans;
    }
};