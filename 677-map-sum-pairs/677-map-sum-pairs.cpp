unordered_map<string,int> mp;
struct Node{
    Node* links[26];
    int tot=0;
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
  private :Node* root;
    public:
    Trie()
    {
        root=new Node();
    }
    bool check(string str)
    {
        Node* node=root;
        for(int i=0;i<str.size();++i)
        {
            if(!node->iscontains(str[i]))
                return false;
            
            node=node->get(str[i]);
        }
        return node->f;
    }
    void insertkey(string str,int val)
    {
        Node* node=root;
        bool f=false;
        int p=0;
        if(mp.find(str)!=mp.end())
        {
            f=true;
            p=mp[str];
        }
        for(int i=0;i<str.size();++i)
        {
            if(!node->iscontains(str[i]))
                node->put(str[i],new Node());
            
            node=node->get(str[i]);
            if(f)
                node->tot=node->tot-p+val;
            else
            node->tot+=val;
        }
        node->f=true;
    }
    int search(string str)
    {
        Node* node=root;
        for(int i=0;i<str.size();++i)
        {
            if(!node->iscontains(str[i]))
                return 0;
            
            node=node->get(str[i]);
        }
        return node->tot;
    }
};
class MapSum {
public:
    Trie t;
    MapSum() {
        mp.clear();
    }
    
    void insert(string key, int val) {
        t.insertkey(key,val);
        mp[key]=val;
    }
    
    int sum(string prefix) {
        return t.search(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */