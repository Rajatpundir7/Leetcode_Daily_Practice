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
     bool solve(TreeNode*root1,TreeNode* root2){
        if(root1 == NULL && root2 == NULL) return true;
        if(root1 == NULL || root2 == NULL) return false;
        if(root1->val != root2->val) return false;
        if(solve(root1->left,root2->left) && solve(root1->right,root2->right)) return true;
        if(solve(root1->left,root2->right) && solve(root1->right,root2->left)) return true;
        return false;
     }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
       // if(root1 == NULL && root2 == NULL)  return true ;

       /* queue<TreeNode*>q1;
        queue<TreeNode*>q2;
        q1.push(root1);
        q2.push(root2);
        while(!q1.empty()){
            int size = q1.size(); 
            while(size--){
                TreeNode * node1 = q1.front();
                q1.pop();
                TreeNode *node2 = q2.front();
                q2.pop();
                /* 
                1 st check for the -- without flip 
                2nd check without flip 
                if without flip node values are equal then push into queue 
                otherwise return true 
                */
              /*  if(node1->left != NULL &&   node2->left != NULL){
                    
                    if(node1->left->val != node2->left->val) return true;
                    q1.push(node1->left);
                    q2.push(node2->left);

                
                if(node1->right != NULL &&  node2->right != NULL){
                    q1.push(node1->right);
                    q2.push(node2->right);
                    if(node1->right->val != node2->right->val) return true;
                //if(node1->right != NULL) q1.push(node1->right);
                //if(node2->left != NULL) q2.push(node2->left);
            }
        }
        return false;*/
        return solve(root1 ,root2);

    }
};