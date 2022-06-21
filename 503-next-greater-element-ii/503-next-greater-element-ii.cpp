class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // vector<int> ans;
        // stack<int> st;
        // for(int i=nums.size()-1;i>=0;--i)
        // {
        //     if(st.empty()) ans.push_back(-1);
        //     else
        //     {
        //         while(!st.empty() && st.top()<=nums[i])
        //             st.pop();
        //         if(st.top()) ans.push_back(-1);
        //         else ans.push_back(st.top());
        //     }
        //     st.push(nums[i]);
        // }
        // reverse(ans.begin(),ans.end());
        // while(!st.empty() )
        //     st.pop();
        // for(int i=0;i<nums.size();++i)
        // {
        //     if(st.empty())
        //     {
        //         ans[i]=max(ans[i],-1);
        //     }
        //     else
        //     {
        //         while(!st.empty() && st.top()<=nums[i])
        //             st.pop();
        //         if(st.top())
        //         {
        //             ans[i]=max(ans[i],-1);
        //         }
        //         else ans[i]=max(ans[i],nums[i]);
        //     }
        //     st.push(nums[i]);
        // }
        // return ans;
         int n=nums.size();
        vector<int> ans(n,-1);
        stack<int> s;
        for(int i=n-1;i>=0;i--)
            s.push(nums[i]);
        
        for(int i=n-1;i>=0;--i)
        {
            while(!s.empty() && s.top()<=nums[i])
                s.pop();
            if(!s.empty())
                ans[i]=s.top();
            
            s.push(nums[i]);
        }
        return ans;
    }
};