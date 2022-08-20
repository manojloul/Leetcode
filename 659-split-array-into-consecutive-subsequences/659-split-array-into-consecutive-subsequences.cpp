class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> mp,es;
        for(int i=0;i<nums.size();++i)
            mp[nums[i]]++;
        

        for(int i=0;i<nums.size();++i)
        {
            if(mp[nums[i]]==0) continue;
            
            if(es[nums[i]]>0)
            {
                es[nums[i]]--;
                mp[nums[i]]--;
                
                es[nums[i]+1]++;
            }
            else if(mp[nums[i]]>0 && mp[nums[i]+1]>0 && mp[nums[i]+2]>0)
            {
                mp[nums[i]]--;
                mp[nums[i]+1]--;
                mp[nums[i]+2]--;
                
                es[nums[i]+3]++;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};