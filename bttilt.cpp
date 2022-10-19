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
    int dfs(TreeNode* root, int &s){
        int l = 0, r = 0;
        if(root->left)
            l = dfs(root->left, s);
        if(root->right)
            r = dfs(root->right, s);
        s += abs(l - r);
        return l + r + root->val;
    }
    int findTilt(TreeNode* root) {
        int s= 0;
        if(root == NULL)
            return s;
        dfs(root, s);
        return s;
    }

    
};
