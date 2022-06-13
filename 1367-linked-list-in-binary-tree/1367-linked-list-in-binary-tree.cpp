/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public: bool f=false;
    bool check(TreeNode* root,ListNode* head)
    {
        if(head==NULL) return true;
        if(root==NULL) return false;
        if(root->val!=head->val) return false;
        
        return check(root->left,head->next) ||check(root->right,head->next);
    }
    void solve(TreeNode* root,ListNode* head)
    {
        if(root==NULL)
         return ;
        
        if(root->val==head->val)
        {
            if(check(root,head))
            {
                f=true;
                return;
            }
        }
        solve(root->left,head);
        solve(root->right,head);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        solve(root,head);
        return f;
    }
};