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
pair<int, TreeNode* >  solve(TreeNode * root){
        if(root == NULL ) return { 0, NULL};

        auto leftans = solve(root->left);
        auto rightans = solve(root->right);

        int leftlevel = leftans.first;
        int rightlevel = rightans.first ;

        TreeNode* leftparent = leftans.second;
        TreeNode* rightparent = rightans.second;

        if(leftlevel == rightlevel)  return {leftlevel+1,root};

        if(leftlevel > rightlevel ) return {leftlevel+1 , leftparent };
        else return {rightlevel+1, rightparent};

    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return solve(root).second;
    }
};