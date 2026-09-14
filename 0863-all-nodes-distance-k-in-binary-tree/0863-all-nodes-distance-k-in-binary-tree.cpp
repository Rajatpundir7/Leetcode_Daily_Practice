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
     void makeparent(TreeNode* root , unordered_map<TreeNode* , TreeNode*>&parent ){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*  current =  q.front();
            q.pop();
            if(current->left != NULL ) {
                parent[current->left] = current;
                q.push(current->left);
            }
            if(current->right != NULL){
                parent[current->right] = current;
                q.push(current->right);
            }
        }
     }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*>parent;
        makeparent(root,parent );

        unordered_map<TreeNode* , bool >visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target] = true;

        int curr_level = 0;
        while(!q.empty()){
            int sz = q.size();
            if(curr_level++ == k) break;

            while(sz--){
                TreeNode* current = q.front();
                q.pop();

                if(current->left != NULL && !visited[current->left]){
                    q.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right != NULL && !visited[current->right]){
                    q.push(current->right);
                    visited[current->right] = true;
                }
                if(parent[current] != NULL && !visited[parent[current]]){
                    q.push(parent[current]);
                    visited[parent[current]] = true;
                }
            }
            //curr_level++;
        }
        vector<int>result;
        while(!q.empty()){
           
            result.push_back(q.front()->val);
            q.pop();
        }
        return result;
    }
};