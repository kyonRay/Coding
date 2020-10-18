/**
 * 
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
#include <iostream>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
  if (l1 == nullptr)
    return l2;
  if (l2 == nullptr)
    return l1;
  ListNode *lHead = l1, *pre1;
  int flag = 0;
  int temp;
  while (l1 && l2)
  {
    temp = l1->val;
    l1->val = (l1->val + l2->val + flag) % 10;
    flag = (temp + l2->val + flag) / 10;
    pre1 = l1;
    l1 = l1->next;
    l2 = l2->next;
  }
  if (l1)
  {
    while (l1)
    {
      temp = l1->val;
      l1->val = (l1->val + flag) % 10;
      flag = (temp + flag) / 10;
      l1 = l1->next;
    }
  }
  if (l2)
  {
    pre1->next = l2;
    while (l2)
    {
      temp = l2->val;
      l2->val = (l2->val + flag) % 10;
      flag = (temp + flag) / 10;
      l2 = l2->next;
    }
  }
  if (flag)
  {
    while (pre1->next)
    {
      pre1 = pre1->next;
    }
    pre1->next = new ListNode(1);
  }
  return lHead;
}
int main(int argc, char const *argv[])
{
  ListNode *l1 = new ListNode(3);
  l1->next = new ListNode(7);
  ListNode *l2 = new ListNode(9);
  l2->next = new ListNode(2);

  ListNode *l3 = addTwoNumbers(l1, l2);
  while (l3)
  {
    cout << l3->val << endl;
    l3 = l3->next;
  }
  delete l1;
  delete l2;
  return 0;
}
