#include <iostream>
#include "ListNode.h"
using namespace std;

/* 
https://leetcode-cn.com/problems/add-two-numbers/
2. 两数相加
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

关键字：位运算

解答：
    1） 注意低位的进位，用类似数电加法器的carr保存进位；
    2） 最高位如果有进位，则新链表会比原链表多1位；

 */


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto p1 = l1, p2 = l2;
        int carr = 0;   // 进位符号
        ListNode *dumb = new ListNode(0);
        auto pre = dumb;
        // 1. p1 and p2公共长度部分，两部分相加
        while(p1 && p2){
            int val1 = p1->val;
            int val2 = p2->val;
            int val3 = (val1 + val2 + carr) % 10;
            carr = (val1 + val2 + carr) / 10;    // update carr

            auto cur = new ListNode(val3);
            pre->next = cur;

            pre = cur;    // update pre
            p1 = p1->next;     // update p1, p2;
            p2 = p2->next;
        }

        // 2. l1 l2长度不等
        auto p  = p1? p1: p2;
        while(p){
            auto cur = new ListNode((p->val + carr) % 10);
            carr = (p->val + carr) / 10;
            pre->next = cur;
            // update
            p = p->next;
            pre = cur;
        }
        // 最后有进位
        if(carr == 1){
            auto cur = new ListNode(carr);
            pre->next = cur;
        }
        return dumb->next;
    }