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
    vector<int> reverseee(vector<int>&arr){
        int n = arr.size();
        int i = 0 , j =n-1;
        while(i<j){
            swap(arr[i],arr[j]);
            i++ , j--;
        }
        return arr;

    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        if(root == NULL ) return ans ;
        q.push(root);
        int flag =0 ;
        while(!q.empty()){
            
            int sz  = q.size();

            vector<int>level;
            
            while(sz--){
                TreeNode* node = q.front();
             q.pop();

             


             level.push_back(node->val);

             if(node->left) q.push(node->left);
             if(node->right) q.push(node->right);

            }
            if(flag){
                //reverse(level.front(),level.end());
                reverseee(level);
             }
             ans.push_back(level);
             
             if(flag == 0) flag =1;
             else flag =0;
        }
        return ans ;
    }
};