class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int curr=0;
        int prev=values[0];
        
        for(int i=1;i<values.size();++i)
        {
            curr=max(curr,prev+values[i]-i);
            prev=max(prev,values[i]+i);
        }
        return curr;
    }
};