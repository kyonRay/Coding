/**
 * https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/6/linked-list/45/
 * 回文链表
请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
 */

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode *head)
{
    if (head == NULL||head->next == NULL)
        return true;
    int count = 1;
    ListNode *dump = new ListNode(0);
    dump->next = head;
    ListNode *temp1 = head;
    ListNode *temp2 = head->next;
    ListNode *temp3 = head->next->next;
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
        count++;
    }
    temp1 = dump->next;
    for (int i = 1; i < count / 2; i++)
    {
        temp3 = temp2->next;
        temp2->next = temp1;
        temp1 = temp2;
        temp2 = temp3;
    }
    head->next = temp2;
    dump->next = temp1;
    temp2 = dump->next;
    for (int i = 0; i < count / 2; i++)
    {
        temp1 = temp1->next;
    }
    if (count & 1)
        temp1 = temp1->next;
    while (temp1 != NULL)
    {
        if (temp1->val == temp2->val)
        {
            temp2 = temp2->next;
            temp1 = temp1->next;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    cout << isPalindrome(l1) << endl;
    return 0;
}