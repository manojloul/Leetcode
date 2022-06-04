class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans=prices.size();
        int i=0;
        for(int j=1;j<prices.size();++j)
        {
            if(prices[j-1]-prices[j]==1)
                ans+=j-i;
            else
                i=j;
        }
        
        return ans;
    }
};