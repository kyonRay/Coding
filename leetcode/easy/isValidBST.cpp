/**
 * https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/7/trees/48/
 * 验证二叉搜索树
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
示例 1:

输入:
    2
   / \
  1   3
输出: true
 * 
 */

#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *pre;
bool isValidBST(TreeNode *root)
{
    if (root == NULL)
        return true;
    if (!isValidBST(root->left))
        return false;
    if (pre && pre->val >= root->val)
        return false;
    pre = root;
    if (!isValidBST(root->right))
        return false;
    return true;
}

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(1);
    cout << isValidBST(root) << endl;
    return 0;
}
