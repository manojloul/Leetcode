class Solution {
public:
    bool isvalid(vector<int> &time,long long t,long long m)
    {
        long long sum=0;
        
        for(int i=0;i<time.size();++i)
        {
            sum+=m/time[i];
        }
        if(sum>=t) return true;
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long sum=1e11+7;
        long long i=0;
         if( time.size()==0 ){
            return 0;
        } else if ( time.size() == 1 ){
            return ( (long long) time[0])*totalTrips;
        }
        long long  ans=0;
        
        while(i<=sum)
        {
            long long mid=i+(sum-i)/2;
            
            if(isvalid(time,totalTrips,mid))
            {
                ans=mid;
                sum=mid-1;
            }
            else
                i=mid+1;
        }
        return ans;
    }
};