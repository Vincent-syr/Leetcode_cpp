
#include <iostream>
#include <queue>
#include "ListNode.h"
using namespace std;


/*
 * @Author: Vincent-syr
 * @Date: 2020-12-09 21:47:22
 * @LastEditTime: 2020-12-09 22:57:26
 * @Description: file content
https://leetcode-cn.com/problems/reverse-nodes-in-k-group/
25. K 个一组翻转链表    hard
给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

 

示例：

给你这个链表：1->2->3->4->5

当 k = 2 时，应当返回: 2->1->4->3->5

当 k = 3 时，应当返回: 3->2->1->4->5

 

说明：

你的算法只能使用常数的额外空间。
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。




边际情况：
    k==1 不翻转
    head == nullptr或head只有1个元素；
    当k> 链表长度时，不翻转；
    
解法：
    按照按照group外有prev，每次调用reverseK(head, k)，对下一个group进行翻转，
    prev->next = reverseK(head, k), 即原来dumb->1->2->3->->4->5, k=2，第一次之后为
    dumb->2-1-3-4-5;一次遍历；
    


debug点：
    当剩余节点<k时，保持原有顺序；
    外层loop循环条件为        while(cur && cur->next),否则head=head->next容易出问题；

 */

    ListNode* reverseK(ListNode* head, int k){
        /**
         * @description: 反转链表的前k个节点，返回翻转后的最后一个
         * 如head=1->2->3->4, k=2, 则返回2->1->3->4;
         * @param {*}
         * @return {*}
         */
        auto cur = head;
        // 当剩余节点<k时，保持原有顺序；
        for(int i=0; i<k; i++){
            if(cur == nullptr)    return head;
            cur = cur->next;
        }
        int cnt = 0;
        ListNode *prev = nullptr;
        cur = head;
        while(cur && cnt < k){
            auto tmp = cur->next;
            cur->next = prev;
            // update
            prev = cur;
            cur = tmp;
            cnt++;
        }
        // 连上1->3
        head->next = cur;
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || k == 1)   return head;
        ListNode* dumb = new ListNode(0);
        auto cur = dumb;
        cur->next = head;
        // auto newHead = dumb;
        // bool firstGroup = false;
        while(cur && cur->next){
            cur->next = reverseK(head, k);
            head = head->next;
            int cnt = 0;
            while(cur && cnt<k){
                cur = cur->next;
                cnt++;
            }

        }
        return dumb->next;
    }


    int main(int argc, char const *argv[])
    {
        vector<int> nums = {1,2,3,4,5};
        int k = 6;
        ListNode* head = createList(nums);
        outputList(head);
        outputList(reverseKGroup(head, k));
        return 0;
    }
    