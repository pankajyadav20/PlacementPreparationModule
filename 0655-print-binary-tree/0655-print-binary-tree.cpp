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
    private:
    int h(TreeNode *root){
            if(root == NULL) return -1;
        return 1 + max(  h(root->left) , h (root->right));
    }
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int ht = h(root);        
       int n = ht + 1;
        int m = pow(2, ht+1) - 1;
        vector<vector<string>> ans(n , vector<string>(m,""));
    // cout<<ht<<endl;
        queue< pair < TreeNode*  , pair<int,int>> > q;
        q.push({  root , { 0 ,(int)((m-1)/2) } });
       // cout<< ( m);
           TreeNode *node = q.front().first;  
                int row = q.front().second.first;
                int col = q.front().second.second;
        
        // cout<<node->val<<" "<<row<<" "<<col;
        while(!q.empty()){
            
                TreeNode *node = q.front().first;  
                int row = q.front().second.first;
                int col = q.front().second.second;
                q.pop();
                // if(node != NULL)
                ans[row][col] = to_string(node->val);   
                
                int temp = pow(2 , ht - row - 1);
                // left
                if(node ->left != NULL)
                q.push( { node->left ,{ row + 1 , col - temp}  } );
                //right
                if(node->right != NULL)
                q.push({ node->right, { row + 1 , col  + temp}  });
        }
        return ans;
        
    }
};




