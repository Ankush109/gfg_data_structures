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
   int h(TreeNode *root){
    if(root==NULL) 
        return 0;
   
    return max(h(root->left),h(root->right))+1;
    
}
 int findBottomLeftValue(TreeNode* root) {
        if(root->left==NULL && root->right==NULL)
            return root->val;
        int l=h(root->left);
        int r=h(root->right);
        if(l<r)
        return findBottomLeftValue(root->right);
         else
        return findBottomLeftValue(root->left);
         
        
    }
};
