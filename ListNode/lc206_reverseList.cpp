#include <iostream>
#include <vector>
#include "ListNode.h"
using namespace std;


/*
 * @Author: Vincent-syr
 * @Date: 2020-12-06 20:08:22
 * @LastEditTime: 2020-12-06 21:07:04
 * @Description: file content
https://leetcode-cn.com/problems/reverse-linked-list/
206. 反转链表   easy
反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

解法：  总耗时：60mins
    方法1：reverseList，双指着法；
        时间O(N)，空间O(1)；
    方法2：递归reverseListRec，较麻烦，需要定义全局变量pre和tail，而且需要考虑nullptr请情况；
        时间O(N)，空间O(N)
    方法3：也是递归reverseListRec2，更好，不需要全局变量；

边界情况：
    head = nullptr;
    head只有一个元素；

debug点：
    reverseListRec(): 需要避免循环指针，即每次递归后让当前pre指向null，否则输出无穷；
        pre->next = nullptr;   // 避免循环指针；

 */


    ListNode* reverseList(ListNode* head) {
        /**
         * @description:  双指针循环法，空间O(1)
         * @param {*}
         * @return {*}
         */
        ListNode* cur = nullptr;
        ListNode* pre = head;

        while(pre){
            auto tmp = pre->next;
            pre->next = cur;
            cur = pre;
            pre = tmp;
        }
        return cur;
        
    }

    ListNode* tail = new ListNode(0);  // dump node
    ListNode* pre = tail;

    ListNode* reverseListRec(ListNode* head) {

        if(head == nullptr)  return head;
        auto cur = head;
        if(cur->next)   reverseListRec(cur->next);
        pre->next = cur;
        pre = cur;
        pre->next = nullptr;   // 避免循环指针；
        return tail->next;
    }


    // 不需要全局变量；不妨假设链表为1，2，3，4，5。
    // 按照递归，当执行reverseList（5）的时候返回了5这个节点，reverseList(4)中的p就是5这个节点，
    // 我们看看reverseList（4）接下来执行完之后，5->next = 4, 4->next = null。
    ListNode* reverseListRec2(ListNode* head) {
        if(head == nullptr || head->next==nullptr)  return head;
        auto p = reverseListRec2(head->next);
        head->next->next = head;
        head->next = nullptr;
        return p;
    }

    int main(int argc, char const *argv[])
    {
        vector<int> nums = {1,2,3,4,5};
        ListNode* head = createList(nums);

        auto res = reverseListRec(head);

        outputList(res);


        return 0;
    }
    

