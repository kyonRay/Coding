/**
 * https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/6/linked-list/44/
 * 合并两个有序链表
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
 */

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    ListNode *newList = new ListNode(0);
    ListNode *temp = newList;
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->val > l2->val)
        {
            newList->next = l2;
            l2 = l2->next;
            newList = newList->next;
        }
        else
        {
            newList->next = l1;
            l1 = l1->next;
            newList = newList->next;
        }
    }
    if (l1 == NULL)
    {
        newList->next = l2;
    }
    else if (l2 == NULL)
    {
        newList->next = l1;
    }
    return temp->next;
}
