/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *lca(TreeNode *root , TreeNode *p , TreeNode *q){
        if(root == NULL){
            return root;
        }
        if(root->val == p->val || root->val == q->val){
            return root;               // i am the lca of p and q
        }
        
        TreeNode* left = lca(root->left , p ,q);
        TreeNode *right = lca(root->right , p , q);
        if(left == NULL && right != NULL){
            return right;
        }
        else if(right == NULL && left != NULL){
            return left;
        }if(left == NULL && right == NULL){
            return NULL;
        }
        return root;
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root , p , q);
    }
};












