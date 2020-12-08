/*
 * @Author: Vincent-syr
 * @Date: 2020-11-28 13:13:51
 * @LastEditTime: 2020-12-07 22:04:33
 * @Description: file content
 */
#include <iostream>
#include "ListNode.h"
 
 /* 
 https://leetcode-cn.com/problems/linked-list-cycle-ii/
 142. 环形链表 II   middle
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意，pos 仅仅是用于标识环的情况，并不会作为参数传递到函数中。

说明：不允许修改给定的链表。

进阶：

你是否可以使用 O(1) 空间解决此题？
 

示例 1：



输入：head = [3,2,0,-4], pos = 1
输出：返回索引为 1 的链表节点
解释：链表中有一个环，其尾部连接到第二个节点。
示例 2：



输入：head = [1,2], pos = 0
输出：返回索引为 0 的链表节点
解释：链表中有一个环，其尾部连接到第一个节点。
示例 3：



输入：head = [1], pos = -1
输出：返回 null
解释：链表中没有环。
 

提示：

链表中节点的数目范围在范围 [0, 104] 内
-105 <= Node.val <= 105
pos 的值为 -1 或者链表中的一个有效索引


解法：
    双指针算法中的情况2：“已知链表中含有环，返回这个环的起始位置"；
    先让快慢指针相遇，相遇后让其中任一个指针指向头节点，
    然后让它俩以相同速度前进，再次相遇时所在的节点位置就是环开始的位置
 时间复杂度：O(N); 空间O(1);


空间O(N)的HaseSet方法：
    我们遍历链表中的每个节点，并将它记录下来；一旦遇到了此前遍历过的节点，就可以判定链表中存在环。借助哈希表可以很方便地实现。


 */


    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        bool flag = false;
        // 相遇点以及是否有环
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow)    break;
        }
        // 无环
        if(fast == nullptr || fast->next == nullptr)    return nullptr;
        // 有环
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }