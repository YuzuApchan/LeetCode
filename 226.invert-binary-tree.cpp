class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        traverse(root);
        return root;
    }
    void traverse(TreeNode *node){
        if(nullptr == node){
            return;
        }
        TreeNode *temp = node->left;
        node->left = node->right;
        node->right = temp;
        traverse(node->left);
        traverse(node->right);
    }
};