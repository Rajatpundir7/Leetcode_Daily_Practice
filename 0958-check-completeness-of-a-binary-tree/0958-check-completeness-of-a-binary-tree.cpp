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
        queue<TreeNode*>q;
        q.push(root);
        int flag =0 ;
        while(!q.empty()){
            int size = q.size();
            
            while(size--){
                TreeNode* node = q.front();
                q.pop();
               if(flag  == 1 && node->left != NULL ) return false;
               if(flag  == 1 && node->right != NULL ) return false;
                if(node->left == NULL && node->right != NULL) return false;
                if(node->left != NULL ) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
               /* if(node->left != NULL && node->right == NULL) { flag = 1;}
                else if (node->left != NULL && node->right == NULL) {
                    flag = 1;
                }*/
                if (node->right == NULL) {
    flag = 1;
}
            }
        }
        return true;
    }
};