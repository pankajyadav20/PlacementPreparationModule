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
    void dfs(TreeNode *root , TreeNode *parent , TreeNode *grandParent , int &ans){
        if(root == NULL){
            return ;
        }
        if(grandParent != NULL && grandParent->val % 2 == 0){
            ans += root->val;
        }
        dfs(root->left , root,  parent , ans);
        dfs(root->right , root , parent , ans);
    }
    int sumEvenGrandparent(TreeNode* root) {
        int ans = 0;
        dfs(root , NULL , NULL , ans);
        return ans;
    }
};