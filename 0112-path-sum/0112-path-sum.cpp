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
    int sum =0 , flag =0 ;
    void inorder(TreeNode* root, int targetsum){
        if(root == NULL){
            return ;
        }
        sum += root->val;
        
        if(root->left == NULL && root->right == NULL){
              if(sum == targetsum ){
                flag =1;
                 
            }
        }
        
        inorder(root->left,targetsum);
        
        inorder(root->right, targetsum);
        sum -= root->val;

    }
    bool hasPathSum(TreeNode* root, int targetsum) {
        inorder(root,targetsum);
        if(root == NULL ) return false;
        if(flag == 1) return true ;
        else return false;
    }
};