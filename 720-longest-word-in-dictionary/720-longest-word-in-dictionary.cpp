struct Node{
    Node *links[26];
    bool f=false;
    
    bool iscontains(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    
    void put(char ch,Node* node)
    {
        links[ch-'a']=node;
    }
    
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
};
class Trie{
  private: Node* root;
   public: Trie(){
        root=new Node();
    }
    
    public: 
    void insert(string str)
    {
        Node* node=root;
        
        for(int i=0;i<str.size();++i)
        {
            if(!node->iscontains(str[i]))
            {
                node->put(str[i],new Node());
            }
            node=node->get(str[i]);
        }
        node->f=true;
    }
    bool isfind(string str)
    {
        Node* node=root;
        
        for(int i=0;i<str.size();++i)
        {
            if(node->iscontains(str[i]))
            {
                node=node->get(str[i]);
                if(!node->f) return false;
            }
            else return false;
        }
        return node->f;
    }
};
class Solution {
public:
    string longestWord(vector<string>& words) {
        string ans="";
        Trie t;
        for(auto &str:words)
        {
            t.insert(str);
        }
        
        for(auto &str:words)
        {
            if(t.isfind(str) )
            {
                if(str.size()>ans.size()) ans=str;
                else if(ans.size()==str.size())
                {
                    ans=min(ans,str);
                }
            }
        }
        return ans;
    }
};