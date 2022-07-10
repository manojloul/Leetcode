struct Node{
    Node* links[2];
    
    bool iscontains(int bit)
    {
        return links[bit]!=NULL;
    }
    
    void put(int bit,Node* node)
    {
        links[bit]=node;
    }
    
    Node* get(int bit)
    {
        return links[bit];
    }
};
class Trie{
  private: Node* root;
    public:
    Trie()
    {
        root=new Node();
    }
    
    void insert(int num)
    {
        Node* node=root;
        
        for(int i=31;i>=0;--i)
        {
            int bit=num>>i &1;
            
            if(!node->iscontains(bit))
                node->put(bit,new Node());
            
            node=node->get(bit);
        }
    }
    
    int getmax(int num)
    {
        Node* node=root;
        int mx=0;
        for(int i=31;i>=0;--i)
        {
            int bit=num>>i &1;
            
            if(node->iscontains(1-bit))
            {
                mx=mx | 1<<i;
                node=node->get(1-bit);
            }
            else
            node=node->get(bit);
        }
        return mx;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        vector<int> ans(queries.size(),0);
        
        vector<pair<int,pair<int,int>>> vp;
        for(int i=0;i<queries.size();++i)
        {
            vp.push_back({queries[i][1],{queries[i][0],i}});
        }
        sort(vp.begin(),vp.end());
        
        int p=0;
        int i=0;
        Trie t;
        while(i<nums.size())
        {
            if(p>=vp.size()) return ans;
            if(nums[i]<=vp[p].first)
            {
                t.insert(nums[i]);
                i++;
            }
            else
            {
                int k=vp[p].second.first;
                int ind=vp[p].second.second;
                
                if(i==0)
                {
                    ans[ind]=-1;
                    p++;
                    continue;
                }
                int mx=t.getmax(k);
                ans[ind]=mx;
                p++;
            }
        }
        while(p<vp.size())
        {
            int k=vp[p].second.first;
            int ind=vp[p].second.second;
             
            int mx=t.getmax(k);
            ans[ind]=mx;
            p++;
        }
        return ans;
    }
};