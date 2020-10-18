/**
 * https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/7/trees/51/
 * 将有序数组转换为二叉搜索树
将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5
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

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    if (nums.size() == 0)
        return nullptr;
    if (nums.size() == 1)
    {
        return new TreeNode(nums[0]);
    }
    int mid = nums.size() / 2;
    int end = nums.size();
    vector<int> leftNums;
    vector<int> rightNums;
    TreeNode *root = new TreeNode(nums[mid]);

    leftNums.assign(nums.begin(), nums.begin() + mid);
    rightNums.assign(nums.begin() + mid + 1, nums.begin() + end);

    root->left = sortedArrayToBST(leftNums);
    root->right = sortedArrayToBST(rightNums);

    return root;
}