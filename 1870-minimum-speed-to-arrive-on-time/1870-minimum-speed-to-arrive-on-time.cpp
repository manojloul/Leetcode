class Solution {
public:
    bool isvalid(vector<int> &dist,double hr,int k)
    {
        double n=0;
        
        for(int i=0;i<dist.size()-1;++i)
        {
                n+=(dist[i]+k-1)/k;
        }
        n+=dist[dist.size()-1]*1.0/k;
        
        if(n>hr) return false;
        return true;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        double sum=1e9;
      
        double i=1;
        int ans=-1;
        while(i<=sum)
        {
            int mid=i+(sum-i)/2;
            if(isvalid(dist,hour,mid))
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