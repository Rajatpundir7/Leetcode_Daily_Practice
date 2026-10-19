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

    bool solve(TreeNode* root , TreeNode* subroot){
        if(root == NULL && subroot == NULL){
            return true ;
        }
        if(root == NULL || subroot == NULL) return false;

        if(root->val != subroot->val) return  false;

        return (solve(root->left , subroot->left) && solve(root->right,subroot->right));
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // given -  (tree , subtree) - my task is to check , subtree values are exist in tree or not 
        // so my approch for this question 
        // 1st start level order traversal 
        // if the value of tree == value of sub tree 
        queue<TreeNode*>q;
        q.push(root);
        bool ans = false;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode* node = q.front();
                q.pop();

                if(node->val == subRoot->val){
                  ans =   solve(node , subRoot);
                  if(ans == true) return true ;
                   

                }
                if(node->left != NULL ) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
            }
        }
        return ans ;

    }
};