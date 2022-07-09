struct Node{
  Node* links[26];
    bool f=false;
    
    bool contains(char ch)
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
class Trie {
private: Node* root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* temp=root;
        
        for(int i=0;i<word.size();++i)
        {
            if(!temp->contains(word[i]))
            {
                temp->put(word[i],new Node());
            }
            temp=temp->get(word[i]);
        }
        temp->f=true;
    }
    
    bool search(string word) {
        Node* temp=root;
        
        for(int i=0;i<word.size();++i)
        {
            if(temp->contains(word[i]))
            {
                temp=temp->get(word[i]);
            }
            else return false;
        }
        return temp->f;
    }
    
    bool startsWith(string prefix) {
        Node* temp=root;
        
        for(int i=0;i<prefix.size();++i)
        {
            if(temp->contains(prefix[i]))
            {
                temp=temp->get(prefix[i]);
            }
            else return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */