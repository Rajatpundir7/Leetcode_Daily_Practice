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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*>q;
       // queue<int>q2;
        vector<int>ans;

        if(root == NULL ) return ans;

        q.push(root);
       // q2.push(1);
        while(!q.empty()){

            int sz = q.size();
            int mx =INT_MIN;
            while(sz--){
                TreeNode* node = q.front();
                //int side = q2.front();
                q.pop(); //q2.pop();
                mx = max(mx,node->val);
                
                if(node->right != NULL) { 
                    q.push(node->right);
                   // q2.push(1);
                }
                if(node->left != NULL)  
                { 
                    q.push(node->left);
                   // q2.push(0);
                }
            }
            ans.push_back(mx);
        }
        return ans;
    }
};