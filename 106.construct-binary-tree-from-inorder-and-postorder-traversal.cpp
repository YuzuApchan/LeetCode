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
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
  public:
      unordered_map<int, int> val2Idx;
      TreeNode *buildTree(vector<int> &postorder, vector<int> &inorder)
      {
          int len = inorder.size();
          for (int i = 0; i < len; i++)
          {
              val2Idx[inorder[i]] = i;
          }
          return build(postorder, 0, inorder, 0, len);
      }

      TreeNode *build(vector<int> &postorder, int pStart,
                      vector<int> &inorder, int iStart, int len)
      {
          if (0 == len)
          {
              return nullptr;
          }
          int rootVal = postorder[pStart + len - 1];
        //   if (1 == len)
        //   {
        //       return new TreeNode(rootVal, nullptr, nullptr);
        //   }
          int iRootIdx = val2Idx[rootVal];
          int leftTreeSize = iRootIdx - iStart;
          TreeNode *leftTree = build(postorder, pStart, inorder, iStart, leftTreeSize);
          TreeNode *rightTree = build(postorder, pStart + leftTreeSize, inorder, iRootIdx + 1, len - leftTreeSize - 1);
          return new TreeNode(rootVal, leftTree, rightTree);
      }
};

int main(void){
    Solution s;
    vector<int> postorder = {9, 15, 7, 20, 3};
    vector<int> inorder = {9,3,15,20,7};
    // vector<int> postorder = {-1};
    // vector<int> inorder = {-1};
    // vector<int> preorder = {1,2};
    // vector<int> inorder = {2,1};
    s.buildTree(postorder, inorder);
}