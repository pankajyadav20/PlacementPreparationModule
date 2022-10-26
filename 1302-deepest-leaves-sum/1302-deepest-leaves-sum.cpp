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
public:
    int len(TreeNode *root){
        if(root == NULL ) return 0;
        return 1 + max ( len(root->left) , len(root->right) ) ;
    }
    
    int fun(TreeNode *root, int h , int curH){
        
        if(root == NULL){
            return 0;
        }
        if(curH == h - 1){
            return root->val; 
        }
        return fun(root->left , h , curH + 1) + fun(root->right,  h , curH + 1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int h = len(root);
        return fun(root , h ,0);
    }
};