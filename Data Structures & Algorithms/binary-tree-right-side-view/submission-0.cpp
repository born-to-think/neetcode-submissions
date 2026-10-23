// https://leetcode.com/problems/binary-tree-right-side-view/

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
		
		if(root){
			queue<TreeNode *> q;
			
            int n=1;
			q.push(root);

			while(n){
				ans.push_back(q.back()->val);

				int temp_next_n = 0;
				for(int k=0;k<n;k++){
					TreeNode *curr = q.front();q.pop();
					if(curr->left){q.push(curr->left);temp_next_n++;}
					if(curr->right){q.push(curr->right);temp_next_n++;}
				}
				n = temp_next_n;

			}
		}
		return ans;
    }
};