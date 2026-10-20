/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      /*  vector<int>path1;
        vector<int>path2;
        TreeNode*p1 = root;*/
       /* while(root != NULL){
           path1.push_back(p1->val);
            if(p1->val > p->val)  p1= p1->left;
            if(p1->val < p->val) p1 =p1->right ;
            else  break;

        }*/
       /* while(p2 != NULL){
            path1.push_back(p1->val);
            if(p2->val > q->val)  p2= p2->left;
            if(p2->val < q->val) p2 =p2->right ;
            else  break;

        }*/
        
        while(root != NULL){
            if(root == p || root == q) return root;
            if( p->val > root->val && q->val > root->val ) root = root->right;
            else if(p->val < root->val && q->val < root->val) root= root->left;
            else return root;
        }
        return NULL;
    }
};