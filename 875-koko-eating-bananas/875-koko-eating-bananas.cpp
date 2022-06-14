class Solution {
public:
    bool isvalid(vector<int> &piles,int h,int k)
    {
        long int hr=0;
        for(int i=0;i<piles.size();++i)
        {
            if(piles[i]%k==0) hr+=piles[i]/k;
            else hr+=piles[i]/k+1;
           // cout<<hr<<endl;
            if(hr>h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int sum=0;
        for(int i=0;i<piles.size();++i)
        {
            sum+=piles[i];
        }
        
        long long int i=1;
        long int ans=0;
        while(i<=sum)
        {
            long long mid=i+(sum-i)/2;
           // cout<<mid<<" ";
            if(isvalid(piles,h,mid))
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