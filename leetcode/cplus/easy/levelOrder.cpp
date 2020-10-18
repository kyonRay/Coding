/**
 * https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/7/trees/50/
 * 二叉树的层次遍历
给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void pre(TreeNode *root, int depth, vector<vector<int>> &ans)
{
    if (!root)
        return;
    if (depth >= ans.size())
        ans.push_back(vector<int>{});
    ans[depth].push_back(root->val);
    pre(root->left, depth + 1, ans);
    pre(root->right, depth + 1, ans);
}

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    pre(root, 0, ans);
    return ans;
}