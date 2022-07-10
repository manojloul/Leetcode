struct Node{
  Node* links[26];
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
    char getChar(char ch)
    {
        for(int i=0;i<26;++i)
        {
            if(links[i]!=NULL && 'a'+i>ch) return 'a'+i;
        }
        char c='0';
        return c;
    }
};
class Trie{
  private: Node* root;
    public:
    Trie(){
        root=new Node();
    }
    
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
    bool check(string str,int pos,Node* node)
    {
        //cout<<pos<<" ";
        for(int i=pos;i<str.size();++i)
        {
            if(!node->iscontains(str[i])) return false;
            node=node->get(str[i]);
        }
        return node->f;
    }
    bool search(string str,int cnt)
    {
         Node* node=root;
        for(int i=0;i<str.size();++i)
        {
            if(node->iscontains(str[i]))
            {
                char p='0';
                while(node->getChar(p)!='0')
                {
                    char ch=node->getChar(p);
                    p=ch;
                    if(p==str[i]) continue;
                    Node* t=node->get(ch);
                    if(check(str,i+1,t)) return true;
                }
                node=node->get(str[i]);
            }
            else{
                char p='0';
                while(node->getChar(p)!='0')
                {
                    char ch=node->getChar(p);
                    p=ch;
                    Node* t=node->get(ch);
                    if(check(str,i+1,t)) return true;
                }
                return false;
            }
        }
        
        return node->f && cnt==0;
    }
};
class MagicDictionary {
public: Trie t;
    MagicDictionary() {
       
    }
    
    void buildDict(vector<string> dt) {
        for(auto &it:dt)
        {
            t.insert(it);
        }
    }
    
    bool search(string searchWord) {
        return t.search(searchWord,1);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */