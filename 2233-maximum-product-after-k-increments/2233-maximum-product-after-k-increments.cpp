class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int i=0;i<nums.size();++i)
            pq.push(nums[i]);
        
        while(k--)
        {
            int p=pq.top();
            pq.pop();
            pq.push(p+1);
        }
        
        int ans=1;
        
        while(!pq.empty())
        {
            int p=pq.top();
            pq.pop();
            ans=((long)(ans%1000000007)*p)%1000000007;
            ans%=1000000007;
        }
        
        return ans%1000000007;
    }
};