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
    int widthOfBinaryTree(TreeNode* root) {
    
        int maxi = 1;
        queue< pair < TreeNode* , int > > q;
        q.push({root , 1});
        
        while(!q.empty()){
                int size = q.size();
            int startIdx = q.front().second , endIdx = q.back().second;
            maxi = max(maxi , endIdx -  startIdx + 1);
            while(size--){
                  pair<TreeNode*, int> p = q.front();
                    int idx = p.second - startIdx;
                    q.pop();
                    if(p.first->left != NULL)
                        q.push({p.first->left, (long long)2 * idx + 1});

                    if(p.first->right != NULL)
                        q.push({p.first->right, (long long) 2 * idx + 2});
            }
            
        }
        return maxi;
    }
};