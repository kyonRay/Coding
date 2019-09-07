/**
 * 这是个二叉树的常见方法的合集
 * 
 */

#include <iostream>
#include <queue>
#include <stack>
#include <list>
#include <array>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 二叉树的最大深度
int maxDepth(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return max(left, right) + 1;
}

// 二叉树的最小深度
int minDepth(TreeNode *root)
{
    if (root == nullptr)
    {
        return INT_MAX;
    }
    if (root->left == nullptr && root->right == nullptr)
        return 1;
    return min(minDepth(root->left), minDepth(root->right)) + 1;
}

// 二叉树节点个数
int numsOfTree(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    return numsOfTree(root->left) + numsOfTree(root->right) + 1;
}

// 二叉树中叶子的个数
int leafOfTree(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    if (root->left == nullptr && root->right == nullptr)
        return 1;
    return leafOfTree(root->left) + leafOfTree(root->right);
}

// 二叉树中第k层节点的个数
int numsOfKlevelTree(TreeNode *root, int k)
{
    if (root == nullptr || k < 0)
    {
        return 0;
    }
    if (k == 1)
        return 1;
    return numsOfKlevelTree(root->left, k - 1) + numsOfKlevelTree(root->right, k - 1);
}

// 二叉树是否是平衡二叉树
namespace BalancedTree
{
int balancedDepth(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int left = balancedDepth(root->left);
    int right = balancedDepth(root->right);
    if (left == -1 || right == -1 || abs(left - right) > 1)
        return -1;
    return max(left, right) + 1;
}
bool isBalancedTree(TreeNode *root)
{
    return balancedDepth(root) != -1;
}
} // namespace BalancedTree

// 判断二叉树是否是完全二叉树
bool isCompleteTree(TreeNode *root)
{
    if (root == nullptr)
        return true;
    queue<TreeNode *> q;
    q.push(root);
    bool flag = true;
    while (!q.empty())
    {
        TreeNode *currentNode = q.front();
        q.pop();
        if (!flag)
        {
            if (currentNode->left != nullptr && currentNode->right != nullptr)
            {
                return false;
            }
        }
        if (currentNode->left != nullptr && currentNode->right != nullptr)
        {
            q.push(currentNode->left);
            q.push(currentNode->right);
        }
        else if (currentNode->right == nullptr && currentNode->left != nullptr)
        {
            q.push(currentNode->left);
            flag = false;
        }
        else if (currentNode->left == nullptr && currentNode->right != nullptr)
            return false;
        else
        {
            flag = true;
        }
    }
    return flag;
}

// 两个二叉树是否相同
bool isSameTree(TreeNode *t1, TreeNode *t2)
{
    if (t1 == nullptr && t2 == nullptr)
        return true;
    else if (t1 == nullptr || t2 == nullptr)
        return false;
    bool left = isSameTree(t1->left, t2->left);
    bool right = isSameTree(t1->right, t2->right);
    return (t1->val == t2->val) && left && right;
}

// 两个二叉树是否互为镜像
bool isMirrorTree(TreeNode *t1, TreeNode *t2)
{
    if (t1 == nullptr && t2 == nullptr)
    {
        return true;
    }
    else if (t1 == nullptr || t2 == nullptr)
        return false;
    if (t1->val != t2->val)
        return false;
    return isMirrorTree(t1->left, t2->right) && isMirrorTree(t1->right, t2->left);
}

// 翻转二叉树
TreeNode *mirrorTree(TreeNode *root)
{
    if (root == nullptr)
        return root;
    root->left = mirrorTree(root->right);
    root->right = mirrorTree(root->left);
    return root;
}

// 求两个树节点的最低公共祖先节点
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr || root == p || root == q)
        return root;
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if (left == nullptr && right != nullptr)
        return right;
    else if (left != nullptr && right == nullptr)
        return left;
    else if (left != nullptr && right != nullptr)
        return root;
    // return left == nullptr ? right : (right == nullptr ? left : root);
}

// 二叉树的前序遍历 根左右
namespace preOrder
{
list<int> treeList;
// 递归方法
void preOrderRecursive(TreeNode *root)
{
    if (root == nullptr)
        return;
    treeList.push_back(root->val);
    preOrderRecursive(root->left);
    preOrderRecursive(root->right);
}
// 迭代方法
void preOrderIterative(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    stack<TreeNode *> s;
    s.push(root);
    while (!s.empty())
    {
        TreeNode *tempNode = s.top();
        s.pop();
        treeList.push_back(tempNode->val);
        if (tempNode->right != nullptr)
            s.push(tempNode->right);
        if (tempNode->left != nullptr)
            s.push(tempNode->left);
    }
}

} // namespace preOrder

// 中序遍历 左根右
namespace inOrder
{
list<int> treeList;
// 递归方法
void inOrderRecursive(TreeNode *root)
{
    if (root == nullptr)
        return;
    inOrderRecursive(root->left);
    treeList.push_back(root->val);
    inOrderRecursive(root->right);
}
// 迭代方法
void inOrderIterative(TreeNode *root)
{
    if (root == nullptr)
        return;
    stack<TreeNode *> s;
    TreeNode *currentNode = root;
    while (!s.empty() || currentNode != nullptr)
    {
        // 将当前节点的所有左子树都压入栈
        while (currentNode != nullptr)
        {
            s.push(currentNode);
            currentNode = currentNode->left;
        }
        currentNode = s.top();
        s.pop();
        treeList.push_back(currentNode->val);
        currentNode = currentNode->right;
    }
}
} // namespace inOrder

// 后序遍历 左右根
namespace postOrder
{
list<int> treeList;

// 递归方法
void postOrderRecursive(TreeNode *root)
{
    if (root == nullptr)
        return;
    postOrderRecursive(root->left);
    postOrderRecursive(root->right);
    treeList.push_back(root->val);
}

// 迭代方法

void postOrderIterative(TreeNode *root)
{
    if (root == nullptr)
        return;
    stack<TreeNode *> s;
    s.push(root);
    while (!s.empty())
    {
        TreeNode *currentNode = s.top();
        s.pop();
        if (currentNode->left != nullptr)
            s.push(currentNode->left);
        if (currentNode->right != nullptr)
            s.push(currentNode->right);
        // 从开头插入
        treeList.push_front(currentNode->val);
    }
}
} // namespace postOrder

// 前序遍历和后序遍历构造二叉树
namespace buildTreeByPreAndInOrder
{

TreeNode *buildingTree(vector<int> &preOrder, int preBegin, int preEnd, vector<int> &inOrder, int inBegin, int inEnd)
{
    if (inBegin > inEnd)
        return nullptr;
    TreeNode *root = new TreeNode(preOrder[preBegin]);
    int pos = *find(inOrder.begin() + inBegin, inOrder.begin() + inEnd, root->val);

    root->left = buildingTree(preOrder, preBegin + 1, preBegin + pos - inBegin, inOrder, inBegin, pos - 1);
    root->right = buildingTree(preOrder, pos - inEnd + preEnd + 1, preEnd, inOrder, pos + 1, inEnd);
    return root;
}
TreeNode *buildTree(vector<int> &preOrder, vector<int> &inOrder)
{
    if (preOrder.size() != inOrder.size())
        return nullptr;
    return buildingTree(preOrder, 0, preOrder.size() - 1, inOrder, 0, inOrder.size() - 1);
}
} // namespace buildTreeByPreAndInOrder
