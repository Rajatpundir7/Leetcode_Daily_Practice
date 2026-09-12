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
int ans = 0;
    void solve(TreeNode* root , int targetsum , unordered_map<long long, int>&mp, long long sum ){

        if(root == NULL ){
            return ;
        }
         sum += root->val;

         

         if(mp.count(sum- targetsum)){
           ans += mp[sum - targetsum];
         }
         mp[sum]++;
      //  if(root->left != NULL ){
         solve(root->left , targetsum , mp ,sum);
      //  }
        //if(root->right != NULL){
            solve(root->right , targetsum, mp, sum);
      //  }
        mp[sum]--;
    }
    int pathSum(TreeNode* root, int targetsum) {
        unordered_map<long long,int>mp;
        mp[0] =1;
        long long sum =0;
        solve(root,targetsum , mp,sum);
        return ans;
    }
};