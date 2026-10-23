// https://leetcode.com/problems/count-good-nodes-in-binary-tree/

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

	void compute(TreeNode *curr, int max_from_root, int& n_good){
		if(curr){
			if(max_from_root<=curr->val){
				max_from_root = curr->val;
				n_good++;
			}
			compute(curr->left,max_from_root,n_good);
			compute(curr->right,max_from_root,n_good);
		}
	}

    int goodNodes(TreeNode* root) {
        int n_good = 0;
        int max_from_root = -1e4 -1;
        compute(root,max_from_root,n_good);
        return n_good;
    }
};

