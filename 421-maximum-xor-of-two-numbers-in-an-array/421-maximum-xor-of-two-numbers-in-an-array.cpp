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
                mx=mx|1<<i;
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
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        for(auto &it:nums)
            t.insert(it);
        
        int mx=0;
        
        for(auto &it:nums)
            mx=max(mx,t.getmax(it));
        
        return mx;
    }
};