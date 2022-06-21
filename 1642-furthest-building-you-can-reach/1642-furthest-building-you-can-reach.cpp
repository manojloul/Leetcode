class Solution {
public:
    // bool isvalid(priority_queue<int> pq,int b,int l)
    // {
    //     while(!pq.empty())
    //     {
    //         if(l>0){
    //             pq.pop();
    //             l--;
    //         }
    //         else if(b>0)
    //         {
    //             if(pq.top()>b) return false;
    //             b-=pq.top();
    //             pq.pop();
    //         }
    //         else return false;
    //     }
    //     return true;
    // }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int ans=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=1;i<heights.size();++i)
        {
            if(heights[i]>heights[i-1])
            {
                if(ladders>0)
                {
                    if(pq.size()==ladders)
                    {
                        if(pq.top()>heights[i]-heights[i-1])
                        {
                            if(heights[i]-heights[i-1]>bricks) break;
                            else bricks-=heights[i]-heights[i-1];
                        }
                        else
                        {
                            int k=pq.top();
                            pq.pop();
                            pq.push(heights[i]-heights[i-1]);
                            if(bricks<k) break;
                            else bricks-=k;
                        }
                    }
                    else
                    {
                        pq.push(heights[i]-heights[i-1]);
                    }
                }
                else
                {
                    if(heights[i]-heights[i-1]>bricks) break;
                        else bricks-=heights[i]-heights[i-1];
                }
            }
            ans=i;
        }
        return ans;
    }
};