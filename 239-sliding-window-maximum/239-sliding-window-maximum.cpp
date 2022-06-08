class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> v;
        deque<int> dq;
        
        int i=0,j=0;
        while(j<nums.size())
        {
            
            if(j-i<k)
            {
                int l=dq.size()-1;
                while(l>=0 && dq[l]<nums[j])
                {
                    dq.pop_back();
                    l--;
                }
                dq.push_back(nums[j]);
            }
            
            if(j-i+1==k)
            {
                v.push_back(dq.front());
                
                if(nums[i]==dq.front())
                      dq.pop_front();
                i++;
            }
            
            j++;
        }
        return v;
    }
};