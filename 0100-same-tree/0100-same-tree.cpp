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
   /* void inorder(TreeNode*root,vector<int>&ans){
        if(root == nullptr){
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }*/
    bool isSameTree(TreeNode* p, TreeNode* q) {
       /* vector<int> v1;
        vector<int> v2;
        inorder(p,v1);
        inorder(q,v2);
        
    int n = v1.size();
    int m = v2.size();
    if(n!=m){return false;}
    for(int i =0;i<n;i++){
        if(v1[i] != v2[i]){
            return false;
        }
    }
    return true;*/
    if(p == nullptr && q == nullptr){ return true;}
    if(p == nullptr || q == nullptr){ return false ;}
    if(p->val != q->val) { return false;}
    return (isSameTree(p->left,q->left) && (isSameTree(p->right,q->right)));
    }
};