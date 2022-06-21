class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int a) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int ans=0;
        
        for(int i=0;i<rocks.size();++i)
        {
            if(rocks[i]==capacity[i]) ans++;
            else pq.push(capacity[i]-rocks[i]);
        }
        
        while(!pq.empty())
        {
            int k=pq.top();
            pq.pop();
            if(a>=k)
            {
                a-=k;
                ans++;
            }
            else
                break;
        }
        return ans;
    }
};