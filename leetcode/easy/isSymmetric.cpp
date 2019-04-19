/**
 * https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/7/trees/49/
 * 
 * 对称二叉树
给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3

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

bool mySymmetric(TreeNode *leftChild, TreeNode *rightChild)
{
    if (leftChild == NULL && rightChild == NULL)
        return true;
    else if (leftChild && !rightChild || !leftChild && rightChild)
    {
        return false;
    }
    else
    {
        if (mySymmetric(leftChild->left, rightChild->right) && mySymmetric(leftChild->right, rightChild->left) && leftChild->val == rightChild->val)
            return true;
        else return false;
    }
}
bool isSymmetric(TreeNode *root)
{
    if (root == NULL)
        return true;
    return mySymmetric(root->left, root->right);
}