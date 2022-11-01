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
    bool isCompleteTree(TreeNode* root) {
      if(root == NULL ) return {};
        // vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty() && q.front() != NULL){
            TreeNode *node = q.front(); q.pop();
            q.push(node->left);
            q.push(node->right);
        }
        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();
            if(node != NULL){
                return false;
            }
        }
        // return ans;   
        return 1;
    }
};