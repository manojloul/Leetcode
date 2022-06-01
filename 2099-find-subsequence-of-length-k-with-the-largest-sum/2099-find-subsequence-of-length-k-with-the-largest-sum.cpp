class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int i=0;i<nums.size();++i)
        {
            pq.push(nums[i]);
            while(pq.size()>k)
            {
                pq.pop();
            }
            
        }
        
        vector<int> v;
        unordered_map<int,int> mp;
        while(!pq.empty())
        {
            mp[pq.top()]++;
            pq.pop();
        }
        
        for(int i=0;i<nums.size();++i)
        {
            if(mp.find(nums[i])!=mp.end())
            {
                v.push_back(nums[i]);
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                    mp.erase(nums[i]);
            }
        }
        return v;
    }
};