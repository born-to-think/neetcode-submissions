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
    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        deque<TreeNode*> dq;
        int level = 0;
        dq.push_back(root);

        while(!dq.empty()){
            for(int i = 0;i<dq.size();i++){
                TreeNode* node = dq.front();dq.pop_front();
                if(node->left)dq.push_back(node->left);
                if(node->right)dq.push_back(node->right);
            }
            level++;
        }
        return level;
    }
};
