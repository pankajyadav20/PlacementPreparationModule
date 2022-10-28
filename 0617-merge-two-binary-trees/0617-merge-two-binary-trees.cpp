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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
         if(!root1 && !root2) return NULL;
        if(!root1) return root2;
        if(!root2) return root1;
        queue< pair< TreeNode * , TreeNode *>> q;
        q.push({root1 , root2});
        // TreeNode *newTree = new TreeNode();
        while(!q.empty()){
            
            TreeNode *node1 = q.front().first;
            TreeNode *node2 = q.front().second;
            q.pop();
            node1->val += node2->val;
           
            if(node1->left != NULL && node2->left != NULL){
                q.push({node1->left , node2->left});
            }
            else if(node2->left != NULL){
                node1->left = node2->left;
            }
            
            if(node1->right != NULL && node2->right != NULL){
                q.push({node1->right, node2->right});
            }else if(node2->right != NULL){
                node1->right =  node2->right;
             }      
        }
        return root1;
    }
};




