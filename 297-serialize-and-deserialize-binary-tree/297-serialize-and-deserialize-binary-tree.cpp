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
public:string s;
     void solve(TreeNode* root)
     {
         if(root==NULL)
         {
             s+='*';
             s+='_';
             return;
         }
         
         s+=to_string(root->val);
         s+='_';
         
         solve(root->left);
         solve(root->right);
     }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
         
        if(root==NULL) return s;
        solve(root);
        s.erase(--s.end());
        return s;
    }

    // Decodes your encoded data to tree.
    int i=0;
    TreeNode* solve(string str)
    {
        if(i>=str.size()) return NULL;
        int data=0;
        if(str[i]=='*')
        {
            i+=2;
            return NULL;
        }
        int p=1;
        while(str[i]!='_')
        {
            if(str[i]=='-'){
                i++;
                p=-1;
                continue;
            }
            data=data*10+str[i]-48;
            i++;
        }
        i++;
        //cout<<data<<" ";
        TreeNode* root=new TreeNode(data*p);
        
        root->left=solve(str);
        root->right=solve(str);
        return root;
    }
    TreeNode* deserialize(string data) {
        cout<<data<<endl;
        if(data=="") return NULL;
        return solve(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));