class Solution {
public:
    bool isvalid(vector<int> &candies,long long k,long long st)
    {
        long long int kn=0;
        
        for(int i=0;i<candies.size();++i)
        {
            kn+=candies[i]/st;
            if(kn>=k) return true;
        }
        
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long int sum=0;
        
        for(int i=0;i<candies.size();++i)
            sum+=candies[i];
        
        long long int i=1;
        int ans=0;
        while(i<=sum)
        {
            long long int mid=i+(sum-i)/2;
            if(isvalid(candies,k,mid))
            {
                ans=mid;
                i=mid+1;
            }
            else
                sum=mid-1;
        }
        return ans;
    }
};