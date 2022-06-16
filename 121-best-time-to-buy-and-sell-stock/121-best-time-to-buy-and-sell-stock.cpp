class Solution {
public:
    int maxProfit(vector<int>& p) {
        int mx=0;
        int buy=-1;
        int sell=0;
        for(int i=0;i<p.size();++i)
        {
            if(buy==-1)
                buy=p[i];
            else
            {
                if(p[i]<buy)
                    buy=p[i];
                else
                {
                    sell=p[i];
                    mx=max(mx,sell-buy);
                }
            }
            
            
        }
        return mx;
    }
};