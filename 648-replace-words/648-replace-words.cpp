struct Node{
    Node* links[26];
    bool f=false;
    
    bool is_contains(char ch)
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
  private : Node* root;
    public:
    Trie()
    {
        root=new Node();
    }
    
    void insert(string str)
    {
        Node* t=root;
        
        for(int i=0;i<str.size();++i)
        {
            if(!t->is_contains(str[i]))
            {
                t->put(str[i],new Node());
            }
            t=t->get(str[i]);
        }
        t->f=true;
    }
    
    string search(string str)
    {
        string ans="";
        
        Node* t=root;
        
        for(int i=0;i<str.size();++i)
        {
            if(t->is_contains(str[i]))
            {
                ans+=str[i];
            }
            else break;
            
            t=t->get(str[i]);
            if(t->f) return ans;
        }
        
        if(t->f)
        return ans;
        else return "";
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dt, string st) {
        Trie t;
        
        for(int i=0;i<dt.size();++i)
            t.insert(dt[i]);
        
        stringstream ss(st);
        string ans;
        string s;
        
        while(ss>>s)
        {
            string tmp=t.search(s);
            if(tmp=="")
                ans+=s;
            else ans+=tmp;
            ans+=" ";
        }
        ans.pop_back();
        return ans;
    }
};