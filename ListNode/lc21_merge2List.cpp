#include <iostream>
#include "ListNode.h"
using namespace std;

/*
 * @Author: Vincent-syr
 * @Date: 2020-12-07 22:10:17
 * @LastEditTime: 2020-12-07 22:26:04
 * @Description: file content

https://leetcode-cn.com/problems/merge-two-sorted-lists/
21. 合并两个有序链表    easy
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

解法：
    我们可以用迭代的方法来实现上述算法。当 l1 和 l2 都不是空链表时，
    判断 l1 和 l2 哪一个链表的头节点的值更小，将较小值的节点添加到结果里，当一个节点被添加到结果里之后，
    将对应链表中的节点向后移一位。
复杂度：
    时间O(N)
    空间O(1)
 */



    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dump = new ListNode(0);
        auto cur = dump;
        while(l1 && l2){
            if(l1->val > l2->val){
                cur->next = new ListNode(l2->val);
                l2 = l2->next;
                cur = cur->next;
            }
            else{
                cur->next = new ListNode(l1->val);
                l1 = l1->next;
                cur = cur->next;
            }
        }
        auto p = l1? l1: l2;         //l1不为空，则等于l1,否则l2；如果都为空，就是nullptr
        cur->next = p;
        return dump->next;
        
    }