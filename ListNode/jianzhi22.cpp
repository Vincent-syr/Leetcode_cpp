#include <iostream>
#include "ListNode.h"
using namespace std;

/* https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/

剑指 Offer 22. 链表中倒数第k个节点
输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。例如，一个链表有6个节点，从头节点开始，它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个节点是值为4的节点。

示例：

给定一个链表: 1->2->3->4->5, 和 k = 2.

返回链表 4->5.

特殊情况：
    head为空指针；
    k大于链表的长度；
    输入的参数k为0； 鲁棒性也是很重要的~
 */

// 双指针法，p2比p1 慢k次；
    ListNode* getKthFromEndMethod1(ListNode* head, int k) {
        // if(k==0)   error;
        if(head==nullptr || head->next==nullptr)   return head;
        auto p1 = head, p2 = head;

        for(int i=0; i<k; i++){
            p1 = p1->next;
        }
        while(p1 != nullptr){
            p1 = p1->next;
            p2 = p2->next;
        }
        
        return p2;              
    }


