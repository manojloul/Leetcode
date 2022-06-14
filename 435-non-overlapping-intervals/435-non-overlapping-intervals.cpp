class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int count=0;
        
        int l=0,r=1;
        
        while(r<intervals.size())
        {
            if(intervals[r][0]>=intervals[l][1])
            {
                l=r;
                r+=1;
            }
            else if(intervals[l][1]>=intervals[r][1])
            {
                count++;
                l=r;
                r+=1;
            }
            else if(intervals[l][1]<intervals[r][1])
            {
                count++;
                r+=1;
            }
        }
        
        return count;
    }
};