/**
 * https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/6/linked-list/46/
 * 给定一个链表，判断链表中是否有环。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
示例 1：

输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。
 */

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return false;
    ListNode *low;
    ListNode *fast;
    low = head;
    fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        low = low->next;
        fast = fast->next->next;
        if(low==fast){
            return true;
        }
    }
    return false;
}