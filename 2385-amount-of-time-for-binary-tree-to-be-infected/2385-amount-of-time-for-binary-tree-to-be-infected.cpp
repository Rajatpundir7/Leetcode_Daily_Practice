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
     TreeNode* findtarget(TreeNode*root, int start){
        if(root == NULL ) return NULL;

        if(root->val == start) return root;
        TreeNode* left = findtarget(root->left, start);
        if(left != NULL) return left;

        return findtarget(root->right , start);

     }
    int amountOfTime(TreeNode* root, int start) {
         unordered_map<TreeNode* , TreeNode*>parent;
        makeparent(root,parent );
        TreeNode* target = findtarget(root,start);
        unordered_map<TreeNode* , bool >visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target] = true;

        int curr_level = 0;
        while(!q.empty()){
            int sz = q.size();
    //if(curr_level++ == k) break;

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
            curr_level++;
        }
        /*vector<int>result;
        while(!q.empty()){
           
            result.push_back(q.front()->val);
            q.pop();
        }
        return result;*/
        return curr_level-1;
    }
};