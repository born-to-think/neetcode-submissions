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

    //<md,dia>
    pair<int,int> compute(TreeNode *node){
        if(node->left == nullptr && node->right == nullptr) return{0,0};
        if(node->left != nullptr && node->right != nullptr){
            pair<int,int> p1 = compute(node->left);
            pair<int,int> p2 = compute(node->right);
            
            int md = 1 + max(p1.first,p2.first);
            int it = max( max(2 + p1.first + p2.first,   p1.second), p2.second );
            return {md, it};
        }

        TreeNode *child = (node->left != nullptr) ? node->left : node->right;
        pair<int,int> c = compute(child);
        return { 1+ c.first, c.second};
        

    }

    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int> ans = compute(root);
        
        return max(ans.second,ans.first);
    }
};
