class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;
        
        for(auto& desc : descriptions) {
            int parent = desc[0];
            int child = desc[1];
            int isLeft = desc[2];
            
            if(nodes.find(parent) == nodes.end()) {
                nodes[parent] = new TreeNode(parent);
            }
            
            if(nodes.find(child) == nodes.end()) {
                nodes[child] = new TreeNode(child);
            }
            
            if(isLeft == 1) {
                nodes[parent]->left = nodes[child];
            } else {
                nodes[parent]->right = nodes[child];
            }
            
            children.insert(child);
        }
        
        for(auto& [value, node] : nodes) {
            if(children.find(value) == children.end()) {
                return node;  
            }
        }
        
        return nullptr;
    }
};