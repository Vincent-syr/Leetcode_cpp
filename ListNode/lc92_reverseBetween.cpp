#include <iostream>
#include <vector>
#include "ListNode.h"
using namespace std;
/*
 * @Author: Vincent-syr
 * @Date: 2020-12-06 21:31:01
 * @LastEditTime: 2020-12-09 23:14:03
 * @Description: file content

https://leetcode-cn.com/problems/reverse-linked-list-ii/
92. 反转链表 II  middle
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
1 ≤ m ≤ n ≤ 链表长度。

示例:

输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL

解法1 递归：   总耗时约30 mins
    1）递归
        本题采用labuladong的递归式解法https://github.com/labuladong/fucking-algorithm/blob/master/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E7%B3%BB%E5%88%97/%E9%80%92%E5%BD%92%E5%8F%8D%E8%BD%AC%E9%93%BE%E8%A1%A8%E7%9A%84%E4%B8%80%E9%83%A8%E5%88%86.md
        先设计reverseN，将链表的前 n 个节点反转（n <= 链表长度）,麻烦点在于需要全局变量successor；
        然后使用reverseBetween调用reverseN；
        复杂度：
            时间O(N)    
            空间O(N)    栈很深

    2） 双指针法循环
        类似lc206，翻转整个指针的双指针法，因时间关系没有写上去；
        复杂度：时间O(N), 空间O(1)

解法2：双指针
    借鉴了lc25_reverseKGroup, 使用reverseK(head, k)函数，反转部分链表；
 */


    // ListNode* successor;
    // ListNode* reverseN(ListNode* head, int n) {   
    //     /**
    //      * @description: // 将链表的前 n 个节点反转（n <= 链表长度）
    //      * @param {*}
    //      * @return {*}
    //      */
    //     auto cur = head;
    //     if(n==1){
    //         successor = cur->next;
    //         return cur;
    //     }
    //     auto p = reverseN(cur->next, n - 1);
    //     cur->next->next = cur;
    //     cur->next = successor;
    //     return p;
    // }

    // ListNode* reverseBetween(ListNode* head, int m, int n) {
    //     if(m == 1)  return reverseN(head, n);
        
    //     head->next = reverseBetween(head->next, m-1, n-1);
    //     return head;
    // }

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



    ListNode* reverseBetween(ListNode* head, int m, int n){
    /**
     * @description: 可以借用lc25中的函数，reverseK
     * @param {*}
     * @return {*}
     */    
        int cnt = 1, k = n - m + 1;
        ListNode* dumb = new ListNode(0);
        dumb->next = head;
        auto prev = dumb;
        auto cur = head;
        while(cnt < m){
            cur = cur->next;
            prev = prev->next;
            cnt++;
        }
        prev->next = reverseK(cur, k);
        return dumb->next;
    }

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,3,4,5};
    // int k = 6;
    ListNode* head = createList(nums);
    outputList(head);
    outputList(reverseBetween(head, 2,4));
    return 0;
}

