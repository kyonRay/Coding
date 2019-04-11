/**
 * https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/6/linked-list/42/
 * 删除链表的倒数第N个节点
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
 */

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//单次遍历
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *dumb = new ListNode(0);
    dumb->next = head;              //dumb 指向头结点前一位
    ListNode *front = dumb, *behind = dumb;
    for (int i = 0; i < n; i++)
        front = front->next;
    //front指向最后一个节点
    while (front->next != NULL)
    {
        front = front->next;
        behind = behind->next;
    }
    //此时behind指向倒数第n+1个节点
    //ListNode* temp = behind->next;
    //free(temp);
    behind->next = behind->next->next;
    head = dumb->next;
    delete dumb;
    return head;
}