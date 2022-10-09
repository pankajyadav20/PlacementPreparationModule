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
    void help(vector<int> &inorder , TreeNode *root){
        if(root == NULL){
            return;
        }
        help(inorder ,root->left);
        inorder.push_back(root->val);
        help(inorder , root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        
        vector<int> ans;
        help(ans , root);
        int low = 0, high = ans.size() -1;
        
        while(low < high){
            if(ans[low] + ans[high] == k){
                return 1;
            }  
            if(ans[low] + ans[high] > k){
                high--;
            }   else low++;
        }
        return 0;
    }
};