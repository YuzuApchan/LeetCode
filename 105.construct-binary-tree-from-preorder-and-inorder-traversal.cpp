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
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}
class Solution {
public:
    unordered_map<int, int> val2Idx;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();
        for(int i = 0; i < len; i++){
            val2Idx[preorder[i]] = i;
        }
        return build(preorder, 0, inorder, 0, len);
    }
    TreeNode *build(vector<int>& preorder, int pStart,
                    vector<int>& inorder, int iStart, int len){
                        int rootVal = preorder[pStart];
                        int iRootIdx =  val2Idx[rootVal];
                        int leftTreeSize = iRootIdx - iStart;
                        TreeNode *leftTree = build(preorder, pStart + 1, inorder, iStart, leftTreeSize);
                        TreeNode *rightTree = build(preorder, pStart + leftTreeSize, inorder, iRootIdx + 1, len - leftTreeSize - 1);
                        return new TreeNode(rootVal, leftTree, rightTree);
                    }
};

int main(void){
    Solution s;
    vector<int> preorder = [3,9,20,15,7];
    vector<int> inorder = [9,3,15,20,7];
    s.buildTree(preorder, inorder);
}