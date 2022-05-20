class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int l=code.size(),s=0;
        vector<int> ans;
        if(k==0)
        {
            for(int i=0;i<code.size();i++)
            {
                ans.push_back(0);
            }
        }
        if(k>0)
        {
            for(int i=0;i<code.size();i++)
            {
                int s=0;
                for(int j=0;j<k;j++)
                {
                    s+=code[(i+j+1)%l];
                }
                ans.push_back(s);
            }
        }
        if(k<0)
        {
            for(int i=0;i<l;i++)
            {
                int s=0;
                for(int j=0;j<abs(k);j++)
                {
                    
                    s+=code[(i-1-j+l)%l];
                }
                ans.push_back(s);
            }
        }
        return ans;
    }
};