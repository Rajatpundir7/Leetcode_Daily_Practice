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
     /*bool hasPathSum(TreeNode* root, int targetsum) {
        if( root == NULL ){
            return false;
        }

        targetsum -= root->val;

        if(root->left == NULL &&  root->right  == NULL){
            return targetsum ==0 ;
        }

        return hasPathSum(root->left , targetsum) || hasPathSum(root->right , targetsum);
    }*/
    void dfs(TreeNode* root , int targetsum , vector<int>&path , vector<vector<int>>&ans){
        if(root == NULL){
            return  ;
        }
        targetsum -= root->val;
        path.push_back(root->val);

        if(root->left == NULL  && root->right == NULL ){
        if(targetsum == 0) {
            ans.push_back(path);
        }
        }
        else{
            dfs(root->left , targetsum , path , ans);
            dfs(root->right , targetsum , path , ans );
        }
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetsum) {
        vector<vector<int>>ans;
        vector<int>path;

        dfs(root,targetsum , path, ans);
        //if( pathSum(root->left , targetsum)|| pathSum(root->right, targetsum)){
            return ans;
        //}
    }
};