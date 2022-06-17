/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string ans="";
    void solve(TreeNode* root)
    {
        if(root==NULL)
        {
            ans+='_';
            ans+='*';
            return ;
        }
        
        ans+='_';
        ans+=to_string(root->val);
        
        solve(root->left);
        solve(root->right);
    }
    string serialize(TreeNode* root) {
        solve(root);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* create(string &data,int &pos)
    {
        
        if(data[pos]=='*'){
            pos+=2;
            return NULL;
        }
        string t="";
        int p=1;
        while(pos<data.size() && data[pos]!='_')
        {
            if(data[pos]=='-')
            {
                p=-1;
                pos++;
                continue;
            }
            t+=data[pos++];
        }
        //cout<<t<<" "<<pos<<endl;
        pos++;
        TreeNode* root=new TreeNode(p*stoi(t));
        root->left=create(data,pos);
        root->right=create(data,pos);
        return root;
        
    }
    TreeNode* deserialize(string data) {
        data.erase(data.begin());
        //cout<<data<<endl;
        int pos=0;
        return create(data,pos);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));