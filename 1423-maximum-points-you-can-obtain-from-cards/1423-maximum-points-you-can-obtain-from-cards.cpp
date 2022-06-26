class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n=card.size();
        int l=n-k;
        int i=0,j=0;
        int sum=0,mn=INT_MAX;
        while(j<card.size())
        {
            sum+=card[j];
            if(j-i+1==l)
            {
                mn=min(mn,sum);
                sum-=card[i];
                i++;
            }
            
            j++;
        }
        
        sum=0;
        for(int i=0;i<card.size();++i)
            sum+=card[i];
        
        if(mn==INT_MAX) return sum;
        return sum-mn;
    }
};